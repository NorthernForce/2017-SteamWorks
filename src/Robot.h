#pragma once

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Subsystems/MecanumDrive.h"
#include "Subsystems/Flashlight.h"
#include "OI.h"
#include <WPILib.h>


class Robot: public frc::IterativeRobot
{
	public:

		Robot();
		virtual void RobotInit();
		virtual void DisabledPeriodic();
		virtual void AutonomousInit();
		virtual void AutonomousPeriodic();
		virtual void TeleopInit();
		virtual void TeleopPeriodic();
		virtual void TestPeriodic();

		static Robot& GetRobot();
		static MecanumDrive& GetDrive();
		static Flashlight& GetLight();
		static OI& GetOI();

	private:
		std::unique_ptr<frc::Command> autonomousCommand;
		frc::SendableChooser<frc::Command*> chooser;

		static Robot m_robotInstance;
		MecanumDrive m_drive;
		Flashlight m_light;
		OI m_oi;


};
