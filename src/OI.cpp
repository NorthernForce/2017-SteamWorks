#include "OI.h"
#include "Commands/SetFlashlight.h"
#include "Commands/DriveToAngle.h"
#include "Commands/DriveWithJoystick.h"


OI::OI() :
	m_DriverStick(kDriverStickPort),
	m_ManipulatorStick(kManipulatorStickPort) {}

void OI::init()
{
	m_DriverStick.A.WhenPressed(new SetFlashlight());
	m_DriverStick.B.WhenPressed(new DriveToAngle());
	m_DriverStick.X.WhenPressed(new DriveWithJoystick());
}

FRCXboxJoystick& OI::GetDriverStick()
{
	return m_DriverStick;
}

Attack3Joystick& OI::GetManipulatorStick()
{
	return m_ManipulatorStick;
}

