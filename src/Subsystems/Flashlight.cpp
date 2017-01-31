#include "Flashlight.h"
#include "../Commands/SetFlashlight.h"


Flashlight::Flashlight() :
		frc::Subsystem("Flashlight"),
		m_relay(0),
		m_itsLit(false)
		{}

void Flashlight::InitDefaultCommand()
{
	SetDefaultCommand(new SetFlashlight());
}

void Flashlight::init()
{

}

void Flashlight::Set(bool isOn)
{
	if(isOn)
	{
		m_relay.Set(frc::Relay::kOn);
		m_itsLit = true;
	}

	else
	{
		m_relay.Set(frc::Relay::kOff);
		m_itsLit = false;

	}
}

bool Flashlight::GetItsLit()
{
	return m_itsLit;
}


