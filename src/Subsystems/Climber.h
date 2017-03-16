#pragma once

#include <WPILib.h>
#include <CANTalon.h>
#include "RobotMap.h"


class Climber: public Subsystem
{
	public:

		Climber();
		void init();
		void SetClimber(double set);
		double GetVoltage();
		int GetVel();
		//void SetRelay();
		void SetVoltage();

	private:
		CANTalon m_climber;

		//frc::Relay* m_relay;
};
