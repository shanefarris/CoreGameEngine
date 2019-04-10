#ifndef __CAIREACTIONCOMPONENT_DEFAULT_H__
#define __CAIREACTIONCOMPONENT_DEFAULT_H__

#include "IAiReactionComponent.h"

namespace Core
{
	class CPlayer;
	
namespace AI
{
	class CAiReactionComponent_Default : public IAiReactionComponent
	{
	public:
		CAiReactionComponent_Default(CPlayer* Player);
		~CAiReactionComponent_Default();
		
		void OnCharacterStateChange();
	};
	
}
}

#endif // __CAIREACTIONCOMPONENT_DEFAULT_H__