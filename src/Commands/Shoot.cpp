#include <Commands/Shoot.h>
#include "../Robot.h"

Shoot::Shoot() : m_IsFinished(false)
{
	Requires(&Robot::GetShooter());
}

void Shoot::Initialize()
{
	Robot::GetShooter().SetWaterWheels(true);

	Wait(2.0);

	Robot::GetShooter().SetShooter(true);
}

void Shoot::Execute()
{
	m_IsFinished = Robot::GetOI().GetDriverStick().GetRightBumper();
}

bool Shoot::IsFinished() {return m_IsFinished;}

void Shoot::End()
{
	Robot::GetShooter().SetWaterWheels(false);
	Robot::GetShooter().SetShooter(false);
}

void Shoot::Interrupted() {}



