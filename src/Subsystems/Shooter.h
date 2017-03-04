#pragma once

#include <WPILib.h>
#include <CANTalon.h>
#include "RobotMap.h"


class Shooter: public Subsystem
{
	public:

		Shooter();
		void init();
		void SetShooter(double set);
		void SetWaterWheels(double set);
		void Output();

	private:
		CANTalon m_shooterRight;
		CANTalon m_shooterLeft;
		CANTalon m_wheels;
};
