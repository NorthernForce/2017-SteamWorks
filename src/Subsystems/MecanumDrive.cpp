#include "MecanumDrive.h"
#include "../Commands/DriveWithJoystick.h"


MecanumDrive::MecanumDrive() :
		frc::Subsystem("MecanumDrive"),
		m_frontLeft(kFrontLeftTalon),
		m_frontRight(kFrontRightTalon),
		m_backLeft(kBackLeftTalon),
		m_backRight(kBackRightTalon),
		m_drive(m_frontLeft, m_frontRight, m_backLeft, m_backRight) {}

void MecanumDrive::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystick());
}

void MecanumDrive::init()
{
	m_frontLeft.Set(0.0);
	m_backLeft.Set(0.0);
	m_frontRight.Set(0.0);
	m_backRight.Set(0.0);

	m_drive.SetExpiration(0.5);
	m_drive.SetSafetyEnabled(false);

	m_drive.SetInvertedMotor(frc::RobotDrive::kFrontLeftMotor, true);
	m_drive.SetInvertedMotor(frc::RobotDrive::kFrontRightMotor, true);
	m_drive.SetInvertedMotor(frc::RobotDrive::kRearLeftMotor, false);
	m_drive.SetInvertedMotor(frc::RobotDrive::kRearRightMotor, false);
}

void MecanumDrive::DriveMecanum(float x, float y, float rotation)//, float gyro)
{
	init();

	m_drive.MecanumDrive_Cartesian(double(x), double(y), double(rotation));//, double(gyro));
	frc::SmartDashboard::PutNumber("DriveMecanum x", x);
	frc::SmartDashboard::PutNumber("DriveMecanum y", y);
	frc::SmartDashboard::PutNumber("DriveMecanum rotation", rotation);
	//frc::SmartDashboard::PutNumber("Gyro", gyro);
}

