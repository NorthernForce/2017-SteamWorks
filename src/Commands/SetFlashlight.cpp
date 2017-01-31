#include <Commands/SetFlashlight.h>

SetFlashlight::SetFlashlight() : m_IsFinished(false)
{
	Requires(light.get());
}

void SetFlashlight::Initialize() {}

void SetFlashlight::Execute()
{
	if(light.get()->GetItsLit())
	{
		light.get()->Set(false);
	}

	else if(!light.get()->GetItsLit())
	{
		light.get()->Set(true);
	}

	m_IsFinished = true;
}

bool SetFlashlight::IsFinished() {return m_IsFinished;}

void SetFlashlight::End() {}

void SetFlashlight::Interrupted() {}
