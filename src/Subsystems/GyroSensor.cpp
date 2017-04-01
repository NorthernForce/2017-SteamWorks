#include "GyroSensor.h"


GyroSensor::GyroSensor() :
	Subsystem("Gyro Sensor"),
	m_gyro(0) {}

void GyroSensor::init()
{
	m_gyro = new AHRS(frc::SerialPort::kMXP);
	Zero();
}

void GyroSensor::GetGyro()
{
	frc::SmartDashboard::PutNumber(  "Gyro_Yaw",              m_gyro->GetYaw());
	frc::SmartDashboard::PutNumber(  "Gyro_Pitch",            m_gyro->GetPitch());
	frc::SmartDashboard::PutNumber(  "Gyro_Roll",             m_gyro->GetRoll());
	frc::SmartDashboard::PutNumber(  "Velocity_X",           m_gyro->GetVelocityX() );
	frc::SmartDashboard::PutNumber(  "Velocity_Y",           m_gyro->GetVelocityY() );
	frc::SmartDashboard::PutNumber(  "Displacement_X",       m_gyro->GetDisplacementX() );
	frc::SmartDashboard::PutNumber(  "Displacement_Y",       m_gyro->GetDisplacementY() );
	frc::SmartDashboard::PutNumber("Displacement_Z", m_gyro->GetDisplacementZ());
}


void GyroSensor::Zero()
{
	m_gyro->ZeroYaw();
	m_gyro->Reset();
	m_gyro->ResetDisplacement();
}

float GyroSensor::GetAngle()
{
	return m_gyro->GetYaw();
}

float GyroSensor::GetDisplacementX()
{
	return m_gyro->GetDisplacementX();
}

float GyroSensor::GetDisplacementY()
{
	return m_gyro->GetDisplacementY();
}

float GyroSensor::GetDisplacementZ()
{
	return m_gyro->GetDisplacementZ();
}

AHRS* GyroSensor::GetGyroObject()
{
	return m_gyro;
}
