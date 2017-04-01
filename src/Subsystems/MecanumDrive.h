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

		float AvgValue(int Motor, float Val);

		void DriveMecanum(float xVel, float yVel, float rotation, float gyro);
		void DriveToAngleInit(float setpoint);
		void DriveToAngle(float angle);
		void SetDriveRelative(bool mode);
		bool GetIsDriveRelative();

		void UsePIDOutput(double output) override;
		double ReturnPIDInput() override;

		void SetInput(double input);

		void PIDWrite(double output) override;

		void DriveFL(double set);
		void DriveFR(double set);
		void DriveBL(double set);
		void DriveBR(double set);

		void FLData();
		void FRData();
		void BLData();
		void BRData();


	private:

		CANTalon m_frontLeft;
		CANTalon m_frontRight;
		CANTalon m_backLeft;
		CANTalon m_backRight;
		RobotDrive m_drive;

		float m_rotationRate;
		bool m_isDriveRelative;
		double m_input;

		int m_pos;
		float m_A[kMotors][kMaxSample];

		double m_p;
		double m_i;
		double m_d;
		double m_f;
		int    m_ppr;
		double m_ramprate;
		int    m_profile;
};

