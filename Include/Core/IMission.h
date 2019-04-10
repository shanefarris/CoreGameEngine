#ifndef __IMISSION_H__
#define __IMISSION_H__

namespace Core
{
namespace Mission
{
	class CMissionEvent;

	// Defines what events need to take place before the mission is completed
	enum MISSION_TYPE
	{
		MT_ELIMINATE	= 0,	// A player needs to die
		MT_PICKUP		= 1,	// Something needs to be picked up
		MT_BROUGHT_HQ	= 2,	// Something needs to be brought to HQ
		MT_RESCUED		= 3,	// Someone needs rescued 
		MT_LOCATION		= 4,	// Reach a specific location (volume)
	};
	
	enum MISSION_STATUS
	{
		MS_WORKING		= 0,
		MS_STOPPED		= 1,
		MS_FAILED		= 2,
		MS_SUCCESS		= 3,
	};

	class IMission
	{
	public:
		virtual void OnStart() = 0;		// Event when the mission starts
		virtual void OnFail() = 0;		// Event when the mission fails
		virtual void OnComplete() = 0;	// Even when the mission is completed successfully
		
		// Updates the mission variables and returns the mission status
		virtual MISSION_STATUS Update() = 0;

		// Used to send data to this mission about updates that could affect the status of the mission
		virtual void RegisterEvent(CMissionEvent* Event) = 0;

		MISSION_STATUS GetStatus() { return m_MissionStatus; }

		String LableName;				// Used to ask the MM what mission is needed
		MISSION_TYPE CompletionDefinition;

	protected:
		bool	isRequired;				// Is this mission required
		bool	isSuccess;				// Completed successfully
		bool	isFailed;				// Was the mission failed
		bool	isStarted;				// Has it started
		MISSION_STATUS m_MissionStatus;	// Current status of the mission
	};

}
}

#endif // __IMISSION_H__