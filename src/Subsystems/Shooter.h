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
		CANTalon m_shooterRight;
		CANTalon m_shooterLeft;
		frc::DigitalOutput m_wheels;
};
