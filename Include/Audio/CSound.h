#ifndef __SOUND_H__
#define __SOUND_H__

#include "Defines.h"
#include "SoundEnginePrereqs.h"
#include "OgreMovableObject.h"

namespace Sound 
{
	class CMemberFunctionSlot;

	/**
	 * CSound.
	 * @remarks
	 * Sounds are created using the CSoundManager::CreateSound method
	 * and then can be attached to Ogre::SceneNodes, placed at a point
	 * in space or placed at an offset relative to the listener.
	 *
	 * @see Ogre::MovableObject
	 */
	class CORE_EXPORT CSound : public Ogre::MovableObject
	{
	public:
		virtual ~CSound();

		enum Priority
		{
			LOW,
			NORMAL,
			HIGH
		};

		// Plays the sound. 
		bool Play();

		// Sound Events
		void (*SoundEvent_OnPlay)(Sound::CSound* Sound);			// Every time it is played
		void (*SoundEvent_OnPlayOnce)(Sound::CSound* Sound);		// Only the first time it is played
		void (*SoundEvent_OnPause)(Sound::CSound* Sound);			// Put on pause
		void (*SoundEvent_OnStop)(Sound::CSound* Sound);			// When it is done

		// Returns true if the sound is playing, otherwise false. 
		virtual bool IsPlaying() const;

		// Pauses the sound. @note Upon calling play again, the sound will resume where it left off 
		virtual bool Pause();

		// Returns true if the sound is paused, otherwise false. 
		virtual bool IsPaused() const;

		// Stops the sound. @note Upon calling play again, the sound will resume from the begining 
		bool Stop();

		// Returns true if the sound is stopped, otherwise false.
		virtual bool IsStopped() const;

		// Returns true if the source does not have a state yet, otherwise false 
		virtual bool IsInitial() const;

		// Starts playing the song while fading in.
		bool FadeIn(f32 fadeTime);

		// Fades out, but keeps playing at volume 0, so it can be faded in again.
		bool FadeOut(f32 fadeTime);

		// Sets the pitch multiplier. Note pitch must always be positive non-zero, all other values will be ignored
		void SetPitch(f32 pitch);

		// Returns the pitch multiplier. 
		f32 GetPitch() const { return m_Pitch; }

		/** 
		 * Sets the gain. 
		 * @param gain The gain where 1.0 is full volume and 0.0 is off
		 * @note Negative values will be ignored
		 */
		void SetGain(f32 gain);

		/** Returns the gain. */
		f32 GetGain() const { return m_Gain; }

		/** 
		 * Sets the max gain. 
		 * @param maxGain The maximum amount of gain allowed for this source
		 * @note Valid range is [0.0 - 1.0] all other values will be ignored
		 */
		void SetMaxGain(f32 maxGain);

		/** Returns the max gain. */
		f32 GetMaxGain() const { return m_MaxGain; }
		/** 
		 * Sets the min gain. 
		 * @param minGain The minimum amount of gain allowed for this source.
		 * @note Valid range is [0.0 - 1.0] all other values will be ignored
		 */
		void SetMinGain(f32 minGain);

		/** Returns the gain. */
		f32 GetMinGain() const { return m_MinGain; }

		/**
		 * Set the min max and current gain.
		 * @param maxGain The maximum amount of gain allowed for this source
		 * @param minGain The minimum amount of gain allowed for this source
		 * @param gain The current gain for this source
		 * @note Gain should be positive
		 */
		void SetGainValues(f32 maxGain, f32 minGain, f32 gain);

		/**
		 * Sets the Max Distance.
		 * @param maxDistance The max distance used in the Inverse Clamped Distance Model
		 * @note This is the distance where there will be no further attenuation of the source
		 * @note Negative values will be ignored
		 */
		void SetMaxDistance(f32 maxDistance);

		/** Returns the max distance */
		f32 GetMaxDistance() const { return m_MaxDistance; }

