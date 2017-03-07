#include <Commands/Climb.h>
#include "../Robot.h"

Climb::Climb() : m_IsFinished(false)
{
	Requires(&Robot::GetClimber());
}

void Climb::Initialize() {}

void Climb::Execute()
{
	Robot::GetClimber().SetClimber(0.2);

	Wait(1.0);

	Robot::GetClimber().SetClimber(-1.0);

	Wait(3.0);

	m_IsFinished = true;
}

bool Climb::IsFinished() {return m_IsFinished;}

void Climb::End()
{
	Robot::GetClimber().SetClimber(0.0);
}

void Climb::Interrupted()
{
	Robot::GetClimber().SetClimber(0.0);
}



