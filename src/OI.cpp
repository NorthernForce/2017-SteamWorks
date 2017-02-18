#include "OI.h"
//#include "Commands/SetFlashlight.h"


#include <WPILib.h>

OI::OI() :
	m_DriverStick(kDriverStickPort),
	m_ManipulatorStick(kManipulatorStickPort) {}

void OI::init()
{
	//m_DriverStick.A.WhenPressed(new SetFlashlight());
}

FRCXboxJoystick& OI::GetDriverStick()
{
	return m_DriverStick;
}

Attack3Joystick& OI::GetManipulatorStick()
{
	return m_ManipulatorStick;
}

