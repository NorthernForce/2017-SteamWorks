#include "Flashlight.h"
//#include "../Commands/SetFlashlight.h"



Flashlight::Flashlight() :
		frc::Subsystem("Flashlight"),
		m_itsLit(false),
		m_relay(0)
		{
			//m_relay = new Relay(1);
		}

Flashlight::~Flashlight()
{
	delete m_relay;
}

void Flashlight::InitDefaultCommand()
{
	//SetDefaultCommand(new SetFlashlight());
}

void Flashlight::init()
{
	if(!m_relay)
	{
		m_relay = new Relay(1);
	}

	m_relay->Set(frc::Relay::kForward);
	m_itsLit = true;
	m_relay->SetExpiration(0.1);
	m_relay->SetSafetyEnabled(false);
}

void Flashlight::Set(bool isOn)
{
	//init();

	//m_relay->Set(frc::Relay::kOn);
	//m_relay->SetExpiration(0.1);
	//m_relay->SetSafetyEnabled(false);

	if(!m_relay)
	{
		m_relay = new Relay(1);
	}


	if(isOn)
	{
		m_relay->Set(frc::Relay::kForward);
		m_itsLit = true;
	}

	else
	{
		m_relay->Set(frc::Relay::kOff);
		m_itsLit = false;

	}

}

bool Flashlight::GetItsLit()
{
	return m_itsLit;
}





