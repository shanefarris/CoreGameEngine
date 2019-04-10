#ifndef __CAICONTROLLER_H__
#define __CAICONTROLLER_H__

namespace Ogre
{
	class Vector3;
}

namespace Core
{
	class CPlayer;

namespace AI
{
	class CAiController
	{
	public:
		CAiController(CPlayer* Player) : m_Player(Player) { }
		virtual ~CAiController() { }

		CPlayer* GetPlayer() { return m_Player; }
		Ogre::Vector3  GetPosition();

	protected:
		CPlayer*	m_Player;
		Ogre::Vector3
	};
}
}

#endif // __CAICONTROLLER_H__