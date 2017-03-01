#include <Commands/Auto.h>
#include <memory>

#include "Robot.h"

Robot Robot::m_robotInstance;
MecanumDrive Robot::m_drive;
//GyroSensor Robot::m_gyro;
Shooter Robot::m_shooter;
Intake Robot::m_intake;
Climber Robot::m_climber;
Flashlight Robot::m_light;


Robot::Robot() : autonomousCommand(), chooser()
{
	//m_light = new Relay(1);
}

Robot& Robot::GetRobot()
{
	return m_robotInstance;
}

MecanumDrive& Robot::GetDrive()
{
	return GetRobot().m_drive;
}

//GyroSensor& Robot::GetGyro()
//{
//	return GetRobot().m_gyro;
//}

Shooter& Robot::GetShooter()
{
	return GetRobot().m_shooter;
}

Intake& Robot::GetIntake()
{
	return GetRobot().m_intake;
}

Climber& Robot::GetClimber()
{
	return GetRobot().m_climber;
}

Flashlight& Robot::GetLight()
{
	return GetRobot().m_light;
}

OI& Robot::GetOI()
{
	return GetRobot().m_oi;
}

void Robot::RobotInit()
{
	chooser.AddDefault("Default Auto", new Auto());
	// chooser.AddObject("My Auto", new MyAutoCommand());
	frc::SmartDashboard::PutData("Auto Modes", &chooser);

	m_oi.init();
	m_drive.init();
	//m_gyro.init();
	m_shooter.init();
	m_intake.init();
	m_climber.init();
	m_light.init();
}

void Robot::DisabledPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

		/**
		 * This autonomous (along with the chooser code above) shows how to select
		 * between different autonomous modes using the dashboard. The sendable
		 * chooser code works with the Java SmartDashboard. If you prefer the
		 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
		 * GetString code to get the auto name from the text box below the Gyro.
		 *
		 * You can add additional auto modes by adding additional commands to the
		 * chooser code above (like the commented example) or additional comparisons
		 * to the if-else structure below with additional strings & commands.
		 */
void Robot::AutonomousInit()
{
	/* std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
	if (autoSelected == "My Auto") {
		autonomousCommand.reset(new MyAutoCommand());
	}
	else {
		autonomousCommand.reset(new ExampleCommand());
	} */

	autonomousCommand.reset(chooser.GetSelected());

	if (autonomousCommand.get() != nullptr)
	{
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.

	frc::CameraServer::GetInstance()->StartAutomaticCapture();
	if (autonomousCommand != nullptr)
	{
		autonomousCommand->Cancel();
	}
}

void Robot::TeleopPeriodic()
{

	//m_light->Set(frc::Relay::kForward);


	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()
{
	frc::LiveWindow::GetInstance()->Run();
}



START_ROBOT_CLASS(Robot)
