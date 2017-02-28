#include "MecanumDrive.h"
#include "../Commands/DriveWithJoystick.h"


MecanumDrive::MecanumDrive() :
		frc::Subsystem("MecanumDrive"),
		m_frontLeft(kFrontLeftTalon),
		m_frontRight(kFrontRightTalon),
		m_backLeft(kBackLeftTalon),
		m_backRight(kBackRightTalon),
		m_drive(m_frontLeft, m_backLeft, m_frontRight, m_backRight),
		m_controller(0) {}

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
	frc::SmartDashboard::PutNumber("DriveMecanum x", x);
	frc::SmartDashboard::PutNumber("DriveMecanum y", y);
	frc::SmartDashboard::PutNumber("DriveMecanum rotation", rotation);
	frc::SmartDashboard::PutNumber("Gyro", gyro);
}

void MecanumDrive::DriveToAngle(AHRS* gyro, float setpoint)
{

	init();

	double kP = 0.03f;
	double kI = 0.00f;
	double kD = 0.00f;
	double kF = 0.00f;
	double kToleranceDegrees = 2.0f;

    m_controller = new frc::PIDController(kP, kI, kD, kF, dynamic_cast<frc::PIDSource*>(gyro), dynamic_cast<frc::PIDOutput*>(&m_drive));
    m_controller->SetInputRange(-180.0f,  180.0f);
    m_controller->SetOutputRange(-1.0, 1.0);
    m_controller->SetAbsoluteTolerance(kToleranceDegrees);
    m_controller->SetContinuous(true);
    m_controller->SetSetpoint(setpoint);
 	m_controller->Enable();
 }

void MecanumDrive::DriveToAngleEnd()
{
	m_controller->Disable();
}

bool MecanumDrive::AngleSet()
{
	return m_controller->OnTarget();

}
