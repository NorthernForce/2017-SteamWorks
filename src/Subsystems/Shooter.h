#pragma once

#include <WPILib.h>
#include <CANTalon.h>
#include "RobotMap.h"


class Shooter: public Subsystem
{
	public:

		Shooter();
		void init();
		void SetShooter(bool set);
		void SetWaterWheels(bool set);

	private:
		CANTalon m_shooter;
		CANTalon m_wheels;
};
