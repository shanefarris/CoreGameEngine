#include "SoundEngineException.h"
#include "CSound.h"
#include "CSoundManager.h"
#include "CSoundFactory.h"
#include "SoundEngineMemberFunctionPointer.h"
#include "IO/CoreLogging.h"

#include "OgreNode.h"

namespace Sound {
	CSound::CSound(const String &name, const String& fileName, bool stream) :
		m_Source(0),
        m_Format(0),
		m_Freq(0),
		m_Size(0),
		m_BPS(0),
		m_Channels(0),
		m_LengthInSeconds(0),
		m_ManualRestart(false),
		m_ManualStop(false),
		m_PreviousOffset(0),
		m_Buffers(0),
		m_BufferSize(0),
		m_BuffersLoaded(false),
		m_BuffersQueued(false),
		m_NumBuffers(stream?2:1),
		m_Priority(NORMAL),
		m_FinishedCallback(0),
		m_LoopedCallback(0),
		m_StartTime(0),
		m_Stream(stream),
		MovableObject(name),
		m_Pitch(1.0), m_Gain(1.0),
		m_MaxGain(1.0),
		m_MinGain(0.0),
		m_FadeMode(FADE_NONE),
		m_FadeTime(0.0),
		m_MaxDistance(3400.0),
		m_RolloffFactor(1.0),
		m_ReferenceDistance(150.0),
		m_OuterConeGain(0.0),
		m_InnerConeAngle(360.0),
		m_OuterConeAngle(360.0),
		m_Position(Vector3::ZERO),
		m_Velocity(Vector3::ZERO),
		m_Direction(Vector3::NEGATIVE_UNIT_Z),
		m_FileName(fileName),
		m_SourceRelative(AL_FALSE),
		m_DerivedPosition(Vector3::ZERO),
		m_DerivedDirection(Vector3::NEGATIVE_UNIT_Z),
		m_IsPlayOnceEvent(false)
	{
		mParentNode = nullptr;
		
		// Events
		SoundEvent_OnPlay = nullptr;
		SoundEvent_OnPlayOnce = nullptr;
		SoundEvent_OnPause = nullptr;
		SoundEvent_OnStop = nullptr;
	}


	CSound::CSound(BufferRef buffer, const String& name, const String& fileName, bool loop) :
		m_Source(0),
		m_Format(0),
		m_Freq(0),
		m_Size(0),
		m_BPS(0),
		m_Channels(0),
		m_LengthInSeconds(0),
		m_ManualRestart(false),
		m_ManualStop(false),
		m_PreviousOffset(0),
		m_BufferSize(0),
		m_BuffersLoaded(true),
		m_BuffersQueued(false),
		m_NumBuffers(1),
		m_Priority(NORMAL),
		m_FinishedCallback(0),
		m_LoopedCallback(0),
		m_StartTime(0),
		m_Stream(false),
		MovableObject(name),
		m_Loop(loop?AL_TRUE:AL_FALSE),
		m_Pitch(1.0), m_Gain(1.0),
		m_MaxGain(1.0), m_MinGain(0.0),
		m_FadeMode(FADE_NONE),
		m_FadeTime(0.0),
		m_MaxDistance(3400.0),
		m_RolloffFactor(1.0),
		m_ReferenceDistance(150.0),
		m_OuterConeGain(0.0),
		m_InnerConeAngle(360.0),
		m_OuterConeAngle(360.0),
		m_Position(Vector3::ZERO),
		m_Velocity(Vector3::ZERO),
		m_Direction(Vector3::NEGATIVE_UNIT_Z),
		m_FileName(fileName),
		m_SourceRelative(AL_FALSE),
		m_DerivedPosition(Vector3::ZERO),
		m_DerivedDirection(Vector3::NEGATIVE_UNIT_Z),
		m_IsPlayOnceEvent(false)
	{
		mParentNode = nullptr;

		// Events
		SoundEvent_OnPlay = nullptr;
		SoundEvent_OnPlayOnce = nullptr;
		SoundEvent_OnPause = nullptr;
		SoundEvent_OnStop = nullptr;

		m_Buffers = new BufferRef[1];
		m_Buffers[0] = buffer;

		alGetBufferi(m_Buffers[0], AL_FREQUENCY, &m_Freq);
		alGetBufferi(m_Buffers[0], AL_BITS, &m_BPS);
		alGetBufferi(m_Buffers[0], AL_CHANNELS, &m_Channels);
		alGetBufferi(m_Buffers[0], AL_SIZE, &m_Size);

		CalculateFormatInfo();

		// m_BufferSize is equal to 1/4 of a second of audio
		m_LengthInSeconds = (f32)m_Size / (f32)(m_BufferSize * 4.0f);
	}

