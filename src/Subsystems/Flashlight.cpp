#include "Flashlight.h"
//#include "../Commands/SetFlashlight.h"
#include <iostream>



Flashlight::Flashlight() :
		frc::Subsystem("Flashlight"),
		m_itsLit(false),
		m_relay(0)
		{
			//m_relay = new Relay(1);
		}

Flashlight::Flashlight(const Flashlight& other) :
		frc::Subsystem("Flashlight")
{
	std::cout << "Copy constructor has been called" << std::endl;

	if(this != &other)
	{
		m_itsLit = other.m_itsLit;
		m_relay = 0;
	}
}

Flashlight& Flashlight::operator =(const Flashlight& other)
{
	std::cout << "Assignment operator has been called" << std::endl;

	if(this != &other)
	{
		m_itsLit = other.m_itsLit;
		m_relay = 0;
	}

	return *this;
}

Flashlight::~Flashlight()
{
	delete m_relay;

	std::cout << "Our relay is in a better place now" << std::endl;
}

void Flashlight::InitDefaultCommand()
{
	//SetDefaultCommand(new SetFlashlight());
}

void Flashlight::init()
{

	m_relay = new Relay(1);

	std::cout << "Initialized from Flashlight::init()" << std::endl;


	m_relay->Set(frc::Relay::kForward);
	m_itsLit = true;
	//m_relay->SetExpiration(0.1);
	//m_relay->SetSafetyEnabled(false);
}

void Flashlight::Set(bool turnOn)
{
	//init();

	//m_relay->Set(frc::Relay::kOn);
	//m_relay->SetExpiration(0.1);
	//m_relay->SetSafetyEnabled(false);

	if(!m_relay)
	{
		m_relay = new Relay(1);

		m_relay->Set(frc::Relay::kForward);
		m_itsLit = true;

		std::cout << "Initialized in Flashlight::Set()" << std::endl;
	}


	if(turnOn)
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