		/**
		 * Sets the rolloff factor.
		 * @param rolloffFactor The rolloff rate for the source 
		 * @note Used for distance attenuation
		 * @note Negative values will be ignored
		 */
		void SetRolloffFactor(f32 rolloffFactor);

		/** Returns the rolloff factor */
		f32 GetRolloffFactor() const {return m_RolloffFactor;}

		/**
		 * Sets the reference distance.
		 * @param refDistance The reference distance used in attenuation calculations.
		 * @note This is the distance under which the volume for the
		 *     source would normally drop by half
		 * @note Negative values will be ignored
		 */
		void SetReferenceDistance(f32 refDistance);

		/** Returns the reference distance. */
		f32 GetReferenceDistance() const {return m_ReferenceDistance; }

		/**
		 * Sets the variables used in the distance attenuation calculation.
		 * @param maxDistance The max distance used in the Inverse Clamped Distance Model
		 * @param rolloffFactor The rolloff rate for the source
		 * @param refDistance The reference distance used in attenuation calculations
		 */
		void SetDistanceValues(f32 maxDistance, f32 rolloffFactor, f32 refDistance);

		/**
		 * Sets the velocity of the sound.
		 * @param x The x part of the velocity vector
		 * @param y The y part of the velocity vector
		 * @param z The z part of the velocity vector
		 */
		void SetVelocity(f32 x, f32 y, f32 z);

		/** Sets the velocity of the sound. @param vec The velocity vector */
		void SetVelocity(const Vector3& vec);

		/** Returns the velocity of the sound. */
		const Vector3& GetVelocity() const {return m_Velocity;}
		/** 
		 * Sets the source relation to the listner.
		 * @param relative Whether the sound position is
		 *    relative to the listener or not.
		 * @note If this is Set to true then the position of the
		 * sound will be relative to the listener.  However,
		 * Setting this to true will have no effect if the sound
		 * is connected to a scene node.
		 */
		void SetRelativeToListener(bool relative);

		/** Returns true if the sound is relative to the listener, otherwise false. */
		bool IsRelativeToListener() const { return m_SourceRelative == AL_TRUE ? true : false; }

		/**
		 * Sets the position of the sound.
		 * @param x The x part of the position
		 * @param y The y part of the position
		 * @param z The z part of the position
		 * @note In the case that this sound is attached to a SceneNode this
		 *     position become the offset from the parent scene node
		 */
		void SetPosition(f32 x, f32 y, f32 z);

		/**
		 * Sets the position of the sound.
		 * @param vec The new postion for the sound.
		 * @note In the case that this sound is attached to a SceneNode this
		 *     position become the offset from the parent scene node
		 */
		void SetPosition(const Vector3& vec);

		/** Returns the position of the sound. */
		const Vector3& GetPosition() const { return m_Position; }

		/**
		 * Sets the direction of the sound.
		 * @param x The x part of the direction vector
		 * @param y The y part of the direction vector
		 * @param z The z part of the direction vector
		 * @note In the case that this sound is attached to a SceneNode this
		 *     directions becomes relative to the parent's direction
		 */
		void SetDirection(f32 x, f32 y, f32 z);

		/**
		 * Sets the direction of the sound.
		 * @param vec The direction vector.
		 * @note In the case that this sound is attached to a SceneNode this
		 *     directions becomes relative to the parent's direction
		 */
		void SetDirection(const Vector3& vec);

		/** Returns the direction of the sound. */
		const Vector3& GetDirection() const { return m_Direction; }

		/**
		 * Sets the gain outside the sound cone of a directional sound.
		 * @param outerConeGain The gain outside the directional cone
		 * @note Each directional source has three zones:<ol><li>The inner zone as defined by the 
		 *     <i>setInnerConeAngle</i> where the gain is constant and is Set by <i>SetGain</i></li>
		 *     <li>The outer zone which is Set by <i>setOuterConeAngle</i> and the gain is a linear 
		 *     transition between the gain and the outerConeGain</li><li>Outside of the sound cone.  
		 *     The gain in this zone is Set by <i>setOuterConeGain</i></li></ol>
		 * @note Valid range is [0.0 - 1.0] all other values will be ignored
		 */
		void SetOuterConeGain(f32 outerConeGain);

