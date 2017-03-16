#include <Commands/Climb.h>
#include "../Robot.h"

Climb::Climb() : m_IsFinished(false)
{
	Requires(&Robot::GetClimber());
}

void Climb::Initialize()
{
	//Robot::GetClimber().SetRelay();
}

void Climb::Execute()
{
	//double t = TimeSinceInitialized();

	//if(t < 1.0) {Robot::GetClimber().SetClimber(0.2);}

	//if(t > 1.0 && t < 6.0)
	//{
		Robot::GetClimber().SetClimber(-1.0);
	//}

	// while(!Robot::GetClimber().GetVel()) {}
	// while(Robot::GetUltrasonic().GetDistance() > 0.1) {}

	//if(t > 6.0)
	//{
	//}
}

bool Climb::IsFinished() {return m_IsFinished;}

void Climb::End()
{
	Robot::GetClimber().SetClimber(0.0);
	//Robot::GetClimber().SetVoltage();
}

void Climb::Interrupted() {Robot::GetClimber().SetClimber(0.0);}



