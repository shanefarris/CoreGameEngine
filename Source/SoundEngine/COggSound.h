#ifndef __OGG_SOUND_H__
#define __OGG_SOUND_H__

#include "ogg/ogg.h"
#include "vorbis/codec.h"
#include "vorbis/vorbisfile.h"
#include "SoundEnginePrereqs.h"
#include "CSound.h"

namespace Sound 
{
/**
 * COggSound.
 * @note
 * This object is only to be instantiated using the CSoundManager::CreateSound method.
 * @remark This is a sound that plays OggVorbis files
 *
 * @see CSound::CSound
 */
class COggSound : public CSound
{
protected:
	/*
	** Constructor is protected to enforce the use of the 
	** factory via CSoundManager::CreateSound
	*/
	/**
	 * Constructor.
	 * @param name The name used to reference this sound
	 * @param soundStream Ogre::DataStreamPtr for the sound resource
	 * @param loop Should the sound loop once it has played
	 * @param stream Should the sound be streamed or all loaded into memory at once
	 */
	COggSound(const String& name, const Ogre::DataStreamPtr& soundStream, bool loop, bool stream);

public:
	virtual ~COggSound();

	// Sets the offset within the audio stream in seconds 
	virtual void SetSecondOffset(f32 seconds);

	// Returns the current offset within the audio stream in seconds 
	virtual f32 GetSecondOffset();

protected:
	// This is called each frame to update the position, direction, etc
	virtual bool UpdateSound();

	// Loads the buffers to be played.  Returns whether the buffer is loaded.
	virtual bool LoadBuffers();

	// Unloads the buffers.  Returns true if the buffers are still loaded.
	virtual bool UnloadBuffers();

private:
	// Returns a buffer containing the next chunk of length size
	//char* BufferData(OggVorbis_File *oggVorbisFile, u32 size, int& totalSize);
	Buffer BufferData(OggVorbis_File *oggVorbisFile, u32 size);

	OggVorbis_File mOggStream;
	vorbis_info *m_VorbisInfo;

	friend class CSoundFactory;
};
} // Namespace

#endif
