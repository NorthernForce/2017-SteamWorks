#include "MecanumDrive.h"
#include "../Commands/DriveWithJoystick.h"


MecanumDrive::MecanumDrive() :
		frc::Subsystem("MecanumDrive"),
		m_frontLeft(kFrontLeftTalon),
		m_frontRight(kFrontRightTalon),
		m_backLeft(kBackLeftTalon),
		m_backRight(kBackRightTalon),
		m_drive(m_frontLeft, m_backLeft, m_frontRight, m_backRight),
		m_rotationRate(0.0) {}


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
	m_drive.SetInvertedMotor(frc::RobotDrive::kFrontRightMotor, false);
	m_drive.SetInvertedMotor(frc::RobotDrive::kRearLeftMotor, true);
	m_drive.SetInvertedMotor(frc::RobotDrive::kRearRightMotor, false);
}

void MecanumDrive::DriveMecanum(float x, float y, float rotation, float gyro)
{
	init();

	m_drive.MecanumDrive_Cartesian(double(x), double(y), double(rotation), double(gyro));
}

void MecanumDrive::DriveToAngle(AHRS* gyro, float setpoint)
{
	init();

	frc::PIDController controller(0.3, 0.0, 0.0, gyro, this);

	controller.SetContinuous(true);
	controller.SetAbsoluteTolerance(2.0);
	controller.SetSetpoint(0.0);
	controller.SetSetpoint(setpoint);
	controller.Enable();

	while(!controller.OnTarget())
	{
		DriveMecanum(0.0, 0.0, m_rotationRate, gyro->GetYaw());
	}
}

void MecanumDrive::PIDWrite(double output)
{
	m_rotationRate = output;
}


