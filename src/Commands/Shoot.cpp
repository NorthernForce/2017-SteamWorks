#include <Commands/Shoot.h>
#include "../Robot.h"

Shoot::Shoot() : m_IsFinished(false)
{
	Requires(&Robot::GetShooter());
	m_shoot=0;
	m_shooterOn=false;

}

void Shoot::Initialize()
{

}

void Shoot::Execute()
{

	double trigger;
	double set = Robot::GetOI().GetManipulatorStick().GetAxis(frc::Joystick::AxisType::kZAxis);
	++set;
	set = set / 4;

	trigger = Robot::GetOI().GetDriverStick().GetLeftTrigger();
	//shoot += 0.3;
	m_shoot=0.3;

// starting with shooter in slow mode, and setting it to higher when the trigger is pushed
	if (trigger > kTriggerThreshold && m_shoot==kShootLow)
	{
		m_shoot=kMaxShoot;
	}


	else if (trigger<kTriggerThreshold && m_shoot==kShootHigh)
	{
		m_shoot=kShootLow;
	}


	if (m_shoot>kMaxShoot)
		{
			m_shoot=kMaxShoot;
		}


	Robot::GetShooter().SetWaterWheels(set);

	Robot::GetShooter().SetShooter(m_shoot);

	Robot::GetShooter().Output();
}

bool Shoot::IsFinished() {return m_IsFinished;}

void Shoot::End()
{
	Robot::GetShooter().SetWaterWheels(0.0);
	Robot::GetShooter().SetShooter(0.0);
}

void Shoot::Interrupted()
{
	Robot::GetShooter().SetWaterWheels(0.0);
	Robot::GetShooter().SetShooter(0.0);
}



