#include "Shooter.h"


Shooter::Shooter() :
	Subsystem("Shooter"),
	m_shooterRight(kShooterRight),
	m_shooterLeft(kShooterLeft),
	m_wheels(kWaterWheels) {}

void Shooter::init()
{
	m_shooterRight.Set(0.0);
	m_shooterRight.SetExpiration(0.5);
	m_shooterRight.SetSafetyEnabled(false);

	m_shooterRight.Set(0.0);
	m_shooterRight.SetExpiration(0.5);
	m_shooterRight.SetSafetyEnabled(false);

	m_wheels.Set(0.0);
}

void Shooter::SetShooter(bool set)
{
	if(set)
	{
		m_shooterRight.Set(0.5);
		m_shooterLeft.Set(0.5);
	}

	else
	{
		m_shooterRight.Set(0.0);
		m_shooterLeft.Set(0.0);
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



