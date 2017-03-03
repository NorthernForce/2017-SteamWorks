#include "Climber.h"


Climber::Climber() :
	Subsystem("Climber"),
	m_climber(kClimber) {}

void Climber::init()
{
	m_climber.SetControlMode(frc::CANSpeedController::kVoltage);
	m_climber.Set(0.0);
	m_climber.SetExpiration(0.5);
	m_climber.SetSafetyEnabled(false);
}

void Climber::SetClimber(double set)
{
	m_climber.Set(set);
}

double Climber::GetVoltage()
{
	return m_climber.GetBusVoltage();
}