	CSound::~CSound()
	{
		Stop();

		try
		{
		  // If we have buffers to deallocate, do so.
		  if(m_Buffers != nullptr) {
		    alDeleteBuffers(m_NumBuffers, m_Buffers);
		    CheckError(alGetError(), "Failed to delete Buffers, must still be in use.");
		    CSoundManager::Instance()->_RemoveBufferRef(m_FileName);
		  }
		}
		catch(...)
		{
			// Don't die because of this.
		}

		if(m_Source != AL_NONE)
		{
			alSourcei(m_Source, AL_BUFFER, 0);
			CheckError(alGetError(), "Failed to release buffer");
		}

		delete[] m_Buffers;

		CSoundManager::Instance()->_ReleaseSource(this);
	}

	bool CSound::Play()
	{
		if(IsPlaying()) 
			return true;

		if(!IsPaused())
		{
			m_ManualRestart = false;
			m_ManualStop = false;		
			m_PreviousOffset = 0;
		}

		if(m_StartTime == 0)
		{
			// First started
			time(&m_StartTime);

			if(!m_IsPlayOnceEvent && SoundEvent_OnPlayOnce)
				SoundEvent_OnPlayOnce(this);

			// Play every time
			if(SoundEvent_OnPlay)
				SoundEvent_OnPlay(this);
		}
		else if(!IsPaused())
		{
			time_t currentTime;
			time(&currentTime);

			SetSecondOffset((f32)(currentTime - m_StartTime));
		}

		if(m_Source != AL_NONE || (m_Source = CSoundManager::Instance()->_RequestSource(this)) != AL_NONE)
		{
			if(!m_BuffersLoaded)
			{
				m_BuffersLoaded = LoadBuffers();
			}

			if(!m_BuffersQueued)
			{
				// Unqueue any buffers that may be left over
				unqueueBuffers();
				QueueBuffers();
			}

			InitSource();

			alSourcePlay(m_Source);
			CheckError(alGetError(), "Failed to play sound");
		}

		return false;
	}

	bool CSound::IsPlaying() const
	{
		if(m_Source == AL_NONE)
		{
			return false;
		}

		State state;
		alGetSourcei(m_Source, AL_SOURCE_STATE, &state);
		CheckError(alGetError(), "Failed to Get State");

		return (state == AL_PLAYING);
	}

	bool CSound::Pause()
	{
		// Pause Event
		if(SoundEvent_OnPause)
			SoundEvent_OnPause(this);

		if(!IsPlaying()) 
			return true;

		if(m_Source != AL_NONE)
		{
			alSourcePause(m_Source);
			CheckError(alGetError(), "Failed to Pause sound");
		}

		return false;
	}

	bool CSound::IsPaused() const
	{
		if(m_Source == AL_NONE)
		{
			return false;
		}

		State state;    
		alGetSourcei(m_Source, AL_SOURCE_STATE, &state);
		CheckError(alGetError(), "Failed to Get State");

		return (state == AL_PAUSED);
	}

	bool CSound::Stop()
	{
		// Stop Event
		if(SoundEvent_OnStop)
			SoundEvent_OnStop(this);

		if(IsStopped())
		{
			if(m_Source != AL_NONE)
			{
				m_Source = CSoundManager::Instance()->_ReleaseSource(this);
				return true;
			}
		}
		else if(m_Source != AL_NONE)
		{
			m_ManualStop = true;

			// Stop the source
			alSourceStop(m_Source);
			CheckError(alGetError(), "Failed to stop sound");

			unqueueBuffers();

			m_BuffersLoaded = UnloadBuffers();
		}

		m_Source = CSoundManager::Instance()->_ReleaseSource(this);

		m_StartTime = 0;

		return true;
	}

