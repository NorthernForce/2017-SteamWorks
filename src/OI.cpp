#include "OI.h"
#include "Commands/SetFlashlight.h"
#include "Commands/DriveToAngle.h"
#include "Commands/SetIntake.h"
#include "Commands/Shoot.h"
#include "Commands/Climb.h"


OI::OI() :
	m_DriverStick(kDriverStickPort),
	m_ManipulatorStick(kManipulatorStickPort) {}

void OI::init()
{
	m_DriverStick.A.WhenPressed(new SetFlashlight());
	m_DriverStick.B.WhenPressed(new DriveToAngle());
	m_DriverStick.X.ToggleWhenPressed(new SetIntake(true));
	m_DriverStick.X.ToggleWhenPressed(new SetIntake(false));
	m_DriverStick.RightBumper.WhenPressed(new Shoot());
	m_DriverStick.LeftBumper.WhenPressed(new Climb());

}

FRCXboxJoystick& OI::GetDriverStick()
{
	return m_DriverStick;
}

Attack3Joystick& OI::GetManipulatorStick()
{
	return m_ManipulatorStick;
}

