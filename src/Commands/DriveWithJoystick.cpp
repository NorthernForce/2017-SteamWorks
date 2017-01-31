#include <Commands/DriveWithJoystick.h>

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

	// Squaring inputs to make for smoother driving
	x = pow(x, 2);
	y = pow(y, 2);
	w = pow(w, 2);

	drive->DriveMecanum(x, y, w);

	drive->RelayOn();
}

bool DriveWithJoystick::IsFinished() {return false;}

void DriveWithJoystick::End() {}

void DriveWithJoystick::Interrupted() {}