	bool CSound::IsStopped() const
	{
		if(m_Source == AL_NONE)
		{
			return true;
		}

		State state;    
		alGetSourcei(m_Source, AL_SOURCE_STATE, &state);
		CheckError(alGetError(), "Failed to Get State");

		return (state == AL_STOPPED);
	}

	bool CSound::IsInitial() const
	{
		if(m_Source == AL_NONE)
		{
			return true;
		}

		State state;    
		alGetSourcei(m_Source, AL_SOURCE_STATE, &state);
		CheckError(alGetError(), "Failed to Get State");

		return (state == AL_INITIAL);
	}

  bool CSound::FadeIn(f32 fadeTime) {
    // If we're playing, then we're going to fade-in from the current gain
    // value. This means that in order to perform the fade-in, we must also
    // not already be at the maximum gain. Also, this only makes sense while
    // we're fading out or not fading at all. I have not thought of a 
    // semantic where calling a fade-in while fading in is worthwhile.
    if(IsPlaying() &&
       m_Gain != m_MaxGain &&
       (m_FadeMode == FADE_NONE || m_FadeMode == FADE_OUT)) {
      // Swap fade direction.
      m_FadeMode = FADE_IN;
      
      // What we're going to do is use the existing updateFading code by
      // modifying the fadeTime and running times so that, when the caller
      // has asked for a fade-in from the current gain to the max gain over
      // fadeTime, we create such a fadeTime and running time as to already
      // have arrived at these values.
      //
      // A                   B          C
      // |===================|----------|
      //
      // Consider A as our min-gain, B as our current gain and C as our
      // max-gain. If we are to fade in from B to C over fadeTime, then
      // this is essentially the same as fadeTime being scaled by the
      // ratio of AC/BC and running time being placed at B.
      m_FadeTime = ((m_MaxGain - m_MinGain) / (m_MaxGain - m_Gain)) * fadeTime;
      m_Running = ((m_Gain - m_MinGain) / (m_MaxGain - m_MinGain)) * m_FadeTime;
	
      return true;

    }else{
      // Not playing. Can safely assume the caller wants the sound faded in 
      // from minimum gain, rather than bursting it in and going from the
      // currently applied gain; this was the default behaviour.
      m_FadeMode = FADE_IN;
      m_FadeTime = fadeTime;
      m_Running = 0.0;
      // Start at min gain..
      SetGain(m_MinGain);
      // ..and play
      return Play();
    }

    
    // A fade-in has been requested either:
    //
    //  * When a fade-in is already in progress.
    //  * When a sound is playing but is already at max-gain.
    //  * When a fade-out is in progress but we're at max-gain.
    //
    return false;
  }

  bool CSound::FadeOut(f32 fadeTime) {
    // The constructs in this fade-out code are extremely similar to that of
    // the fade-in code. For details about operation, consult the respective
    // function. The difference with fade outs is it only makes sense to do
    // one iff:
    //
    //  * We're playing the sound.
    //  * We're not at min-gain already.
    //  * A fade-out is not already in progress.
    //
    if(IsPlaying() &&
       m_Gain != m_MinGain &&
       (m_FadeMode == FADE_NONE || m_FadeMode == FADE_IN)) {
      // Swap fade direction.
      m_FadeMode = FADE_OUT;
      
      // Construct fadeTime and running times so that they interpolate nicely
      // across the supplied time interval. This time we go from B to A.
      m_FadeTime = ((m_MaxGain - m_MinGain) / (m_Gain - m_MinGain)) * fadeTime;
      m_Running = ((m_MaxGain - m_Gain) / (m_MaxGain - m_MinGain)) * m_FadeTime;
	
      return true;

    }

    // A fade-out was requested while:
    //
    //  * The sound is not playing.
    //  * The sound is already at the minimum gain.
    //  * A fade-out is already in progress.
    return false;
  }

	void CSound::SetPitch(f32 pitch)
	{
		if(pitch <= 0) return;

		m_Pitch = pitch;

		if(m_Source != AL_NONE)
		{
			alSourcef(m_Source, AL_PITCH, m_Pitch);
			CheckError(alGetError(), "Failed to Set Pitch");
		}
	}

