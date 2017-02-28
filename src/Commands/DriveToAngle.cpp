#include <Commands/DriveToAngle.h>
#include "../Robot.h"
#include <iostream>
#include <cmath>

DriveToAngle::DriveToAngle() : m_IsFinished(false)
{
	Requires(&Robot::GetDrive());
	Requires(&Robot::GetGyro());
}

void DriveToAngle::Initialize() {}

void DriveToAngle::Execute()
{
	float angle = Robot::GetOI().GetDriverStick().GetLeftTrigger();
	Robot::GetDrive().DriveToAngle(Robot::GetGyro().GetGyroObject(), angle);
}

bool DriveToAngle::IsFinished() {return Robot::GetDrive().AngleSet();}

void DriveToAngle::End()
{
	Robot::GetDrive().DriveToAngleEnd();
}

void DriveToAngle::Interrupted() {}
