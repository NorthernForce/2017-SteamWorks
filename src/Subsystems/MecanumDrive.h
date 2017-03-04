#pragma once

#include "CANTalon.h"
#include <WPILib.h>
#include <AHRS.h>
#include "../RobotMap.h"


class MecanumDrive: public frc::Subsystem, public frc::PIDOutput
{
	public:
		MecanumDrive();
		void InitDefaultCommand() override;
		void init();

		void DriveMecanum(float xVel, float yVel, float rotation, float gyro);
		void DriveToAngle(AHRS* gyro, float setpoint);
		void SetDriveRelative(bool mode);



		void PIDWrite(double output) override;


	private:

		CANTalon m_frontLeft;
		CANTalon m_frontRight;
		CANTalon m_backLeft;
		CANTalon m_backRight;
		RobotDrive m_drive;

		double m_rotationRate;
		bool m_isDriveRelative;
};

