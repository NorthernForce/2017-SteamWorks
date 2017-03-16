#include "UltrasonicSensor.h"


UltrasonicSensor::UltrasonicSensor() :
	Subsystem("UltrasonicSensor"),
	m_ultra(0) {}

void UltrasonicSensor::init()
{
	m_ultra = new frc::AnalogInput(kUltrasonic);
}

// Returns distance in feet
double UltrasonicSensor::GetUltra()
{
	if(!m_ultra)
	{
		m_ultra = new frc::AnalogInput(kUltrasonic);
	}

	return m_ultra->GetVoltage() / 0.0098;
}



