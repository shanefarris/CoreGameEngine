#if 0
#include "SoundEngineException.h"
#include "CWavSound.h"

namespace Sound 
{
CWavSound::CWavSound(const String& name, const Ogre::DataStreamPtr& soundStream, bool loop, bool stream) :
	CSound(name, soundStream->getName(), stream)
{
	try
	{
		 m_SoundStream = soundStream;
		 m_Loop = loop?AL_TRUE:AL_FALSE;

		// buffers
		char magic[5];
		magic[4] = '\0';
		unsigned char buffer32[4];
		unsigned char buffer16[2];

		// check magic
		CheckCondition(m_SoundStream->read(magic, 4) == 4, 13, "Cannot read wav file " + m_FileName);
		CheckCondition(std::string(magic) == "RIFF", 13, "Wrong wav file format. (no RIFF magic): " + m_FileName);

		// The next 4 bytes are the file size, we can skip this since we Get the size from the DataStream
		m_SoundStream->skip(4);
		m_Size = static_cast<Size>(m_SoundStream->size());

		// check file format
		CheckCondition(m_SoundStream->read(magic, 4) == 4, 13, "Cannot read wav file " + m_FileName);
		CheckCondition(std::string(magic) == "WAVE", 13, "Wrong wav file format. (no WAVE format): " + m_FileName);

		// check 'fmt ' sub chunk (1)
		CheckCondition(m_SoundStream->read(magic, 4) == 4, 13, "Cannot read wav file " + m_FileName);
		CheckCondition(std::string(magic) == "fmt ", 13, "Wrong wav file format. (no 'fmt ' subchunk): " + m_FileName);

		// read (1)'s size
		CheckCondition(m_SoundStream->read(buffer32, 4) == 4, 13, "Cannot read wav file " + m_FileName);
		unsigned long subChunk1Size = readByte32(buffer32);
		CheckCondition(subChunk1Size >= 16, 13, "Wrong wav file format. ('fmt ' chunk too small, truncated file?): " + m_FileName);

		// check PCM audio format
		CheckCondition(m_SoundStream->read(buffer16, 2) == 2, 13, "Cannot read wav file " + m_FileName);
		unsigned short audioFormat = readByte16(buffer16);
		CheckCondition(audioFormat == 1, 13, "Wrong wav file format. This file is not a .wav file (audio format is not PCM): " + m_FileName);

		// read number of channels
		CheckCondition(m_SoundStream->read(buffer16, 2) == 2, 13, "Cannot read wav file " + m_FileName);
		m_Channels = readByte16(buffer16);

		// read frequency (sample rate)
		CheckCondition(m_SoundStream->read(buffer32, 4) == 4, 13, "Cannot read wav file " + m_FileName);
		m_Freq = readByte32(buffer32);

		// skip 6 bytes (Byte rate (4), Block align (2))
		m_SoundStream->skip(6);

		// read bits per sample
		CheckCondition(m_SoundStream->read(buffer16, 2) == 2, 13, "Cannot read wav file " + m_FileName);
		m_BPS = readByte16(buffer16);

		// check 'data' sub chunk (2)
		CheckCondition(m_SoundStream->read(magic, 4) == 4, 13, "Cannot read wav file " + m_FileName);
		CheckCondition(std::string(magic) == "data" || std::string(magic) == "fact", 13,
			 "Wrong wav file format. (no data subchunk): " + m_FileName);

		// fact is an option section we don't need to worry about
		if(std::string(magic) == "fact")
		{
			m_SoundStream->skip(8);

			// Now we shoudl hit the data chunk
			CheckCondition(m_SoundStream->read(magic, 4) == 4, 13, "Cannot read wav file " + m_FileName);
			CheckCondition(std::string(magic) == "data", 13, "Wrong wav file format. (no data subchunk): " + m_FileName);
		}

		// The next four bytes are the size remaing of the file
		CheckCondition(m_SoundStream->read(buffer32, 4) == 4, 13, "Cannot read wav file " + m_FileName);
		m_DataSize = readByte32(buffer32);
		m_DataStart = m_SoundStream->tell();

		CalculateFormatInfo();

		// m_BufferSize is equal to 1/4 of a second of audio
		m_LengthInSeconds = (float)m_DataSize / ((float)m_BufferSize * 4);

		GenerateBuffers();
		m_BuffersLoaded = LoadBuffers();
	}
	catch(Ogre::Exception e)
	  {
	    // If we have gone so far as to load the buffers, unload them.
	    if(m_Buffers != nullptr) {
	      for(int i = 0; i < m_NumBuffers; i++)
		{
		  if (m_Buffers[i] && alIsBuffer(m_Buffers[i]) == AL_TRUE)
		    {
		      alDeleteBuffers(1, &m_Buffers[i]);
		      CheckError(alGetError(), "Failed to delete Buffer");
		    }
		}
	    }

	    // Prevent the ~CSound() destructor from double-freeing.
	    m_Buffers = nullptr;
	    // Propagate.
	    throw (e);
	  }
}

CWavSound::~CWavSound()
{}

bool CWavSound::LoadBuffers()
{
	for(int i = 0; i < m_NumBuffers; i++)
	{
		CheckCondition(AL_NONE != m_Buffers[i], 13, "Could not generate buffer");
		Buffer buffer = BufferData(m_SoundStream, m_Stream?m_BufferSize:m_DataSize);
		alBufferData(m_Buffers[i], m_Format, &buffer[0], static_cast<Size>(buffer.size()), m_Freq);
		CheckError(alGetError(), "Could not load buffer data");
	}

	return true;
}

bool CWavSound::UnloadBuffers()
{
	if(m_Stream)
	{
		m_SoundStream->seek(m_DataStart);
		return false;
	}
	else
	{
		return true;
	}
}

void CWavSound::SetSecondOffset(f32 seconds)
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

