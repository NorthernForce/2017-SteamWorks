#include "AutoLeft.h"
#include "../../Robot.h"
#include "../DriveToAngle.h"

AutoLeft::AutoLeft()
{
	Requires(&Robot::GetDrive());
	Requires(&Robot::GetGyro());
	Requires(&Robot::GetIntake());
	Requires(&Robot::GetShooter());
	Requires(&Robot::GetUltra());

}

void AutoLeft::Initialize()
{}

void AutoLeft::Execute()
{

}

bool AutoLeft::IsFinished() {return false;}

void AutoLeft::End()
{

}

void AutoLeft::Interrupted()
{

}
