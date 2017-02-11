#include "MecanumDrive.h"
#include "../Commands/DriveWithJoystick.h"


MecanumDrive::MecanumDrive() :
		frc::Subsystem("MecanumDrive"),
		m_frontLeft(kFrontLeftTalon),
		m_frontRight(kFrontRightTalon),
		m_backLeft(kBackLeftTalon),
		m_backRight(kBackRightTalon),
		m_drive(m_frontLeft, m_frontRight, m_backLeft, m_backRight)
		{}

void MecanumDrive::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystick());
}

void MecanumDrive::init()
{

//	m_frontLeft.EnableControl();
//	m_backLeft.EnableControl();
//	m_frontRight.EnableControl();
//	m_backRight.EnableControl();

	std::cout << "MecanumDrive::Init called!!!" << std::endl;

	m_frontLeft.Set(0.0);
	m_backLeft.Set(0.0);
	m_frontRight.Set(0.0);
	m_backRight.Set(0.0);

	// Included in case the robot is wired strangely

	//m_drive.SetMaxOutput(1.0);

	//m_frontLeft.SetTalonControlMode(CANTalon::kVoltageMode);
	//m_backLeft.SetTalonControlMode(CANTalon::kVoltageMode);
	//m_frontRight.SetTalonControlMode(CANTalon::kVoltageMode);
	//m_backRight.SetTalonControlMode(CANTalon::kVoltageMode);

	//m_frontLeft->Enable();
	//m_backLeft->Enable();
	//m_frontRight->Enable();
	//m_backRight->Enable();


	m_drive.SetExpiration(0.5);
	m_drive.SetSafetyEnabled(false);

	//m_frontLeft.SetVoltageRampRate(6.0);
	//m_backLeft.SetVoltageRampRate(6.0);
	//m_frontRight.SetVoltageRampRate(6.0);
	//m_backRight.SetVoltageRampRate(6.0);
	frc::SmartDashboard::PutString("MecanumDrive  init?", "Yesss");
	m_drive.SetInvertedMotor(frc::RobotDrive::kFrontLeftMotor, true);
	m_drive.SetInvertedMotor(frc::RobotDrive::kFrontRightMotor, true);
	m_drive.SetInvertedMotor(frc::RobotDrive::kRearLeftMotor, false);
	m_drive.SetInvertedMotor(frc::RobotDrive::kRearRightMotor, false);
}

void MecanumDrive::DriveMecanum(float x, float y, float rotation)
{
	init();

	m_drive.MecanumDrive_Cartesian(double(x), double(y), double(rotation));
	frc::SmartDashboard::PutString("DriveMecanum?", "Yesss");
	frc::SmartDashboard::PutNumber("DriveMecanum x", x);
	frc::SmartDashboard::PutNumber("DriveMecanum y", y);
	frc::SmartDashboard::PutNumber("DriveMecanum rotation", rotation);
}

