#ifndef __AI_REACTION_COMPONENT_H__
#define __AI_REACTION_COMPONENT_H__

namespace Core
{
	class CPlayer;
	
namespace AI
{
	class IAiReactionComponent
	{
	public:
		IAiReactionComponent(CPlayer* Player) : m_Player(Player) { }
		virtual ~IAiReactionComponent() { }
		
		virtual void OnCharacterStateChange() = 0;
		
	protected:
		CPlayer*	m_Player;
	};
	
}
}

#endif // __AI_REACTION_COMPONENT_H__