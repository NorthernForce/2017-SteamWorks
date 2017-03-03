#include <Commands/SetIntake.h>
#include "../Robot.h"

SetIntake::SetIntake(bool mode) : m_IsFinished(false), m_mode(mode)
{
	Requires(&Robot::GetIntake());
}

void SetIntake::Initialize() {}

void SetIntake::Execute()
{
	Robot::GetIntake().SetIntake(m_mode);
	m_IsFinished = true;
}

bool SetIntake::IsFinished() {return m_IsFinished;}

void SetIntake::End() {}

void SetIntake::Interrupted() {}