		/** Returns the outerConeGain */
		f32 GetOuterConeGain() const { return m_OuterConeGain; }

		/**
		 * Sets the inner angle of the sound cone for a directional sound.
		 * @param innerConeAngle The angle that defines the inner cone of a directional sound.  Valid values are [0 - 360]
		 * @note Each directional source has three zones:<ol><li>The inner zone as defined by the 
		 *     <i>setInnerConeAngle</i> where the gain is constant and is Set by <i>SetGain</i></li>
		 *     <li>The outer zone which is Set by <i>setOuterConeAngle</i> and the gain is a linear 
		 *     transition between the gain and the outerConeGain</li><li>Outside of the sound cone.  
		 *     The gain in this zone is Set by <i>setOuterConeGain</i></li></ol>
		 */
		void SetInnerConeAngle(f32 innerConeAngle);

		/** Return the innerConeAngle */
		f32 GetInnerConeAngle() const { return m_InnerConeAngle; }

		/**
		 * Sets the outer angle of the sound cone for a directional sound.
		 * @param outerConeAngle The angle that defines the outer cone of a directional sound.  Valid values are [0 - 360]
		 * @note Each directional source has three zones:<ol><li>The inner zone as defined by the 
		 *     <i>setInnerConeAngle</i> where the gain is constant and is Set by <i>SetGain</i></li>
		 *     <li>The outer zone which is Set by <i>setOuterConeAngle</i> and the gain is a linear 
		 *     transition between the gain and the outerConeGain</li><li>Outside of the sound cone.  
		 *     The gain in this zone is Set by <i>setOuterConeGain</i></li></ol>
		 */
		void SetOuterConeAngle(f32 outerConeAngle);

		/** Returns the outerConeAngle */
		f32 GetOuterConeAngle() { return m_OuterConeAngle; } 

		/** Sets the looping state */
		virtual void SetLoop(bool loop);
		/** Returns looping state */
		bool IsLooping() const { return m_Loop == AL_TRUE ? true : false; }

		/** Returns streaming state */
		bool IsStreaming() const { return m_Stream == AL_TRUE ? true : false; }

		/** Sets the priority of the sound */
		void SetPriority(Priority priority) { m_Priority = priority; }

		/** Returns the current Priority for the sound */
		Priority GetPriority() const { return m_Priority; }

		/** Returns the duration of the audio in seconds */
		f32 GetSecondDuration() {return m_LengthInSeconds;}

		/** Sets the offset within the audio stream in seconds. @note Negative values will be ignored */
		virtual void SetSecondOffset(f32 seconds);

		/** Returns the current offset within the audio stream in seconds */
		virtual f32 GetSecondOffset();

		/** Returns the position of the sound including any transform from nodes it is attached to. */
		const Vector3& GetDerivedPosition() const { return m_DerivedPosition; }

		/** Returns the direction of the sound including any transform from nodes it is attached to. */
		const Vector3& GetDerivedDirection() const { return m_DerivedDirection; }

		/** Returns the name of the file used to create this CSound. */
		const String& GetFileName() const { return m_FileName; }

		/** Sets a callback to alert the user when the CSound has stopped playing */
		template<typename T> void addSoundFinishedHandler(T *object, void(T::*function)(CSound *sound))
		{
			m_FinishedCallback = new CMemberFunctionPointer<T>(function, object);
		}

		template<typename T> void addSoundLoopedHandler(T *object, void(T::*function)(CSound *sound))
		{
			m_LoopedCallback = new CMemberFunctionPointer<T>(function, object);
		}

		/** Overridden from MovableObject */
		const String& getMovableType() const;

		/** Overridden from MovableObject */
		const Ogre::AxisAlignedBox& getBoundingBox() const;

		/** Overridden from MovableObject */
		f32 getBoundingRadius() const {return 0; /* Not Visible */} 

