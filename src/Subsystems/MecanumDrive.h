#pragma once

#include "CANTalon.h"
#include <WPILib.h>
#include <AHRS.h>
#include "../RobotMap.h"

class MecanumDrive: public frc::Subsystem
{
	public:
		MecanumDrive();
		void InitDefaultCommand() override;
		void DriveMecanum(float xVel, float yVel, float rotation, float gyro);
		void DriveToAngle(AHRS* gyro, float setpoint);
		void DriveToAngleEnd();
		bool AngleSet();
		void init();


	private:

		CANTalon m_frontLeft;
		CANTalon m_frontRight;
		CANTalon m_backLeft;
		CANTalon m_backRight;
		frc::RobotDrive m_drive;

		frc::PIDController* m_controller;
};

