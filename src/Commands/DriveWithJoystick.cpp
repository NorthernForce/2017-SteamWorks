#include <Commands/DriveWithJoystick.h>
#include "../Robot.h"
#include <iostream>

DriveWithJoystick::DriveWithJoystick()
{
	Requires(&Robot::GetDrive());
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute()
{
	float x = Robot::GetOI().GetDriverStick().GetLeftStickX();
	float y = Robot::GetOI().GetDriverStick().GetLeftStickY();
	float w = Robot::GetOI().GetDriverStick().GetRightStickX();

	frc::SmartDashboard::PutNumber("x: ", x);
	frc::SmartDashboard::PutNumber("y: ", y);
	frc::SmartDashboard::PutNumber("w: ", w);


	// Squaring inputs to make for smoother driving
	if(x < 0) { x = -pow(x, 2); }
	else { x = pow(x, 2); }

	if(y < 0) { y = -pow(x, 2); }
	else { y = pow(x, 2); }

	if(w < 0) { w = -pow(x, 2); }
	else { w = pow(x, 2); }

	Robot::GetDrive().DriveMecanum(x, y, w);
}

bool DriveWithJoystick::IsFinished() {return false;}

void DriveWithJoystick::End() {}

void DriveWithJoystick::Interrupted() {}