		/** Overridden from MovableObject */
		void _updateRenderQueue(Ogre::RenderQueue* queue);

		/** Notifies the sound when it is attached to a node */
		void _notifyAttached(Ogre::Node *parent, bool isTagPoint = false);

		/** Overridden from MovableObject */
		virtual void visitRenderables(Ogre::Renderable::Visitor* visitor, bool debugRenderables = false){}

	protected:
		// Normal Constructor. Should not be called directly! Use CSoundManager::CreateSound 
		CSound(const String& name, const String& fileName, bool stream);

		// Constructor to be called if BufferRef exists 
		CSound(BufferRef buffer, const String& name, const String& fileName, bool loop = false);

		// Updates the sound if need be
		virtual bool UpdateSound();

		// Sets the source for the sound
		void SetSource(SourceRef source) {m_Source = source;}

		// Returns the SourceRef
		SourceRef GetSource() {return m_Source;}

		// Convienance method to reset the sound state
		void InitSource();

		// Convienance method for creating buffers
		void GenerateBuffers();

		// Calculates format info for the sounds. @note requires m_Freq, m_Channels and m_BPS;
		void CalculateFormatInfo();

		// Queues buffers to be played
		void QueueBuffers();

		// Empties any queues that may still be active in the sound
		void unqueueBuffers();

		// Loads the buffers to be played.  Returns whether the buffer is loaded.
		virtual bool LoadBuffers() {return true;}

		// Unloads the buffers.  Returns true if the buffers are still loaded.
		virtual bool UnloadBuffers() {return true;}

		// Returns the BufferRef for this sounds
		BufferRef GetBufferRef() const {return m_Buffers[0];}

		// Postion taking into account the parent node
		mutable Vector3 m_DerivedPosition;

		// Direction taking into account the parent node
		mutable Vector3 m_DerivedDirection;

		// Stored versions of parent orientation
		mutable Ogre::Quaternion m_LastParentOrientation;

		// Stored versions of parent position
		mutable Vector3 m_LastParentPosition;

		f32			m_Pitch;
		f32			m_Gain;
		f32			m_MaxGain;
		f32			m_MinGain;
		f32			m_MaxDistance;
		f32			m_RolloffFactor;
		f32			m_ReferenceDistance;
		f32			m_OuterConeGain;
		f32			m_InnerConeAngle;
		f32			m_OuterConeAngle;
		Vector3 m_Position;
		Vector3 m_Velocity;
		Vector3 m_Direction;
		String		m_FileName;
		ALboolean	m_SourceRelative;
		ALboolean	m_Loop;
		mutable bool m_LocalTransformDirty;

		Ogre::DataStreamPtr m_SoundStream;

		SourceRef	m_Source;
		BufferRef*	m_Buffers;
		int			m_NumBuffers;
		int			m_BufferSize;
		bool		m_Stream;
		bool		m_BuffersLoaded;
		bool		m_BuffersQueued;
		bool		m_IsPlayOnceEvent;			// Has the played once event been called
		Size		m_Freq;
		Size		m_Size;
		Size		m_Channels;
		Size		m_BPS;
		f32			m_LengthInSeconds;
		BufferFormat m_Format;

		bool		m_ManualRestart;
		bool		m_ManualStop;
		f32			m_PreviousOffset;

		Priority	m_Priority;

		// Callbacks to alert the user of specific events
		CMemberFunctionSlot *m_FinishedCallback;
		CMemberFunctionSlot *m_LoopedCallback;

		// This allows us to start a sound back where is should be after being sacrificed
		time_t m_StartTime;
		
		friend class CSoundManager;
		friend class CSoundFactory;

	private:
		void _Update() const;
		void _UpdateFading();

		enum FadeMode
		{
			FADE_NONE,
			FADE_IN,
			FADE_OUT
		};

		FadeMode m_FadeMode;
		f32		 m_FadeTime;
		f32		 m_Running;
	};

} 

#endif
