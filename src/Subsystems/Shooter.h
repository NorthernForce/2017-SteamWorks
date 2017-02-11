#pragma once

#include <WPILib.h>
#include "../RobotMap.h"

class Shooter: public frc::Subsystem
{
	public:
		Shooter();
		void InitDefaultCommand() override;
		void init();
		void Shoot();
		void Expell();


	private:

		frc::Talon m_shooterTalon;

};

