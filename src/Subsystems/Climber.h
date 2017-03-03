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

	private:
		CANTalon m_climber;
};
