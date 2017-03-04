#include <Commands/Shoot.h>
#include "../Robot.h"

Shoot::Shoot() : m_IsFinished(false)
{
	Requires(&Robot::GetShooter());
}

void Shoot::Initialize()
{

}

void Shoot::Execute()
{
	double set = Robot::GetOI().GetManipulatorStick().GetAxis(frc::Joystick::AxisType::kZAxis);
	++set;
	set = set / 4;

	double shoot = Robot::GetOI().GetDriverStick().GetLeftTrigger();
	shoot += 0.5;

	Robot::GetShooter().SetWaterWheels(set);

	Robot::GetShooter().SetShooter(shoot);

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



