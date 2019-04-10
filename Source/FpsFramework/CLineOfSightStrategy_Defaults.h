#ifndef __CLINEOFSIGHTSTRATEGY_DEFAULTS_H__
#define __CLINEOFSIGHTSTRATEGY_DEFAULTS_H__

namespace Ogre
{
	class Vector3;
	class SceneNode;
}

namespace Core
{
	class CPlayer;
	class CGameObject;
	enum E_LOS_TYPE;

	namespace Physics
	{
		class IPhysicsStrategy;
	}

	class ILineOfSightStrategy
	{
	public:
		ILineOfSightStrategy(CPlayer* Player);
		virtual ~ILineOfSightStrategy() { }
		
		virtual bool CanSee(CPlayer* Player) = 0;
		virtual bool CanSee(const Ogre::Vector3& Position) = 0;

		E_LOS_TYPE GetLoSType() { return m_LosType; }

	protected:
		E_LOS_TYPE			m_LosType;
		CPlayer*			m_Player;
		Ogre::SceneNode*	m_PlayerNode;
	};

	class CLineOfSightStrategy_Basic : public ILineOfSightStrategy
	{
	public:
		CLineOfSightStrategy_Basic(CPlayer* Player);
		~CLineOfSightStrategy_Basic();

		bool CanSee(CPlayer* Player);
		bool CanSee(const Ogre::Vector3& Position);
	};

	class CLineOfSightStrategy_Triangle : public ILineOfSightStrategy
	{
	public:
		CLineOfSightStrategy_Triangle(CPlayer* Player);
		~CLineOfSightStrategy_Triangle();

		bool CanSee(CPlayer* Player);
		bool CanSee(const Ogre::Vector3& Position);

	private:
		Physics::IPhysicsStrategy*  m_PhysicsStrategy;
	};

	class CLineOfSightStrategy_RangeBasic : public ILineOfSightStrategy
	{
	public:
		CLineOfSightStrategy_RangeBasic(CPlayer* Player);
		~CLineOfSightStrategy_RangeBasic();

		bool CanSee(CPlayer* Player);
		bool CanSee(const Ogre::Vector3& Position);

	private:
		Physics::IPhysicsStrategy*  m_PhysicsStrategy;
	};
}

#endif // __CLINEOFSIGHTSTRATEGY_DEFAULTS_H__