#include "MecanumDrive.h"


MecanumDrive::MecanumDrive() :
		frc::Subsystem("MecanumDrive"),
		m_drive(m_frontLeft, m_frontRight, m_backLeft, m_backRight),
		m_frontLeft(kFrontLeftTalon),
		m_frontRight(kFrontRightTalon),
		m_backLeft(kBackLeftTalon),
		m_backRight(kBackRightTalon)
		{}

void MecanumDrive::InitDefaultCommand()
{
	//SetDefaultCommand(new DriveWithJoystick());
}

void MecanumDrive::init()
{
	m_drive.SetSafetyEnabled(false);

	// Included in case the robot is wired strangely
	m_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
	m_drive.SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
	m_drive.SetInvertedMotor(RobotDrive::kRearLeftMotor, false);
	m_drive.SetInvertedMotor(RobotDrive::kRearRightMotor, false);

	m_drive.SetExpiration(0.2);
}

void MecanumDrive::DriveMecanum(float x, float y, float rotation)
{
	m_drive.MecanumDrive_Cartesian(x, y, rotation);
}

