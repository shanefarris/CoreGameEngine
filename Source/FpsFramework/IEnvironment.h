#pragma once

namespace Core
{
namespace Nature
{
	enum E_ENVIRONMENT_TYPE
	{
		EET_HYDRAX,
		EET_VEG,
		EET_WEATHER,
		EET_RAIN,
		EET_TERRIN,
		EET_SKY,
	};

	class IEnvironment
	{
	public:
		virtual ~IEnvironment() { }
		virtual void Update(const float& elapsed) = 0;
		virtual void Shutdown() = 0;
		virtual void Pause() = 0;
		virtual void Resume() = 0;

		E_ENVIRONMENT_TYPE EnvironmentType;
	};
}
}