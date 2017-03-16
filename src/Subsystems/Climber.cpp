#include "Climber.h"
#include <cmath>


Climber::Climber() :
	Subsystem("Climber"),
	m_climber(kClimber) {}
	//m_relay() {}

void Climber::init()
{
	//m_climber.Set(-0.1);

	m_climber.SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);

	//m_relay = new frc::Relay(0);

	//if(m_relay)
	//{
	//	m_relay->Set(frc::Relay::kReverse);
	//}
}

void Climber::SetClimber(double set)
{
	m_climber.Set(set);
}

double Climber::GetVoltage()
{
	return m_climber.GetBusVoltage();
}

int Climber::GetVel()
{
	return abs(m_climber.GetEncVel());
}

//void Climber::SetRelay()
//{
//	if(!m_relay)
//	{
//		m_relay = new frc::Relay(0);
//	}

//	m_relay->Set(frc::Relay::kForward);
//}

void Climber::SetVoltage()
{
	m_climber.SetControlMode(frc::CANSpeedController::kVoltage);

	m_climber.Set(-2.0);
}
