#include "AutoRight.h"
#include "../../Robot.h"
#include "../DriveToAngle.h"

AutoRight::AutoRight()
{
	Requires(&Robot::GetDrive());
	Requires(&Robot::GetGyro());
	Requires(&Robot::GetIntake());
	Requires(&Robot::GetShooter());
	Requires(&Robot::GetUltra());

}

void AutoRight::Initialize()
{}

void AutoRight::Execute()
{

}

bool AutoRight::IsFinished() {return false;}

void AutoRight::End()
{

}

void AutoRight::Interrupted()
{

}
