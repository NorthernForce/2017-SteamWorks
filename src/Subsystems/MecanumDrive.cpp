#include "MecanumDrive.h"
#include "../Commands/DriveWithJoystick.h"


MecanumDrive::MecanumDrive() :
		frc::PIDSubsystem("MecanumDrive", 0.3, 0.0, 0.0, 0.0),
		m_frontLeft(kFrontLeftTalon),
		m_frontRight(kFrontRightTalon),
		m_backLeft(kBackLeftTalon),
		m_backRight(kBackRightTalon),
		m_drive(m_frontLeft, m_backLeft, m_frontRight, m_backRight),
		m_rotationRate(0.0),
		m_isDriveRelative(false),
		m_input(0) {}


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

	m_frontLeft.SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_backLeft.SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_frontRight.SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_backRight.SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);

}

void MecanumDrive::DriveMecanum(float x, float y, float rotation, float gyro)
{
	init();

	if(m_isDriveRelative)
	{
		m_drive.MecanumDrive_Cartesian(double(x), double(y), double(rotation), double(gyro));
	}

	else
	{
		m_drive.MecanumDrive_Cartesian(double(x), double(y), double(rotation));
	}
}

void MecanumDrive::DriveToAngleInit(float setpoint)
{
	init();

	SetInputRange(-180.0, 180.0);
	SetOutputRange(-1.0, 1.0);
	SetAbsoluteTolerance(2.0);
	SetSetpoint(setpoint);
	Enable();
}

void MecanumDrive::DriveToAngle(float angle)
{
		DriveMecanum(0.0, 0.0, m_rotationRate, angle);
}

void MecanumDrive::SetDriveRelative(bool mode)
{
	m_isDriveRelative = mode;
}

bool MecanumDrive::GetIsDriveRelative()
{
	return m_isDriveRelative;
}

void MecanumDrive::UsePIDOutput(double output)
{
	m_rotationRate = output;

	std::cout << "Rotation Rate " << m_rotationRate << std::endl;
}

double MecanumDrive::ReturnPIDInput()
{
	return m_input;
}

void MecanumDrive::SetInput(double input)
{
	m_input = input;
}

