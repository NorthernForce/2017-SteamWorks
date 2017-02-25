#pragma once

#include <WPILib.h>
#include <CANTalon.h>
#include "RobotMap.h"


class Intake: public Subsystem
{
	public:

		Intake();
		void init();
		void SetIntake(bool set);

	private:
		CANTalon m_intake;
};
