#include <Commands/DriveToAngle.h>
#include "../Robot.h"
#include <iostream>
#include <cmath>

DriveToAngle::DriveToAngle() : m_IsFinished(false), m_angle(0.0)
{
	Requires(&Robot::GetDrive());
	Requires(&Robot::GetGyro());
}

void DriveToAngle::Initialize()
{
	m_angle = Robot::GetUserAngle();
	Robot::GetDrive().DriveToAngleInit(m_angle);
}

void DriveToAngle::Execute()
{
	Robot::GetDrive().SetInput(Robot::GetGyro().GetAngle());
	Robot::GetDrive().DriveToAngle(Robot::GetGyro().GetAngle());
}

bool DriveToAngle::IsFinished() {return m_IsFinished;}

void DriveToAngle::End() {}

void DriveToAngle::Interrupted() {}
