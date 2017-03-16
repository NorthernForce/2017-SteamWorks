#include "OI.h"
#include "Commands/DriveToAngle.h"
#include "Commands/SetIntake.h"
#include "Commands/Shoot.h"
#include "Commands/Unjam.h"
#include "Commands/Climb.h"
#include "Commands/SetDriveMode.h"
#include "Commands/Test.hpp"


OI::OI() :
	m_DriverStick(kDriverStickPort),
	m_ManipulatorStick(kManipulatorStickPort) {}

void OI::init()
{
	//m_DriverStick.A.WhenPressed(new SetFlashlight());
	m_DriverStick.B.WhenPressed(new DriveToAngle());
	m_DriverStick.LeftBumper.WhenPressed(new SetDriveMode());

	m_ManipulatorStick.Trigger.ToggleWhenPressed(new Unjam()); // shooter on and water wheels backward
	m_ManipulatorStick.Button2.ToggleWhenPressed(new Shoot());
	m_ManipulatorStick.Button3.ToggleWhenPressed(new SetIntake());
	m_ManipulatorStick.Button4.ToggleWhenPressed(new Climb());
	m_ManipulatorStick.Button5.ToggleWhenPressed(new Climb());

	m_ManipulatorStick.Button6.ToggleWhenPressed(new ATest(1));
	m_ManipulatorStick.Button7.ToggleWhenPressed(new ATest(2));
	m_ManipulatorStick.Button8.ToggleWhenPressed(new ATest(3));
	m_ManipulatorStick.Button9.ToggleWhenPressed(new ATest(4));
}

FRCXboxJoystick& OI::GetDriverStick()
{
	return m_DriverStick;
}

Attack3Joystick& OI::GetManipulatorStick()
{
	return m_ManipulatorStick;
}