	void CSound::SetGain(f32 gain)
	{
		if(gain < 0) return;

		m_Gain = gain;

		if(m_Source != AL_NONE)
		{
			alSourcef(m_Source, AL_GAIN, m_Gain);
			CheckError(alGetError(), "Failed to Set Gain");
		}
	}

	void CSound::SetMaxGain(f32 maxGain)
	{
		if(maxGain < 0 || maxGain > 1) return;
		
		m_MaxGain = maxGain;
		
		if(m_Source != AL_NONE)
		{
			alSourcef(m_Source, AL_MAX_GAIN, m_MaxGain);
			CheckError(alGetError(), "Failed to Set Max Gain");
		}
	}

	void CSound::SetMinGain(f32 minGain)
	{
		if(minGain < 0 || minGain > 1) return;

		m_MinGain = minGain;

		if(m_Source != AL_NONE)
		{
			alSourcef(m_Source, AL_MIN_GAIN, m_MinGain);
			CheckError(alGetError(), "Failed to Set Min Gain");
		}
	}

	void CSound::SetMaxDistance(f32 maxDistance)
	{
		if(maxDistance < 0) return;

		m_MaxDistance = maxDistance;

		if(m_Source != AL_NONE)
		{
			alSourcef(m_Source, AL_MAX_DISTANCE, m_MaxDistance);
			CheckError(alGetError(), "Failed to Set Max Distance");
		}
	}

	void CSound::SetRolloffFactor(f32 rolloffFactor)
	{
		if(rolloffFactor < 0) return;

		m_RolloffFactor = rolloffFactor;

		if(m_Source != AL_NONE)
		{
			alSourcef(m_Source, AL_ROLLOFF_FACTOR, m_RolloffFactor);
			CheckError(alGetError(), "Failed to Set Rolloff Factor");
		}
	}

	void CSound::SetReferenceDistance(f32 refDistance)
	{
		if(refDistance < 0) return;

		m_ReferenceDistance = refDistance;

		if(m_Source != AL_NONE)
		{
			alSourcef(m_Source, AL_REFERENCE_DISTANCE, m_ReferenceDistance);
			CheckError(alGetError(), "Failed to Set Reference Distance");
		}
	}

	void CSound::SetDistanceValues(f32 maxDistance, f32 rolloffFactor, f32 refDistance)
	{
		SetMaxDistance(maxDistance);
		SetRolloffFactor(rolloffFactor);
		SetReferenceDistance(refDistance);
	}

	void CSound::SetVelocity(f32 x, f32 y, f32 z)
	{
		m_Velocity.x = x;
		m_Velocity.y = y;
		m_Velocity.z = z;

		if(m_Source != AL_NONE)
		{
			alSource3f(m_Source, AL_VELOCITY, m_Velocity.x, m_Velocity.y, m_Velocity.z);
			CheckError(alGetError(), "Failed to Set Velocity");
		}
	}

	void CSound::SetVelocity(const Vector3& vec)
	{
		SetVelocity(vec.x, vec.y, vec.z);
	}

	void CSound::SetRelativeToListener(bool relative)
	{
		// Do not Set to relative if it's connected to a node
		if(mParentNode) return;

		m_SourceRelative = relative;

		if(m_Source != AL_NONE)
		{
			alSourcei(m_Source, AL_SOURCE_RELATIVE, m_SourceRelative);
			CheckError(alGetError(), "Failed to Set Source Relative");
		}
	}

	void CSound::SetOuterConeGain(f32 outerConeGain)
	{
		if(outerConeGain < 0 || outerConeGain > 1) return;

		m_OuterConeGain = outerConeGain;

		if(m_Source != AL_NONE)
		{
			alSourcef(m_Source, AL_CONE_OUTER_GAIN, m_OuterConeGain);
			CheckError(alGetError(), "Failed to Set Outer Cone Gain");
		}
	}

	void CSound::SetInnerConeAngle(f32 innerConeAngle)
	{
		m_InnerConeAngle = innerConeAngle;

		if(m_Source != AL_NONE)
		{
			alSourcef(m_Source, AL_CONE_INNER_ANGLE, m_InnerConeAngle);
			CheckError(alGetError(), "Failed to Set Inner Cone Angle");
		}
	}

