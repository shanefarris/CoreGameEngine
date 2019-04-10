#include "SoundEngineException.h"
#include "COggSound.h"
#include "SoundEngineMemberFunctionPointer.h"

/*
** These next four methods are custom accessor functions to allow the Ogg Vorbis
** libraries to be able to stream audio data directly from an Ogre::DataStreamPtr
*/
size_t OgreALOggStreamRead(void *ptr, size_t size, size_t nmemb, void *datasource)
{
	Ogre::DataStreamPtr dataStream = *reinterpret_cast<Ogre::DataStreamPtr*>(datasource);
	return dataStream->read(ptr, size);
}

int OgreALOggStreamSeek(void *datasource, ogg_int64_t offset, int whence)
{
	Ogre::DataStreamPtr dataStream = *reinterpret_cast<Ogre::DataStreamPtr*>(datasource);
	switch(whence)
	{
	case SEEK_SET:
		dataStream->seek((long)offset);
		break;
	case SEEK_END:
		dataStream->seek(dataStream->size());
		// Falling through purposefully here
	case SEEK_CUR:
		dataStream->skip((long)offset);
		break;
	}

	return 0;
}

int OgreALOggStreamClose(void *datasource)
{
	return 0;
}

long OgreALOggStreamTell(void *datasource)
{
	Ogre::DataStreamPtr dataStream = *reinterpret_cast<Ogre::DataStreamPtr*>(datasource);
	return static_cast<long>(dataStream->tell());
}

