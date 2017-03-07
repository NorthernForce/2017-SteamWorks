#include "UltrasonicSensor.h"


UltrasonicSensor::UltrasonicSensor() :
	Subsystem("UltrasonicSensor"),
	m_ultra(0) {}

void UltrasonicSensor::init()
{
	//m_ultra = new Ultrasonic(9);
}

// Returns distance in feet
double UltrasonicSensor::GetUltra()
{
	return m_ultra->GetRangeInches() / 12;
}



