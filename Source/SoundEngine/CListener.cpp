#include "SoundEngineException.h"
#include "CListener.h"

#include "OgreNode.h"

template<> Sound::CListener* Ogre::Singleton<Sound::CListener>::msSingleton = 0;

namespace Sound 
{

	CListener* CListener::Listener = nullptr;

	CListener* CListener::Instance()
	{
		if(Listener == nullptr)
			Listener = new CListener();
		return Listener;
	}

	CListener::CListener() :
		m_Gain(1.0),
		m_Position(Vector3::ZERO),
		m_Direction(Vector3::NEGATIVE_UNIT_Z),
		m_Velocity(Vector3::ZERO),
		m_Up(Vector3::UNIT_Y),
		m_DerivedPosition(Vector3::ZERO),
		m_DerivedDirection(Vector3::NEGATIVE_UNIT_Z)
	{
		mParentNode = nullptr;
		m_LocalTransformDirty = false;
		InitListener();
	}

	CListener::CListener(const String& name) :
		Ogre::MovableObject(name),
		m_Gain(1.0),
		m_Position(Vector3::ZERO),
		m_Direction(Vector3::NEGATIVE_UNIT_Z),
		m_Velocity(Vector3::ZERO),
		m_Up(Vector3::UNIT_Y),
		m_DerivedPosition(Vector3::ZERO),
		m_DerivedDirection(Vector3::NEGATIVE_UNIT_Z)
	{
		mParentNode = nullptr;
		InitListener();
	}

	CListener::~CListener()
	{
	}

	void CListener::SetGain(f32 gain)
	{
		m_Gain = gain;

		alListenerf(AL_GAIN, m_Gain);
		CheckError(alGetError(), "Failed to Set Gain");
	}

	void CListener::SetPosition(f32 x, f32 y, f32 z)
	{
		m_Position.x = x;
		m_Position.y = y;
		m_Position.z = z;
		m_LocalTransformDirty = true;
	}

	void CListener::SetPosition(const Vector3& vec)
	{
		m_Position = vec;
		m_LocalTransformDirty = true;
	}

	void CListener::SetDirection(f32 x, f32 y, f32 z)
	{
		m_Direction.x = x;
		m_Direction.y = y;
		m_Direction.z = z;
		m_LocalTransformDirty = true;
	}

	void CListener::SetDirection(const Vector3& vec)
	{
		m_Direction = vec;
		m_LocalTransformDirty = true;
	}

	void CListener::SetVelocity(f32 x, f32 y, f32 z)
	{
		m_Velocity.x = x;
		m_Velocity.y = y;
		m_Velocity.z = z;

		alListener3f(AL_VELOCITY, m_Velocity.x, m_Velocity.y, m_Velocity.z);
		CheckError(alGetError(), "Failed to Set Velocity");
	}

	void CListener::SetVelocity(const Vector3& vec)
	{
		SetVelocity(vec.x, vec.y, vec.z);
	}

	const Vector3& CListener::GetDerivedPosition(void) const
	{
		Update();
		return m_DerivedPosition;
	}

	const Vector3& CListener::GetDerivedDirection(void) const
	{
		Update();
		return m_DerivedDirection;
	}

	void CListener::InitListener()
	{
		mOrientation[0]= m_Direction.x; // Forward.x
		mOrientation[1]= m_Direction.y; // Forward.y
		mOrientation[2]= m_Direction.z; // Forward.z

		mOrientation[3]= m_Up.x; // Up.x
		mOrientation[4]= m_Up.y; // Up.y
		mOrientation[5]= m_Up.z; // Up.z

		alListener3f(AL_POSITION, m_Position.x, m_Position.y, m_Position.z);
		CheckError(alGetError(), "Failed to Set Position");

		alListenerfv(AL_ORIENTATION, mOrientation);
		CheckError(alGetError(), "Failed to Set Orientation");

		alListenerf (AL_GAIN, 1.0f);
		CheckError(alGetError(), "Failed to Set Gain");

		alListener3f(AL_VELOCITY, 0.0f, 0.0f, 0.0f);
		CheckError(alGetError(), "Failed to Set Velocity");
	}

	void CListener::Update() const
	{
		if (mParentNode)
		{
			if (!(mParentNode->_getDerivedOrientation() == m_LastParentOrientation &&
				mParentNode->_getDerivedPosition() == m_LastParentPosition)
				|| m_LocalTransformDirty)
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

	void CListener::UpdateListener()
	{
		Update();
		if(mParentNode)
		{
			m_Position = m_LastParentPosition;
			m_Direction = m_LastParentOrientation.zAxis();
			m_Up = m_LastParentOrientation.yAxis();
		}
		alListener3f(AL_POSITION, m_Position.x, m_Position.y, m_Position.z);
		CheckError(alGetError(), "Failed to Set Position");

		mOrientation[0]= -m_Direction.x; // Forward.x
		mOrientation[1]= -m_Direction.y; // Forward.y
		mOrientation[2]= -m_Direction.z; // Forward.z

		mOrientation[3]= m_Up.x; // Up.x
		mOrientation[4]= m_Up.y; // Up.y
		mOrientation[5]= m_Up.z; // Up.z

		alListenerfv(AL_ORIENTATION, mOrientation); 
		CheckError(alGetError(), "Failed to Set Orientation");
	}

	const String& CListener::getMovableType() const
	{
		return ListenerFactory::FACTORY_TYPE_NAME;
	}

	const Ogre::AxisAlignedBox& CListener::getBoundingBox() const
	{
		// Null, Sounds are not visible
		static Ogre::AxisAlignedBox box;
		return box;
	}

	void CListener::_updateRenderQueue(Ogre::RenderQueue* queue)
	{
		// Do Nothing
	}

	void CListener::_notifyAttached(Ogre::Node* parent, bool isTagPoint)
	{
		mParentNode = parent;
	}

	String ListenerFactory::FACTORY_TYPE_NAME = "OgreAL_Listener";

	const String& ListenerFactory::getType(void) const
	{
		return FACTORY_TYPE_NAME;
	}

	Ogre::MovableObject* ListenerFactory::createInstanceImpl(const String& name, const Ogre::NameValuePairList* params)
	{
		CListener *listener = CListener::Instance();
		if(listener)
			return listener;
		else
			return new CListener(name);
	}

	void ListenerFactory::destroyInstance(Ogre::MovableObject* obj)
	{
		delete obj;
	}

}
