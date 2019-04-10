#ifndef __PLUGINTYPES_H__
#define __PLUGINTYPES_H__

namespace Core
{
	namespace Plugin
	{
		// Types of plugins supported
		enum E_PLUGIN
		{
			EP_OBJECT_FACTORY	= 0,
			EP_CONSOLE			= 1,
			EP_MISSION			= 2,
			EP_AI_STATE			= 3,
			EP_PLAYER			= 4,
			EP_PARTICLE			= 5,
			EP_CAMERA			= 6,
			EP_ITEM				= 7,
			EP_POSTEFFECT		= 8,
			EP_PHYSICSSTRATEGY	= 9,
			EP_ENTITYEFFECT		= 10,
			EP_BUILDING			= 11,
			EP_NETWORKING		= 12,
			EP_GUISTRATEGY		= 13,
		};

		enum E_COMMAND_RET
		{
			ECR_SUCCESS		= 0,	// Success
			ECR_NOT_FOUND	= 1,	// Command not found
			ECR_NOT_CORRECT = 2,	// Command found not not submitted correly
			ECR_ERROR		= 3,	// Error executing the command
			ECR_CONTINUE	= 4,	// Executed, but another plugin could have the same command so continue through the parsers
		};
	}
}

#endif // __PLUGINTYPES_H__