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
//	x = pow(x, 2);
//	y = pow(y, 2);
//	w = pow(w, 2);

	Robot::GetDrive().DriveMecanum(x, y, w);

	frc::SmartDashboard::PutString("Has driven?", "Yesss");

}

bool DriveWithJoystick::IsFinished() {return false;}

void DriveWithJoystick::End() {}

void DriveWithJoystick::Interrupted() {}
