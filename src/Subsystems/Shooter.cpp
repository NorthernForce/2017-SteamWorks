#include "Shooter.h"


Shooter::Shooter() :
	Subsystem("Shooter"),
	m_shooterRight(kShooterRight),
	m_shooterLeft(kShooterLeft),
	m_wheels(kWaterWheels) {}

void Shooter::init()
{
	m_shooterRight.Set(0.0);
	m_shooterLeft.Set(0.0);
	m_wheels.Set(0.0);

	m_shooterRight.SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_shooterLeft.SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_wheels.SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
}

void Shooter::SetShooter(double set)
{
	m_shooterRight.Set(set);
	m_shooterLeft.Set(set);
}

void Shooter::SetWaterWheels(double set)
{
	m_wheels.Set(set);
}

void Shooter::Output()
{
	frc::SmartDashboard::PutNumber("Right Shooter", m_shooterRight.GetEncVel());
	frc::SmartDashboard::PutNumber("Left Shooter", m_shooterLeft.GetEncVel());
}

void Shooter::CheckJam()
{
	double encVel = m_wheels.GetEncVel();

	if(encVel < 5)
	{
		m_wheels.Set(0.0);
	}

}

double Shooter::GetCurrent()
{
	return m_wheels.GetOutputCurrent();
}
