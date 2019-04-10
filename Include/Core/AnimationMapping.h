#ifndef __ANIMATION_MAPPING_H__
#define __ANIMATION_MAPPING_H__

namespace Core
{
	// Standard animations
	enum E_ANIM_STATE
	{
		EAS_IDLE		= 0,	// Just killing time
		EAS_WALK		= 1,
		EAS_RUN			= 2,
		EAS_SPRINT		= 3,	// Fastest run
		EAS_DIEING		= 4,	// When they are dieing
		EAS_DEAD		= 5,	// They are dead, no motion
		EAS_CRAWL		= 6,
		EAS_SHOOT		= 7,
		EAS_RELOAD		= 8,
		EAS_KNEEL		= 9,
		EAS_PRONE		= 10,
		EAS_RUNSHOOT	= 11,
		EAS_HIT			= 12,
		EAS_MELEE		= 13,
		EAS_JUMP		= 14,
		EAS_AIM_STAND	= 15,
		EAS_CHANGE_ITEM = 16,
		EAS_NONE		= 32
	};

	struct SoundToAnimation
	{
		SoundToAnimation(const char* Anim, const char* Sound)
		{
			Animation = Anim;
			AnimSound = Sound;
		}

		const char* Animation;		// Animation name in the skeleton
		const char* AnimSound;		// Sound file in the sound engine
	};
}

#endif // __ANIMATION_MAPPING_H__