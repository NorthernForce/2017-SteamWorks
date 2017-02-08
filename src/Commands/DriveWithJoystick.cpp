#include <Commands/DriveWithJoystick.h>
#include <iostream>

DriveWithJoystick::DriveWithJoystick()
{
	Requires(drive.get());
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute()
{
	float x = oi->GetDriverStick().GetLeftStickX();
	float y = oi->GetDriverStick().GetLeftStickY();
	float w = oi->GetDriverStick().GetRightStickX();

	frc::SmartDashboard::PutNumber("x: ", x);
	frc::SmartDashboard::PutNumber("y: ", y);
	frc::SmartDashboard::PutNumber("w: ", w);


	// Squaring inputs to make for smoother driving
//	x = pow(x, 2);
//	y = pow(y, 2);
//	w = pow(w, 2);

	drive->DriveMecanum(x, y, w);

	frc::SmartDashboard::PutString("Has driven?", "Yesss");

}

bool DriveWithJoystick::IsFinished() {return false;}

void DriveWithJoystick::End() {}

void DriveWithJoystick::Interrupted() {}
