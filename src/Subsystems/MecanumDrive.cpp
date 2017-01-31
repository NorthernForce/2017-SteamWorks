#include "MecanumDrive.h"
#include "../Commands/DriveWithJoystick.h"


MecanumDrive::MecanumDrive() :
		frc::Subsystem("MecanumDrive"),
		m_drive(m_frontLeft, m_frontRight, m_backLeft, m_backRight),
		m_frontLeft(kFrontLeftTalon),
		m_frontRight(kFrontRightTalon),
		m_backLeft(kBackLeftTalon),
		m_backRight(kBackRightTalon),
		m_relay(0)
		{}

void MecanumDrive::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystick());
}

void MecanumDrive::init()
{
	m_drive.SetSafetyEnabled(false);

	// Included in case the robot is wired strangely
	m_drive.SetInvertedMotor(frc::RobotDrive::kFrontLeftMotor, true);
	m_drive.SetInvertedMotor(frc::RobotDrive::kFrontRightMotor, true);
	m_drive.SetInvertedMotor(frc::RobotDrive::kRearLeftMotor, false);
	m_drive.SetInvertedMotor(frc::RobotDrive::kRearRightMotor, false);

	m_drive.SetExpiration(0.1);
}

void MecanumDrive::DriveMecanum(float x, float y, float rotation)
{
	m_drive.MecanumDrive_Cartesian(x, y, rotation);
}

void MecanumDrive::RelayOn()
{
	m_relay.Set(frc::Relay::kOn);
}


