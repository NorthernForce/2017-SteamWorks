#include "Shooter.h"


Shooter::Shooter() :
	Subsystem("Shooter"),
	m_shooter(kShooter),
	m_wheels(kWaterWheels) {}

void Shooter::init()
{
	m_shooter.Set(0.0);
	m_shooter.SetExpiration(0.5);
	m_shooter.SetSafetyEnabled(false);

	m_wheels.Set(0.0);
	m_wheels.SetExpiration(0.5);
	m_wheels.SetSafetyEnabled(false);
}

void Shooter::SetShooter(bool set)
{
	if(set)
	{
		m_shooter.Set(0.5);
	}

	else
	{
		m_shooter.Set(0.0);
	}
}

void Shooter::SetWaterWheels(bool set)
{
	if(set)
	{
		m_wheels.Set(0.5);
	}

	else
	{
		m_wheels.Set(0.0);
	}
}


