#pragma once

#include <WPILib.h>
#include "Lib/Attack3Joystick.h"
#include "Lib/FRCXboxJoystick.h"

class OI
{
	public:
		OI();
		void init();
		FRCXboxJoystick& GetDriverStick();
		Attack3Joystick& GetManipulatorStick();

	private:
		FRCXboxJoystick m_DriverStick;
		Attack3Joystick m_ManipulatorStick;
};

