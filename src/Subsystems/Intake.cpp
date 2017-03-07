#include "Intake.h"


Intake::Intake() :
	Subsystem("Intake"),
	m_intake(kIntake) {}

void Intake::init()
{
	m_intake.Set(0.0);
}

void Intake::SetIntake(bool set)
{
	if(set)
	{
		m_intake.Set(-0.5);
	}

	else
	{
		m_intake.Set(0.0);
	}
}





