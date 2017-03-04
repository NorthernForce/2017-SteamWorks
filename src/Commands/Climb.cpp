#include <Commands/Climb.h>
#include "../Robot.h"

Climb::Climb() : m_IsFinished(false)
{
	Requires(&Robot::GetClimber());
}

void Climb::Initialize() {}

void Climb::Execute()
{
	Robot::GetClimber().SetClimber(6.0);

	if(Robot::GetClimber().GetVoltage() > 12)
	{
		Robot::GetClimber().SetClimber(2.0);
	}
}

bool Climb::IsFinished() {return m_IsFinished;}

void Climb::End()
{
	Robot::GetClimber().SetClimber(false);
}

void Climb::Interrupted()
{
	Robot::GetClimber().SetClimber(false);
}



