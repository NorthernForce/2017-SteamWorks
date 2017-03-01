#pragma once

#include "CANTalon.h"
#include <WPILib.h>
#include <AHRS.h>
#include "../RobotMap.h"

class PIDDrive : public frc::PIDOutput, public frc::RobotDrive
{
	public:
		PIDDrive(CANTalon& a, CANTalon& b, CANTalon& c, CANTalon& d) : RobotDrive(a, b, c, d),
																   m_rotationRate(0) {}
		void PIDWrite(double output) override
		{
			m_rotationRate = output;
		}

	private:
		double m_rotationRate;
};


class MecanumDrive: public frc::PIDSubsystem
{
	public:
		MecanumDrive();
		void InitDefaultCommand() override;
		void init();

		void DriveMecanum(float xVel, float yVel, float rotation, float gyro);
		void DriveToAngle(float setpoint);
		void DriveToAngleEnd();
		bool IsOnTarget();


		void GetGyro();
		void Zero();
		float GetAngle();
		float GetDisplacement();


	protected:
		double ReturnPIDInput();
		void UsePIDOutput(double output);

	private:

		CANTalon m_frontLeft;
		CANTalon m_frontRight;
		CANTalon m_backLeft;
		CANTalon m_backRight;
		PIDDrive m_drive;

		AHRS* m_gyro;
};

