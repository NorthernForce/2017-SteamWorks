#include <Commands/SetFlashlight.h>
#include "../Robot.h"

SetFlashlight::SetFlashlight() : m_IsFinished(false)
{
	Requires(&Robot::GetLight());
}

void SetFlashlight::Initialize() {}

void SetFlashlight::Execute()
{
	if(Robot::GetLight().GetItsLit())
	{
		Robot::GetLight().Set(false);
	}

	else if(!Robot::GetLight().GetItsLit())
	{
		Robot::GetLight().Set(true);
	}

	m_IsFinished = true;
}

bool SetFlashlight::IsFinished() {return m_IsFinished;}

void SetFlashlight::End() {}

void SetFlashlight::Interrupted() {}



