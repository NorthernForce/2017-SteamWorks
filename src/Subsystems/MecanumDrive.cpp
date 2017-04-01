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
		m_input(0),
		m_p(1.0),
		m_i(0.0),
		m_d(0),
		m_f(0.0003),
		m_ppr(256),
		m_ramprate(60),
		m_profile(0)
{
  int i, m;

  for (m = 0; m < kMotors; ++m)
  {
	  for (i = 0; i < kMaxSample; ++i)
	  {
		  m_A[m][i] = 0;
	  };
  }

  m_pos = 0;
/*
  m_frontLeft.SelectProfileSlot(m_profile);
  m_frontLeft.SetPID(m_p, m_i, m_d, m_f);
  m_frontLeft.SetIzone(m_ppr);
  m_frontLeft.SetCloseLoopRampRate(m_ramprate);

  m_backLeft.SelectProfileSlot(m_profile);
  m_backLeft.SetPID(m_p, m_i, m_d, m_f);
  m_backLeft.SetIzone(m_ppr);
  m_backLeft.SetCloseLoopRampRate(m_ramprate);

  m_frontRight.SelectProfileSlot(m_profile);
  m_frontRight.SetPID(m_p, m_i, m_d, m_f);
  m_frontRight.SetIzone(m_ppr);
  m_frontRight.SetCloseLoopRampRate(m_ramprate);

  m_backRight.SelectProfileSlot(m_profile);
  m_backRight.SetPID(m_p, m_i, m_d, m_f);
  m_backRight.SetIzone(m_ppr);
  m_backRight.SetCloseLoopRampRate(m_ramprate);
  */

//  m_frontLeft.SetTalonControlMode(CANTalon::TalonControlMode::kSpeedMode);
//  m_backLeft.SetTalonControlMode(CANTalon::TalonControlMode::kSpeedMode);
//  m_frontRight.SetTalonControlMode(CANTalon::TalonControlMode::kSpeedMode);
//  m_backRight.SetTalonControlMode(CANTalon::TalonControlMode::kSpeedMode);
}


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

	//m_frontLeft.ConfigEncoderCodesPerRev(m_ppr);
	//m_backLeft.ConfigEncoderCodesPerRev(m_ppr);
	//m_frontRight.ConfigEncoderCodesPerRev(m_ppr);
	//m_backRight.ConfigEncoderCodesPerRev(m_ppr);
	//m_frontLeft.SetControlMode(CANTalon::ControlMode::kSpeed);
	//m_backLeft.SetControlMode(CANTalon::ControlMode::kSpeed);
	//m_frontRight.SetControlMode(CANTalon::ControlMode::kSpeed);
	//m_backRight.SetControlMode(CANTalon::ControlMode::kSpeed);
}


float MecanumDrive::AvgValue(int Motor, float Val)
{
	float f = 0;

	m_A[Motor][m_pos] = Val;

	for (int i = 0; i < kMaxSample; ++i)
	{
		f = m_A[Motor][i] + f;
	};

	m_pos++;

	if (m_pos > (kMaxSample - 1))
		m_pos = 0;

	return(f / kMaxSample);


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

	//frc::SmartDashboard::PutNumber("FL", m_frontLeft.GetEncVel());
	//frc::SmartDashboard::PutNumber("FR", m_frontRight.GetEncVel());


}

void MecanumDrive::DriveToAngleInit(float setpoint)
{
	init();

	SetInputRange(-180.0, 180.0);
	SetOutputRange(0.0, 1.0);
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
	PIDWrite(output);
}

double MecanumDrive::ReturnPIDInput()
{
	return m_input;
}

void MecanumDrive::SetInput(double input)
{
	m_input = input;
}

void MecanumDrive::PIDWrite(double output)
{
	m_rotationRate = output;

	std::cout << "Rotation Rate " << m_rotationRate << std::endl;
}

void MecanumDrive::DriveBL(double set)
{
	m_backLeft.Set(set);
	frc::SmartDashboard::PutNumber("BL", m_backLeft.GetSpeed());

}

void MecanumDrive::DriveBR(double set)
{
	m_backRight.Set(set);
	frc::SmartDashboard::PutNumber("BR", m_backRight.GetSpeed());
}

void MecanumDrive::DriveFL(double set)
{
	m_frontLeft.Set(set);
	frc::SmartDashboard::PutNumber("FL", m_frontLeft.GetSpeed());
}

void MecanumDrive::DriveFR(double set)
{
	m_frontRight.Set(set);
	frc::SmartDashboard::PutNumber("FR", m_frontRight.GetSpeed());

}

void MecanumDrive::BLData()
{
	frc::SmartDashboard::PutNumber("BL Speed", m_backLeft.GetSpeed());
	frc::SmartDashboard::PutNumber("BL Voltage", m_backLeft.GetOutputVoltage());
	frc::SmartDashboard::PutNumber("BL Current", m_backLeft.GetOutputCurrent());
	//frc::SmartDashboard::PutNumber("BL Current Avg.:", AvgValue(kBL, m_backLeft.GetOutputCurrent()));
}

void MecanumDrive::FLData()
{
	frc::SmartDashboard::PutNumber("FL Speed", m_frontLeft.GetSpeed());
	frc::SmartDashboard::PutNumber("FL Voltage", m_frontLeft.GetOutputVoltage());
	frc::SmartDashboard::PutNumber("FL Current", m_frontLeft.GetOutputCurrent());
	//frc::SmartDashboard::PutNumber("FL Current Avg.:", AvgValue(kFL, m_frontLeft.GetOutputCurrent()));
}

void MecanumDrive::FRData()
{
	frc::SmartDashboard::PutNumber("FR Speed", m_frontRight.GetSpeed());
	frc::SmartDashboard::PutNumber("FR Voltage", m_frontRight.GetOutputVoltage());
	frc::SmartDashboard::PutNumber("FR Current", m_frontRight.GetOutputCurrent());
	//frc::SmartDashboard::PutNumber("FR Current Avg.:", AvgValue(kFR, m_frontRight.GetOutputCurrent()));
}

void MecanumDrive::BRData()
{
	frc::SmartDashboard::PutNumber("BR Speed", m_backRight.GetSpeed());
	frc::SmartDashboard::PutNumber("BR Voltage", m_backRight.GetOutputVoltage());
	frc::SmartDashboard::PutNumber("BR Current", m_backRight.GetOutputCurrent());
	//frc::SmartDashboard::PutNumber("BR Current Avg.:", AvgValue(kBR, m_backRight.GetOutputCurrent()));
}
