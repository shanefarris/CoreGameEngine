#ifndef _OGREODESTEPPER_H_
#define _OGREODESTEPPER_H_

#include "PreReqs.h"
#include "OgreFrameListener.h"

namespace Ode 
{
    //------------------------------------------------------------------------------------------------
    class StepMode
    {
    public:
        StepMode(World *world) : _world(world) { }
        virtual ~StepMode() { }

        virtual void step(const f32& time) = 0;

    protected:
        World* _world;
    };
    //------------------------------------------------------------------------------------------------
    class BasicStepMode : public StepMode
    {
    public:
        BasicStepMode(World *world) : StepMode(world) { }
        virtual ~BasicStepMode() { }

        inline void step(const f32& time) { dWorldStep(_world->getWorldID(), (dReal)time); }
    };
    //------------------------------------------------------------------------------------------------
    class QuickStepMode : public StepMode
    {
    public:
        QuickStepMode(World *world) : StepMode(world) { }
        virtual ~QuickStepMode() { }

        inline void step(const f32& time) { dWorldQuickStep(_world->getWorldID(), (dReal)time); }
    };
    //------------------------------------------------------------------------------------------------
	class StepListener
	{
	public:
		StepListener() { }
		virtual ~StepListener() { }

        virtual bool preStep(const f32& time) { return true; }
        virtual bool postStep(const f32& time)  { return true; }
        virtual bool middleStep(const f32& time)  { return true; }
    };
    //------------------------------------------------------------------------------------------------
	class StepHandler : public Ogre::FrameListener
    {
	public:
		enum AutoMode
		{
			AutoMode_NotAutomatic,
			AutoMode_PreFrame,
			AutoMode_PostFrame
        };
        enum StepModeType
        {
            BasicStep = 0,
            QuickStep,
            FastStep,
            StepModeTypeCount
        };

	public:
        StepHandler(World *world, StepModeType stepModeType = QuickStep, 
			const f32& step_size = 0.01f, 
			const f32& max_interval = 1.0f / 4.0f, 
			const f32& time_scale = 1.0f);

		virtual ~StepHandler();

		virtual bool step(const f32& time);

		f32 getStepSize() const { return _step_size; }
		void setStepSize (const f32& step_size){ _step_size = step_size; }

		void pause(bool pause);
		bool isPaused();

		void setStepListener(StepListener* listener);
		void setAutomatic(StepHandler::AutoMode mode, EngineDevice* root = 0);

		bool frameStarted(const FrameEvent& evt);
		bool frameEnded(const FrameEvent& evt);

    protected:
        bool prepareSteppingTime(const f32& time);
        bool basicStep(const f32& time);

	protected:
		World*	_world;
		bool	_paused;
		bool	_auto_pre;
		bool	_auto_post;
		f32		_step_size;
        f32		_total_time;
        f32		_max_interval;
        f32		_time_scale;
		EngineDevice* _root;
		StepListener* _listener;
        StepMode*	  _current_stepper;
    };

    //------------------------------------------------------------------------------------------------
	class ForwardFixedStepHandler:public StepHandler
	{
	public:
        ForwardFixedStepHandler(World *world, StepModeType stepModeType = QuickStep, 
			const f32& step_size = 0.01f, 
			const f32& max_interval = 1.0f / 4.0f, 
			const f32& time_scale = 1.0f);

		virtual ~ForwardFixedStepHandler();

		virtual bool step(const f32& time);
    };
    //------------------------------------------------------------------------------------------------
	class ExactVariableStepHandler:public StepHandler
	{
	public:
        ExactVariableStepHandler(World *world ,
            StepModeType stepModeType = QuickStep,
            const f32& step_size = 0.01f, 
            const f32& max_interval = 1.0f / 4.0f, 
            const f32& time_scale = 1.0f);

		virtual ~ExactVariableStepHandler();

		virtual bool step(const f32& time);
    };
    //------------------------------------------------------------------------------------------------
	// Fix your timestep Gaffer implementation.
	// http://www.gaffer.org/articles/Timestep.html
	// Gaffer :"If you implement this interpolation technique you ensure that there will
	// not be any visual stuttering when your display and physics framerates 
	// are out of sync. It will also perfectly handle the undersampling case so 
	// your objects will move smoothly when you view your simulation in slow 
	// motion or ten years from now on that Sexium." 
	class ForwardFixedInterpolatedStepHandler : public StepHandler
	{
	public:
        ForwardFixedInterpolatedStepHandler(World *world, 
            StepModeType stepModeType = QuickStep,
            const f32& step_size = 0.01f, 
            const f32& frame_rate = 1.0f / 60.0f,
            const f32& max_interval = 1.0f / 4.0f, 
            const f32& time_scale = 1.0f);

		virtual ~ForwardFixedInterpolatedStepHandler();

		virtual bool step(const f32& time);
    private :
        f32		_dbl_step_size;
        f32		_inv_step_size;

        f32		_next_total_time;
        u32		_next_frame_step_count;
        f32		_inv_next_total_time;
        bool	_fixed_frame_rate;
        f32		_frame_rate;
	};

}

#endif
