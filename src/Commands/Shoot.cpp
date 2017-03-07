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
	//m_wheels = Robot::GetOI().GetManipulatorStick().GetAxis(frc::Joystick::AxisType::kZAxis);
	//++m_wheels;
	//m_wheels = m_wheels / 4;

	//m_wheels = frc::SmartDashboard::GetNumber("Set Waterwheels", 0.3);

	m_wheels = Robot::GetWheelSpeed();

	//m_shoot = Robot::GetOI().GetDriverStick().GetLeftTrigger();
	//m_shoot += 0.5;

	//m_shoot = frc::SmartDashboard::GetNumber("Set Shooter", 0.85);

	m_shoot = Robot::GetShootSpeed();

	if(m_shoot > 0.85)
	{
		m_shoot = 0.85;
	}

	Robot::GetShooter().SetWaterWheels(m_wheels);

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



