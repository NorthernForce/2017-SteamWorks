#include "AutoMiddle.h"
#include "../../Robot.h"
#include "../DriveToAngle.h"
#include "../Shoot.h"

AutoMiddle::AutoMiddle()
{
	Requires(&Robot::GetDrive());
	Requires(&Robot::GetGyro());
	Requires(&Robot::GetIntake());
	Requires(&Robot::GetShooter());
	Requires(&Robot::GetUltra());
}

void AutoMiddle::Initialize()
{}

void AutoMiddle::Execute()
{
	while(Robot::GetGyro().GetDisplacementZ() < 2.0)
	{
		Robot::GetDrive().DriveMecanum(0.5, 0.0, 0.0, Robot::GetGyro().GetAngle());
	}

	Robot::GetDrive().DriveMecanum(0.0, 0.0, 0.0, 0.0);

	Wait(2.0);

	while(Robot::GetGyro().GetDisplacementZ() > 0.5)
	{
		Robot::GetDrive().DriveMecanum(-0.5, 0.0, 0.0, Robot::GetGyro().GetAngle());
	}

	Robot::GetDrive().DriveMecanum(0.0, 0.0, 0.0, 0.0);

	DriveToAngle();

	while(Robot::GetGyro().GetDisplacementY() < 3.0)
	{
		Robot::GetDrive().DriveMecanum(0.5, 0.0, 0.0, Robot::GetGyro().GetAngle());
	}

	Robot::GetDrive().DriveMecanum(0.0, 0.0, 0.0, 0.0);

	Robot::GetShooter().SetWaterWheels(1.0);
	Robot::GetShooter().SetShooter(0.85);


}

bool AutoMiddle::IsFinished() {return false;}

void AutoMiddle::End()
{

}

void AutoMiddle::Interrupted()
{

}
