#pragma once

#include "CANTalon.h"
#include <WPILib.h>
#include <AHRS.h>
#include "../RobotMap.h"


class MecanumDrive: public frc::PIDSubsystem
{
	public:
		MecanumDrive();
		void InitDefaultCommand() override;
		void init();

		void DriveMecanum(float xVel, float yVel, float rotation, float gyro);
		void DriveToAngleInit(float setpoint);
		void DriveToAngle(float angle);
		void SetDriveRelative(bool mode);
		bool GetIsDriveRelative();

		void UsePIDOutput(double output) override;
		double ReturnPIDInput() override;

		void SetInput(double input);


	private:

		CANTalon m_frontLeft;
		CANTalon m_frontRight;
		CANTalon m_backLeft;
		CANTalon m_backRight;
		RobotDrive m_drive;

		float m_rotationRate;
		bool m_isDriveRelative;
		double m_input;
};

