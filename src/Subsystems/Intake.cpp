#include "Intake.h"


Intake::Intake() :
	Subsystem("Intake"),
	m_intake(kIntake) {}

void Intake::init()
{
	m_intake.Set(0.0);
	m_intake.SetExpiration(0.5);
	m_intake.SetSafetyEnabled(false);
}

void Intake::SetIntake(bool set)
{
	if(set)
	{
		m_intake.Set(0.3);
	}

	else
	{
		m_intake.Set(0.0);
	}
}




