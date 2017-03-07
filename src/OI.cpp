#include "OI.h"
#include "Commands/SetFlashlight.h"
#include "Commands/DriveToAngle.h"
#include "Commands/SetIntake.h"
#include "Commands/Shoot.h"
#include "Commands/Unjam.h"
#include "Commands/Climb.h"
#include "Commands/SetDriveMode.h"


OI::OI() :
	m_DriverStick(kDriverStickPort),
	m_ManipulatorStick(kManipulatorStickPort) {}

void OI::init()
{
	//m_DriverStick.A.WhenPressed(new SetFlashlight());
	m_DriverStick.B.WhenPressed(new DriveToAngle());
	//m_DriverStick.X.ToggleWhenPressed(new SetIntake());
	//m_DriverStick.RightBumper.ToggleWhenPressed(new Shoot());
	m_DriverStick.LeftBumper.WhenPressed(new SetDriveMode());

	m_ManipulatorStick.Trigger.ToggleWhenPressed(new Unjam()); //aka shooter on
	m_ManipulatorStick.Button2.ToggleWhenPressed(new Shoot());
	m_ManipulatorStick.Button3.ToggleWhenPressed(new SetIntake());
	m_ManipulatorStick.Button4.ToggleWhenPressed(new Climb());
	m_ManipulatorStick.Button5.ToggleWhenPressed(new Climb());
}

FRCXboxJoystick& OI::GetDriverStick()
{
	return m_DriverStick;
}

Attack3Joystick& OI::GetManipulatorStick()
{
	return m_ManipulatorStick;
}

