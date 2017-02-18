/*

#include "Flashlight.h"
#include "../Commands/SetFlashlight.h"


Flashlight::Flashlight() :
		frc::Subsystem("Flashlight"),
		m_itsLit(false)
		{
			m_relay = new Relay(1);
		}

void Flashlight::InitDefaultCommand()
{
	SetDefaultCommand(new SetFlashlight());
}

void Flashlight::init() {}

void Flashlight::Set(bool isOn)
{
	if(isOn)
	{
		m_relay->Set(frc::Relay::kForward);
		m_itsLit = true;
	}

	else
	{
		m_relay->Set(frc::Relay::kReverse);
		m_itsLit = false;

	}
}

bool Flashlight::GetItsLit()
{
	return m_itsLit;
}

*/



