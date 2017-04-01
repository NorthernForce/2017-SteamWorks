#include <Commands/DriveWithJoystick.h>
#include "../Robot.h"
#include <iostream>
#include <cmath>

DriveWithJoystick::DriveWithJoystick()
{
	Requires(&Robot::GetDrive());
	Requires(&Robot::GetGyro());
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute()
{
	float x = -Robot::GetOI().GetDriverStick().GetLeftStickX();
	float y = Robot::GetOI().GetDriverStick().GetLeftStickY();
	float w = Robot::GetOI().GetDriverStick().GetRightStickX();
	float g = Robot::GetGyro().GetAngle();

	//if (abs(x) < 0.05) x = 0.0;
	//if (abs(y) < 0.05) y = 0.0;
	//if (abs(w) < 0.05) w = 0.0;
	//if (abs(g) < 0.05) g = 0.0;

	/*
	if(abs(x) > 0.2)
	{
		Robot::GetDrive().InitEncoders();
	}

	else
	{
		Robot::GetDrive().DisableEncoders();
	}
	*/

	frc::SmartDashboard::PutNumber("x: ", x);
	frc::SmartDashboard::PutNumber("y: ", y);
	frc::SmartDashboard::PutNumber("w: ", w);

	Robot::GetDrive().FRData();
	Robot::GetDrive().FLData();
	Robot::GetDrive().BRData();
	Robot::GetDrive().BLData();


	// Squaring inputs to make for smoother driving

	//if(x < 0) { x = -pow(x, 2); }
	//else { x = pow(x, 2); }

	//if(y < 0) { y = -pow(y, 2); }
	//else { y = pow(y, 2); }

	//if(w < 0) { w = -pow(w, 2); }
	//else { w = pow(w, 2); }


	Robot::GetDrive().DriveMecanum(x, y, w, g);
}

bool DriveWithJoystick::IsFinished() {return false;}

void DriveWithJoystick::End() {}

void DriveWithJoystick::Interrupted() {}