	void CSound::SetOuterConeAngle(f32 outerConeAngle)
	{
		m_OuterConeAngle = outerConeAngle;

		if(m_Source != AL_NONE)
		{
			alSourcef(m_Source, AL_CONE_OUTER_ANGLE, m_OuterConeAngle);
			CheckError(alGetError(), "Failed to Set Outer Cone Angle");
		}
	}

	void CSound::SetLoop(bool loop)
	{
		m_Loop = loop?AL_TRUE:AL_FALSE;

		if(m_Source != AL_NONE && !m_Stream)
		{
			alSourcei(m_Source, AL_LOOPING, m_Loop);
			CheckError(alGetError(), "Failed to Set Looping");
		}
	}

	void CSound::SetSecondOffset(f32 seconds)
	{
		if(seconds < 0) return;

		if(m_Source != AL_NONE)
		{
			alSourcef(m_Source, AL_SEC_OFFSET, seconds);
			CheckError(alGetError(), "Failed to Set offset");
		}
	}

	f32 CSound::GetSecondOffset()
	{
		f32 offset = 0;

		if(m_Source != AL_NONE)
		{
			alGetSourcef(m_Source, AL_SEC_OFFSET, &offset);
			CheckError(alGetError(), "Failed to Set Looping");
		}

		return offset;
	}

	void CSound::SetPosition(f32 x, f32 y, f32 z)
	{
		m_Position.x = x;
		m_Position.y = y;
		m_Position.z = z;
		m_LocalTransformDirty = true;
	}

	void CSound::SetPosition(const Vector3& vec)
	{
		m_Position = vec;
		m_LocalTransformDirty = true;
	}

	void CSound::SetDirection(f32 x, f32 y, f32 z)
	{
		m_Direction.x = x;
		m_Direction.y = y;
		m_Direction.z = z;
		m_LocalTransformDirty = true;
	}

	void CSound::SetDirection(const Vector3& vec)
	{
		m_Direction = vec;
		m_LocalTransformDirty = true;
	}

	void CSound::_Update() const
	{
		if (mParentNode)
		{
		    if (!(mParentNode->_getDerivedOrientation() == m_LastParentOrientation && mParentNode->_getDerivedPosition() == m_LastParentPosition) || 
				m_LocalTransformDirty)
		    {
				// Ok, we're out of date with SceneNode we're attached to
				m_LastParentOrientation = mParentNode->_getDerivedOrientation();
				m_LastParentPosition = mParentNode->_getDerivedPosition();
				m_DerivedDirection = m_LastParentOrientation * m_Direction;
				m_DerivedPosition = (m_LastParentOrientation * m_Position) + m_LastParentPosition;
		    }
		}
		else
		{
		    m_DerivedPosition = m_Position;
		    m_DerivedDirection = m_Direction;
		}

		m_LocalTransformDirty = false;
	}

	void CSound::_UpdateFading()
	{
		if(m_FadeMode != FADE_NONE)
		{   
			m_Running += CSoundManager::Instance()->_GetLastDeltaTime();
			// Calculate volume between min and max Gain over fade time
			f32 delta = m_MaxGain - m_MinGain;
			f32 gain;

			if(m_FadeMode == FADE_IN)
			{
				gain = m_MinGain + (delta * m_Running / m_FadeTime);
				// Clamp & stop if needed
				if (gain > m_MaxGain)
				{
					gain = m_MaxGain;
					m_FadeMode = FADE_NONE;
				}
			}
			else if(m_FadeMode == FADE_OUT)
			{
				gain = m_MaxGain - (delta * m_Running / m_FadeTime);
				// Clamp & stop if needed
				if(gain < m_MinGain)
				{
					gain = m_MinGain;
					m_FadeMode = FADE_NONE;
				}
			}

			// Set the adjusted gain
			SetGain(gain);
		}
	}

