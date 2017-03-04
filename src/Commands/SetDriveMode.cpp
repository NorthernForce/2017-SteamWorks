#include <Commands/SetDriveMode.h>
#include "../Robot.h"

SetDriveMode::SetDriveMode(bool mode) : m_mode(mode),
										m_IsFinished(true)
{
	Requires(&Robot::GetDrive());
}

void SetDriveMode::Initialize()
{
	Robot::GetDrive().SetDriveRelative(m_mode);
}

void SetDriveMode::Execute() {}

bool SetDriveMode::IsFinished() {return m_IsFinished;}

void SetDriveMode::End() {}

void SetDriveMode::Interrupted() {}



