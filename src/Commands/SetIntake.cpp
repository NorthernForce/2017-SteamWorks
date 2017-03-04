#include <Commands/SetIntake.h>
#include "../Robot.h"

SetIntake::SetIntake() : m_IsFinished(false), m_mode(true)
{
	Requires(&Robot::GetIntake());
}

void SetIntake::Initialize() {}

void SetIntake::Execute()
{
	Robot::GetIntake().SetIntake(m_mode);
}

bool SetIntake::IsFinished() {return m_IsFinished;}

void SetIntake::End()
{
	Robot::GetIntake().SetIntake(0.0);
}

void SetIntake::Interrupted()
{
	Robot::GetIntake().SetIntake(0.0);
}