	bool CSound::UpdateSound()
	{
		_Update();

		if(m_Source != AL_NONE)
		{
			if(IsStopped() && !m_ManualStop && m_FinishedCallback)
			{
				m_FinishedCallback->execute(this);
			}

			f32 currOffset = GetSecondOffset();
			if(currOffset < m_PreviousOffset && !m_ManualRestart && m_LoopedCallback)
			{
				m_LoopedCallback->execute(this);
			}
			m_PreviousOffset = currOffset;

			alSource3f(m_Source, AL_POSITION, m_DerivedPosition.x, m_DerivedPosition.y, m_DerivedPosition.z);
			CheckError(alGetError(), "Failed to Set Position");

			alSource3f(m_Source, AL_DIRECTION, m_DerivedDirection.x, m_DerivedDirection.y, m_DerivedDirection.z);
			CheckError(alGetError(), "Failed to Set Direction");

			// Fading
			_UpdateFading();
		}

		return true;
	}

	void CSound::InitSource()
	{
		if(m_Source == AL_NONE)
		{
			return;
		}

		alSourcef (m_Source, AL_PITCH,				m_Pitch);
		alSourcef (m_Source, AL_GAIN,				m_Gain);
		alSourcef (m_Source, AL_MAX_GAIN,			m_MaxGain);
		alSourcef (m_Source, AL_MIN_GAIN,			m_MinGain);
		alSourcef (m_Source, AL_MAX_DISTANCE,		m_MaxDistance);
		alSourcef (m_Source, AL_ROLLOFF_FACTOR,		m_RolloffFactor);
		alSourcef (m_Source, AL_REFERENCE_DISTANCE,	m_ReferenceDistance);
		alSourcef (m_Source, AL_CONE_OUTER_GAIN,		m_OuterConeGain);
		alSourcef (m_Source, AL_CONE_INNER_ANGLE,	m_InnerConeAngle);
		alSourcef (m_Source, AL_CONE_OUTER_ANGLE,	m_OuterConeAngle);
		alSource3f(m_Source, AL_POSITION,			m_DerivedPosition.x, m_DerivedPosition.y, m_DerivedPosition.z);
		alSource3f(m_Source, AL_VELOCITY,			m_Velocity.x, m_Velocity.y, m_Velocity.z);
		alSource3f(m_Source, AL_DIRECTION,			m_DerivedDirection.x, m_DerivedDirection.y, m_DerivedDirection.z);
		alSourcei (m_Source, AL_SOURCE_RELATIVE,		m_SourceRelative);
		// There is an issue with looping and streaming, so we will
		// disable looping and deal with it on our own.
		alSourcei (m_Source, AL_LOOPING,				m_Stream ? AL_FALSE : m_Loop);
		CheckError(alGetError(), "Failed to initialize source");
	}

	void CSound::GenerateBuffers()
	{
		m_Buffers = new BufferRef[m_NumBuffers];
		alGenBuffers(m_NumBuffers, m_Buffers);
		CheckError(alGetError(), "Could not generate buffer");

		if(CSoundManager::Instance()->XRamSupport())
		{
			CSoundManager::Instance()->EaxSetBufferMode(m_NumBuffers, m_Buffers, CSoundManager::xRamHardware);
		}
	}