		// m_BufferSize is 1/4 of a second
		size_t dataOffset = static_cast<size_t>(seconds * m_BufferSize * 4);
		m_SoundStream->seek(dataOffset + m_DataStart);

		if(wasPlaying) Play();
	}
}

f32 CWavSound::GetSecondOffset()
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

		// m_BufferSize is 1/4 of a second
		f32 wavStreamOffset = (float)(m_SoundStream->tell() - m_DataStart) / (float)(m_BufferSize * 4);
		f32 bufferOffset = CSound::GetSecondOffset();

		f32 totalOffset = wavStreamOffset + (0.25 - bufferOffset);
		return totalOffset;
	}
}

bool CWavSound::UpdateSound()
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
	 
			Buffer data = BufferData(m_SoundStream, m_BufferSize);
			alBufferData(buffer, m_Format, &data[0], static_cast<Size>(data.size()), m_Freq);

			eof = m_SoundStream->eof();
	 
			alSourceQueueBuffers(m_Source, 1, &buffer);
			CheckError(alGetError(), "Failed to queue buffers");

			if(eof)
			{
				if(m_Loop)
				{
					eof = false;
					m_SoundStream->seek(m_DataStart);
					if(m_LoopedCallback)
						m_LoopedCallback->execute(static_cast<CSound*>(this));
				}
				else
				{
					Stop();
					if(m_FinishedCallback)
						m_FinishedCallback->execute(static_cast<CSound*>(this));
				}
			}
		}
	}
 
	return !eof;
}

Buffer CWavSound::BufferData(Ogre::DataStreamPtr dataStream, u32 size)
{
	size_t bytes;
	std::vector<char> data;
	char *array = new char[m_BufferSize];

	while(data.size() != size)
	{
		// Read up to a buffer's worth of decoded sound data
		bytes = m_SoundStream->read(array, m_BufferSize);

		if (bytes <= 0)
			break;

		if (data.size() + bytes > size)
			bytes = size - data.size();

		// Append to end of buffer
		data.insert(data.end(), array, array + bytes);
	}

	delete []array;
	array = nullptr;

	return data;
}

} // Namespace

#endif