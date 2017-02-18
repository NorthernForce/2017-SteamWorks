#include "Climber.h"


Climber::Climber() :
	Subsystem("Climber"),
	m_climber(kClimber) {}

void Climber::init()
{
	m_climber.Set(0.0);
	m_climber.SetExpiration(0.5);
	m_climber.SetSafetyEnabled(false);
}

void Climber::SetClimber(bool set)
{
	if(set)
	{
		m_climber.Set(0.3);
	}

	else
	{
		m_climber.Set(0.0);
	}
}
