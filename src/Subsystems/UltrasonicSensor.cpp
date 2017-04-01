#include "UltrasonicSensor.h"


UltrasonicSensor::UltrasonicSensor() :
	Subsystem("UltrasonicSensor"),
	m_ultra(0),
	m_pinOutZero(0),
	m_pinOutOne(0) {}

void UltrasonicSensor::init()
{
	m_ultra = new frc::AnalogInput(kUltrasonic);
	m_pinOutZero = new frc::DigitalOutput(0);
	m_pinOutOne = new frc::DigitalOutput(1);

	m_pinOutZero->DisablePWM();
	m_pinOutOne->DisablePWM();

	m_pinOutZero->Set(true);
	m_pinOutOne->Set(true);
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



