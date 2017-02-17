#include <Commands/Auto.h>

Auto::Auto()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Auto::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Auto::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Auto::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Auto::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Auto::Interrupted()
{

}
