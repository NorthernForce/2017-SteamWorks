#include "GyroIMU.h"
#include "../Robot.h"


GyroIMU::GyroIMU() : frc::Subsystem("Gyro"), m_gyro(0)
{
//	std::cout << "ctor start" << std::endl;
//
//	m_rotateToAngleRate = 0.0;
//
//	m_turnController = new frc::PIDController(kP, kI, kD, kF, m_gyro, this);
//	m_turnController->SetInputRange(-180.0,  180.0);
//	m_turnController->SetOutputRange(-1.0, 1.0);
//	m_turnController->SetAbsoluteTolerance(kToleranceDegrees);
//	m_turnController->SetContinuous(true);

	std::cout << "ctor end" << std::endl;

}

GyroIMU::~GyroIMU()
{
	delete m_gyro;
}

GyroIMU::GyroIMU(const GyroIMU& other) : frc::Subsystem("Gyro")
{
	std::cout << "copy ctor" << std::endl;

	if (this != &other)
	{
		m_gyro = new AHRS(frc::SPI::Port::kOnboardCS0);

	}
}

GyroIMU& GyroIMU::operator = (const GyroIMU& other)
{
	std::cout << "assign op" << std::endl;

	if (this != &other)
	{
		m_gyro = new AHRS(frc::SPI::Port::kOnboardCS0);
	}

	return *this;
}

void GyroIMU::InitDefaultCommand()
{
	//SetDefaultCommand(new DriveWithJoystick());
}

void GyroIMU::init()
{
	if(!m_gyro)
	{
		m_gyro = new AHRS(frc::SerialPort::kMXP);
	}

	m_gyro->Reset();

	std::cout << "init start" << std::endl;

	m_rotateToAngleRate = 0.0;

	m_turnController = new frc::PIDController(kP, kI, kD, kF, m_gyro, this);
	m_turnController->SetInputRange(-180.0,  180.0);
	m_turnController->SetOutputRange(-1.0, 1.0);
	m_turnController->SetAbsoluteTolerance(kToleranceDegrees);
	m_turnController->SetContinuous(true);

}

float GyroIMU::GetXDisplacement()
{
	float XDisplacement = m_gyro->GetDisplacementX();
	return XDisplacement;
}

float GyroIMU::GetYDisplacement()
{
	float YDisplacement = m_gyro->GetDisplacementY();
	return YDisplacement;
}

float GyroIMU::GetZDisplacement()
{
	float ZDisplacement = m_gyro->GetDisplacementZ();
	return ZDisplacement;
}

void GyroIMU::ResetGyro()
{
	m_gyro->Reset();
}

float GyroIMU::GetGyroAngle()
{
	float angle = m_gyro->GetAngle();
	return angle;
}

float GyroIMU::GetAngleX()
{
	float angleX = m_gyro->GetRoll();
	return angleX;
}

float GyroIMU::GetAngleY()
{
	float angleY = m_gyro->GetPitch();
	return angleY;
}

float GyroIMU::GetAngleZ()
{
	float angleZ = m_gyro->GetYaw();
	return angleZ;
}

void GyroIMU::RotateToAngle(float angle)
{
	bool turnRight;
	float currentAngle = m_gyro->GetYaw();

	std::cout << "Fun times Current Angle  " << currentAngle << std::endl;

	float oppAngle = angle - 180;
	if (oppAngle < currentAngle && currentAngle < angle)
	{
		m_turnController->SetSetpoint(angle);
		turnRight = true;
	}
	else
	{
		m_turnController->SetSetpoint(angle);
		turnRight = false;
	}

	float RotationRate;

	if ( turnRight )
	{
	     m_turnController->Enable();
	     RotationRate = m_rotateToAngleRate;
	}
	else
	{
	     m_turnController->Enable();
	     RotationRate = -m_rotateToAngleRate;
	}

	std::cout << "More fun times Rotation Rate " << RotationRate << std::endl;

	Robot::GetDrive().DriveMecanum(0.0, 0.0, RotationRate, float(m_gyro->GetAngle()));
}


