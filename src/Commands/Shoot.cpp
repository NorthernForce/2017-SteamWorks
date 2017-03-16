#include <Commands/Shoot.h>
#include "../Robot.h"


double Shoot::m_wheels;
double Shoot::m_shoot;


Shoot::Shoot() : m_IsFinished(false)
{
	Requires(&Robot::GetShooter());
}

void Shoot::Initialize(){}

void Shoot::Execute()
{
	m_wheels = Robot::GetWheelSpeed();
	m_shoot = Robot::GetShootSpeed();

	if(m_shoot > 0.85)
	{
		m_shoot = 0.85;
	}

	Robot::GetShooter().SetWaterWheels(m_wheels);
	Robot::GetShooter().SetShooter(m_shoot);
	Robot::GetShooter().Output();


	// UNTESTED
	//Robot::GetShooter().CheckJam();
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



