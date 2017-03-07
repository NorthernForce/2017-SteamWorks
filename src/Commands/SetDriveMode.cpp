#include <Commands/SetDriveMode.h>
#include "../Robot.h"

SetDriveMode::SetDriveMode() : m_IsFinished(false)
{
	Requires(&Robot::GetDrive());
}

void SetDriveMode::Initialize()
{
	Robot::GetDrive().SetDriveRelative(!Robot::GetDrive().GetIsDriveRelative());

	m_IsFinished = true;
}

void SetDriveMode::Execute() {}

bool SetDriveMode::IsFinished() {return m_IsFinished;}

void SetDriveMode::End() {}

void SetDriveMode::Interrupted() {}



