#pragma once

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Subsystems/MecanumDrive.h"
//#include "Subsystems/GyroSensor.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Flashlight.h"
#include "OI.h"
#include <WPILib.h>


class Robot: public frc::IterativeRobot
{
	public:

		Robot();

		static Robot& GetRobot();
		static MecanumDrive& GetDrive();
		//static GyroSensor& GetGyro();
		static Shooter& GetShooter();
		static Intake& GetIntake();
		static Climber& GetClimber();
		static Flashlight& GetLight();
		static OI& GetOI();



	private:

		std::unique_ptr<frc::Command> autonomousCommand;
		frc::SendableChooser<frc::Command*> chooser;

		static Robot m_robotInstance;
		MecanumDrive m_drive;
		//GyroSensor m_gyro;
		Shooter m_shooter;
		Intake m_intake;
		Climber m_climber;
		Flashlight m_light;

		OI m_oi;

		virtual void RobotInit();
		virtual void DisabledPeriodic();
		virtual void AutonomousInit();
		virtual void AutonomousPeriodic();
		virtual void TeleopInit();
		virtual void TeleopPeriodic();
		virtual void TestPeriodic();


};
