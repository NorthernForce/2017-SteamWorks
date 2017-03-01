#include "MecanumDrive.h"
#include "../Commands/DriveWithJoystick.h"


MecanumDrive::MecanumDrive() :
		frc::PIDSubsystem("MecanumDrive", 0.3, 0.0, 0.0),
		m_frontLeft(kFrontLeftTalon),
		m_frontRight(kFrontRightTalon),
		m_backLeft(kBackLeftTalon),
		m_backRight(kBackRightTalon),
		m_drive(m_frontLeft, m_backLeft, m_frontRight, m_backRight),
		m_gyro(0)
{
	GetPIDController()->SetContinuous(true);
	SetAbsoluteTolerance(2.0);
	SetSetpoint(0.0);
}

double MecanumDrive::ReturnPIDInput() {return m_gyro->GetYaw();}

void MecanumDrive::UsePIDOutput(double output) {m_drive.PIDWrite(output);}

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

	m_gyro = new AHRS(frc::SerialPort::kMXP);

	Zero();

}

void MecanumDrive::DriveMecanum(float x, float y, float rotation, float gyro)
{
	//init();
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



	m_drive.MecanumDrive_Cartesian(double(x), double(y), double(rotation), double(gyro));
	frc::SmartDashboard::PutNumber("DriveMecanum x", x);
	frc::SmartDashboard::PutNumber("DriveMecanum y", y);
	frc::SmartDashboard::PutNumber("DriveMecanum rotation", rotation);
	frc::SmartDashboard::PutNumber("Gyro", gyro);
}

void MecanumDrive::DriveToAngle(float setpoint)
{

	//init();
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


	SetSetpoint(setpoint);

	Enable();
 }

void MecanumDrive::DriveToAngleEnd()
{
	Disable();
}

bool MecanumDrive::IsOnTarget()
{
	return OnTarget();
}

void MecanumDrive::GetGyro()
{
	frc::SmartDashboard::PutNumber("Gyro_Yaw", m_gyro->GetYaw());
}


void MecanumDrive::Zero()
{
	m_gyro->ZeroYaw();
}

float MecanumDrive::GetAngle()
{
	return m_gyro->GetYaw();
}

float MecanumDrive::GetDisplacement()
{
	return m_gyro->GetDisplacementX();
}


