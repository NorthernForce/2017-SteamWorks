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
	double inputAngle = frc::SmartDashboard::GetNumber("Angle", 90.0);
	Robot::GetDrive().DriveToAngle(Robot::GetGyro().GetGyroObject(), float(inputAngle));
}

bool DriveToAngle::IsFinished() {return m_IsFinished;}

void DriveToAngle::End() {}

void DriveToAngle::Interrupted() {}
