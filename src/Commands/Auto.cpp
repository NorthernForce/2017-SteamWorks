#include <Commands/Auto.h>
#include "../Robot.h"

Auto::Auto()
{
	Requires(&Robot::GetDrive());
	Requires(&Robot::GetGyro());
	Requires(&Robot::GetIntake());
	Requires(&Robot::GetShooter());

}

void Auto::Initialize()
{

}

void Auto::Execute()
{

}

bool Auto::IsFinished() {return false;}

void Auto::End()
{

}

void Auto::Interrupted()
{

}