/*
** End Custome Accessors
*/
namespace Sound 
{
COggSound::COggSound(const String& name, const Ogre::DataStreamPtr& soundStream, bool loop, bool stream) :
	CSound(name, soundStream->getName(), stream)
{
	try
	{
		m_SoundStream = soundStream;

		// Set up custom accessors
		ov_callbacks callbacks;
		callbacks.close_func = OgreALOggStreamClose;
		callbacks.tell_func = OgreALOggStreamTell;
		callbacks.read_func = OgreALOggStreamRead;
		callbacks.seek_func = OgreALOggStreamSeek;

		// Open the Ogre::DataStreamPtr
		CheckCondition(ov_open_callbacks(&m_SoundStream, &mOggStream, nullptr, 0, callbacks) >= 0, 1, "Could not open Ogg stream.");

		m_VorbisInfo = ov_info(&mOggStream, -1);
		unsigned long channels = m_VorbisInfo->channels;
		m_Freq = m_VorbisInfo->rate;
		m_Channels = m_VorbisInfo->channels;
		m_BPS = 16;
		m_Loop = loop;

		CalculateFormatInfo();

		m_LengthInSeconds = (f32)ov_time_total(&mOggStream, -1);

		GenerateBuffers();
		m_BuffersLoaded = LoadBuffers();
	}
	catch(Ogre::Exception e)
	{
		for(int i = 0; i < m_NumBuffers; i++)
		{
			if (m_Buffers[i] && alIsBuffer(m_Buffers[i]) == AL_TRUE)
			{
				alDeleteBuffers(1, &m_Buffers[i]);
				CheckError(alGetError(), "Failed to delete Buffer");
			}
		}

		ov_clear(&mOggStream);

		throw (e);
	}
}

COggSound::~COggSound()
{
	ov_clear(&mOggStream);
}

bool COggSound::LoadBuffers()
{
	for(int i = 0; i < m_NumBuffers; i++)
	{
		CheckCondition(AL_NONE != m_Buffers[i], 13, "Could not generate buffer");
		Buffer buffer = BufferData(&mOggStream, m_Stream ? m_BufferSize : 0);
		alBufferData(m_Buffers[i], m_Format, &buffer[0], static_cast<Size>(buffer.size()), m_Freq);
		CheckError(alGetError(), "Could not load buffer data");
	}

	return true;
}

bool COggSound::UnloadBuffers()
{
	if(m_Stream)
	{
		ov_time_seek(&mOggStream, 0);
		return false;
	}
	else
	{
		return true;
	}
}

void COggSound::SetSecondOffset(f32 seconds)
{
	if(seconds < 0) return;

	if(!m_Stream)
	{
		CSound::SetSecondOffset(seconds);
	}
	else
	{
		bool wasPlaying = IsPlaying();
		
		Pause();
		ov_time_seek(&mOggStream, seconds);

		if(wasPlaying) Play();
	}
}

f32 COggSound::GetSecondOffset()
{
	if(!m_Stream)
	{
		return CSound::GetSecondOffset();
	}
	else
	{
		/*
		** We know that we are playing a buffer and that we have another buffer loaded.
		** We also know that each buffer is 1/4 of a second when full.
		** We can Get the current offset in the OggStream which will be after both bufers
		** and subtract from that 1/4 of a second for the waiting buffer and 1/4 of a second
		** minus the offset into the current buffer to Get the current overall offset.
		*/

		auto oggStreamOffset = ov_time_tell(&mOggStream);
		auto bufferOffset = CSound::GetSecondOffset();

		auto totalOffset = oggStreamOffset - (0.25f + (0.25f - bufferOffset));
		return (f32)totalOffset;
	}
}

bool COggSound::UpdateSound()
{
	// Call the parent method to update the position
	CSound::UpdateSound();

	bool eof = false;

	if(m_Stream && (m_Source != AL_NONE) && IsPlaying())
	{
		// Update the stream
		int processed;

		alGetSourcei(m_Source, AL_BUFFERS_PROCESSED, &processed);
		CheckError(alGetError(), "Failed to Get source");
	 
		while(processed--)
		{
			ALuint buffer;
	        
			alSourceUnqueueBuffers(m_Source, 1, &buffer);
			CheckError(alGetError(), "Failed to unqueue buffers");
	 
			Buffer data = BufferData(&mOggStream, m_BufferSize);
			alBufferData(buffer, m_Format, &data[0], static_cast<Size>(data.size()), m_Freq);

			eof = (mOggStream.offset == mOggStream.end);
	 
			alSourceQueueBuffers(m_Source, 1, &buffer);
			CheckError(alGetError(), "Failed to queue buffers");

			if(eof)
			{
				if(m_Loop)
				{
					eof = false;
					ov_time_seek(&mOggStream, 0);
					if(m_LoopedCallback)
						m_LoopedCallback->execute(static_cast<CSound*>(this));
				}
				else
				{
					// Doing it this way may cut off the last 0.5s of the audio
					Stop();
					if(m_FinishedCallback)
						m_FinishedCallback->execute(static_cast<CSound*>(this));
				}
			}
		}
	}
 
	return !eof;
}

Buffer COggSound::BufferData(OggVorbis_File *oggVorbisFile, u32 size)
{
	Buffer buffer;
	char *data = new char[m_BufferSize];
	int section, sizeRead = 0;

	if(size == 0)
	{
		// Read the rest of the file
		do
		{
			sizeRead = ov_read(&mOggStream, data, m_BufferSize, 0, 2, 1, &section);
			buffer.insert(buffer.end(), data, data + sizeRead);
		}while(sizeRead > 0);
	}
	else
	{
		// Read only what was asked for
		while(buffer.size() < size)
		{
			sizeRead = ov_read(&mOggStream, data, m_BufferSize, 0, 2, 1, &section);
			if(sizeRead == 0) break;
			buffer.insert(buffer.end(), data, data + sizeRead);
		}
	}
	
	delete[] data;
	return buffer;

	//int section;
	//int sizeRead = 0;
	//totalSize  = 0;
	//char* data = new char[m_BufferSize];
	//if((m_Stream ? m_BufferSize : 0) == 0)
	//{
	//	// Read the rest of the file
	//	do
	//	{
	//		sizeRead = ov_read(&mOggStream, data, m_BufferSize, 0, 2, 1, &section);
	//		totalSize += sizeRead;
	//	}while(sizeRead > 0);
	//}
	//else
	//{
	//	// Read only what was asked for
	//	while(totalSize < size)
	//	{
	//		sizeRead = ov_read(&mOggStream, data + sizeRead, m_BufferSize, 0, 2, 1, &section);
	//		if(sizeRead == 0) break;
	//	}
	//}
	//return data;
}

} // Namespace