	void CSound::CalculateFormatInfo()
	{
		switch(m_Channels)
		{
		case 1:
			if(m_BPS == 8)
			{
				m_Format = AL_FORMAT_MONO8;
				// Set BufferSize to 250ms (Frequency divided by 4 (quarter of a second))
				m_BufferSize = m_Freq / 4;
			}
			else
			{
				m_Format = AL_FORMAT_MONO16;
				// Set BufferSize to 250ms (Frequency * 2 (16bit) divided by 4 (quarter of a second))
				m_BufferSize = m_Freq >> 1;
				// IMPORTANT : The Buffer Size must be an exact multiple of the BlockAlignment ...
				m_BufferSize -= (m_BufferSize % 2);
			}
			break;
		case 2:
			if(m_BPS == 8)
			{
				m_Format = AL_FORMAT_STEREO16;
				// Set BufferSize to 250ms (Frequency * 2 (8bit stereo) divided by 4 (quarter of a second))
				m_BufferSize = m_Freq >> 1;
				// IMPORTANT : The Buffer Size must be an exact multiple of the BlockAlignment ...
				m_BufferSize -= (m_BufferSize % 2);
			}
			else
			{
				m_Format = AL_FORMAT_STEREO16;
				// Set BufferSize to 250ms (Frequency * 4 (16bit stereo) divided by 4 (quarter of a second))
				m_BufferSize = m_Freq;
				// IMPORTANT : The Buffer Size must be an exact multiple of the BlockAlignment ...
				m_BufferSize -= (m_BufferSize % 4);
			}
			break;
		case 4:
			m_Format = alGetEnumValue("AL_FORMAT_QUAD16");
			// Set BufferSize to 250ms (Frequency * 8 (16bit 4-channel) divided by 4 (quarter of a second))
			m_BufferSize = m_Freq * 2;
			// IMPORTANT : The Buffer Size must be an exact multiple of the BlockAlignment ...
			m_BufferSize -= (m_BufferSize % 8);
			break;
		case 6:
			m_Format = alGetEnumValue("AL_FORMAT_51CHN16");
			// Set BufferSize to 250ms (Frequency * 12 (16bit 6-channel) divided by 4 (quarter of a second))
			m_BufferSize = m_Freq * 3;
			// IMPORTANT : The Buffer Size must be an exact multiple of the BlockAlignment ...
			m_BufferSize -= (m_BufferSize % 12);
			break;
		case 7:
			m_Format = alGetEnumValue("AL_FORMAT_61CHN16");
			// Set BufferSize to 250ms (Frequency * 16 (16bit 7-channel) divided by 4 (quarter of a second))
			m_BufferSize = m_Freq * 4;
			// IMPORTANT : The Buffer Size must be an exact multiple of the BlockAlignment ...
			m_BufferSize -= (m_BufferSize % 16);
			break;
		case 8:
			m_Format = alGetEnumValue("AL_FORMAT_71CHN16");
			// Set BufferSize to 250ms (Frequency * 20 (16bit 8-channel) divided by 4 (quarter of a second))
			m_BufferSize = m_Freq * 5;
			// IMPORTANT : The Buffer Size must be an exact multiple of the BlockAlignment ...
			m_BufferSize -= (m_BufferSize % 20);
			break;
		default:
			// Couldn't determine buffer format so log the error and default to mono
			CORE_LOG("!!WARNING!! Could not determine buffer format!  Defaulting to MONO");

			m_Format = AL_FORMAT_MONO16;
			// Set BufferSize to 250ms (Frequency * 2 (16bit) divided by 4 (quarter of a second))
			m_BufferSize = m_Freq >> 1;
			// IMPORTANT : The Buffer Size must be an exact multiple of the BlockAlignment ...
			m_BufferSize -= (m_BufferSize % 2);
			break;
		}
	}

	void CSound::QueueBuffers()
	{
		alSourceQueueBuffers(m_Source, m_NumBuffers, m_Buffers);
		CheckError(alGetError(), "Failed to bind Buffer");
	}

	void CSound::unqueueBuffers()
	{
		/*
		** If the sound doens't have a state yet it causes an
		** error when you try to unqueue the buffers! :S  In 
		** order to Get around this we stop the source even if
		** it wasn't playing.
		*/
		alSourceStop(m_Source);
		CheckError(alGetError(), "Failed to stop sound");

		int queued;
		alGetSourcei(m_Source, AL_BUFFERS_QUEUED, &queued);
		CheckError(alGetError(), "Failed to Get Source");

		alSourceUnqueueBuffers(m_Source, queued, m_Buffers);
		CheckError(alGetError(), "Failed to unqueue Buffers");

		
		m_BuffersQueued = false;
	}

	const String& CSound::getMovableType(void) const
	{
		return CSoundFactory::FACTORY_TYPE_NAME;
	}

	const Ogre::AxisAlignedBox& CSound::getBoundingBox(void) const
	{
		// Null, Sounds are not visible
		static Ogre::AxisAlignedBox box;
		return box;
	}

	void CSound::_updateRenderQueue(Ogre::RenderQueue* queue)
	{
		// Sounds are not visible so do nothing
	}

	void CSound::_notifyAttached(Ogre::Node *parent, bool isTagPoint)
	{
		// Set the source not relative to the listener if it's attached to a node
		if(m_SourceRelative)
		{
			m_SourceRelative = false;
			if(m_Source != AL_NONE)
			{
				alSourcei(m_Source, AL_SOURCE_RELATIVE, AL_FALSE);
				CheckCondition(alGetError() == AL_NO_ERROR, 13, "Inalid Value");
			}
		}
		mParentNode = parent;
		_Update();
	}

} // Namespace
