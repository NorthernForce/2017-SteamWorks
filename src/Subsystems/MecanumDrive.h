#pragma once

#include "CANTalon.h"
#include <WPILib.h>
#include "../RobotMap.h"

class MecanumDrive: public frc::Subsystem
{
	public:
		MecanumDrive();
		void InitDefaultCommand() override;
		void DriveMecanum(float x, float y, float rotation);
		void init();

		void RelayOn();

	private:

		frc::RobotDrive m_drive;
		CANTalon m_frontLeft;
		CANTalon m_frontRight;
		CANTalon m_backLeft;
		CANTalon m_backRight;

		frc::Relay m_relay;
};

