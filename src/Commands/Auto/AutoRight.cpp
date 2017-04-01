#include "AutoRight.h"
#include "../../Robot.h"
#include "../DriveToAngle.h"

AutoRight::AutoRight()
{
	Requires(&Robot::GetDrive());
	Requires(&Robot::GetGyro());
	Requires(&Robot::GetIntake());
	Requires(&Robot::GetShooter());
	Requires(&Robot::GetUltra());

}

void AutoRight::Initialize()
{}

void AutoRight::Execute()
{
	double t = TimeSinceInitialized();

	Robot::GetDrive().SetDriveRelative(false);

	if(t < 1.3)
	{
		Robot::GetDrive().DriveMecanum(0.0, 0.5, 0.0, 0.0);
	}

	if(t > 1.3 && t < 2.8)
	{
		Robot::GetDrive().DriveMecanum(0.0, 0.0, 0.5, 0.0);
	}

	if(t > 2.8 && t < 3.4)
	{
		Robot::GetDrive().DriveMecanum(0.0, 0.5, 0.0, 0.0);
	}

	if(t > 3.4)
	{
		Robot::GetDrive().DriveMecanum(0.0, 0.0, 0.0, 0.0);
	}
}

bool AutoRight::IsFinished() {return false;}

void AutoRight::End()
{

}

void AutoRight::Interrupted()
{

}
