#include <Commands/Unjam.h>
#include "../Robot.h"


Unjam::Unjam() : m_IsFinished(false)
{
	Requires(&Robot::GetShooter());
}

void Unjam::Initialize(){}

void Unjam::Execute()
{
	Robot::GetShooter().SetWaterWheels(-0.2);

	Robot::GetShooter().SetShooter(0.85);

	Robot::GetShooter().Output();
}

bool Unjam::IsFinished() {return m_IsFinished;}

void Unjam::End()
{
	Robot::GetShooter().SetWaterWheels(0.0);
	Robot::GetShooter().SetShooter(0.0);
}

void Unjam::Interrupted()
{
	Robot::GetShooter().SetWaterWheels(0.0);
	Robot::GetShooter().SetShooter(0.0);
}



