
#pragma once
#include <WPILib.h>
#include "../Robotmap.h"
#include "Joystick.h"

/**
* @brief This class is the driver for the Logitech
* Attack 3 Joystick. This joystick is often used at
* competition to control the robot. This joystick
* is not deadband adjusted, as these joysticks do
* not seem to need deadband calibration.
*
* This class also contains JoystickButtons for all of the
* buttons that are available on the XBox joystick itself.
* These buttons can be assigned by calling
* <code>[stick].[button].WhenPressed()</code>.
*
* @author Arthur Lockman
*/


class Attack3Joystick: public Joystick
{
	public:
		Attack3Joystick(int port);
		float GetStickX();
		float GetStickY();
		float GetPOT();
		bool GetTrigger();
		bool GetButton2();
		bool GetButton3();
		bool GetButton4();
		bool GetButton5();
		bool GetButton6();
		bool GetButton7();
		bool GetButton8();
		bool GetButton9();
		bool GetButton10();
		bool GetButton11();
		//bool GetButton12();
		frc::JoystickButton Trigger;
		frc::JoystickButton Button2;
		frc::JoystickButton Button3;
		frc::JoystickButton Button4;
		frc::JoystickButton Button5;
		frc::JoystickButton Button6;
		frc::JoystickButton Button7;
		frc::JoystickButton Button8;
		frc::JoystickButton Button9;
		frc::JoystickButton Button10;
		frc::JoystickButton Button11;
		//frc::JoystickButton Button12;

	private:
		float Deadband(float input);
};


