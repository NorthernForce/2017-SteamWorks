#pragma once

#include <WPILib.h>
#include <CANTalon.h>
#include "RobotMap.h"


class Climber: public Subsystem
{
	public:

		Climber();
		void init();
		void SetClimber(bool set);

	private:
		CANTalon m_climber;
};
