#include <Commands/DriveToAngle.h>
#include "../Robot.h"
#include <iostream>
#include <cmath>

DriveToAngle::DriveToAngle() : m_IsFinished(false)
{
	Requires(&Robot::GetDrive());
}

void DriveToAngle::Initialize() {}

void DriveToAngle::Execute()
{
	double angle = frc::SmartDashboard::GetNumber("Angle", 90.0);
	Robot::GetDrive().DriveToAngle(float(angle));
}

bool DriveToAngle::IsFinished() {return Robot::GetDrive().IsOnTarget();}

void DriveToAngle::End()
{
	Robot::GetDrive().DriveToAngleEnd();
}

void DriveToAngle::Interrupted() {}
