#pragma once

#include "../Robot.h"
#include <WPILib.h>

class ATest: public frc::Command
{
	public:
		ATest(int status) :
			m_IsFinished(false),
			m_status(status)
		{
			Requires(&Robot::GetDrive());
		}

		void Initialize() override {}
		void Execute() override
		{
			if(m_status == 1)
			{
				Robot::GetDrive().DriveFL(1);
			}

			if(m_status == 2)
			{
				Robot::GetDrive().DriveFR(1);
			}

			if(m_status == 3)
			{
				Robot::GetDrive().DriveBL(1);
			}

			if(m_status == 4)
			{
				Robot::GetDrive().DriveBR(1);
			}


		}

		bool IsFinished() override
		{
			return m_IsFinished;
		}

		void End() override
		{
			Robot::GetDrive().DriveFL(0.0);
			Robot::GetDrive().DriveFR(0.0);
			Robot::GetDrive().DriveBL(0.0);
			Robot::GetDrive().DriveBR(0.0);
		}

		void Interrupted() override
		{
			Robot::GetDrive().DriveFL(0.0);
			Robot::GetDrive().DriveFR(0.0);
			Robot::GetDrive().DriveBL(0.0);
			Robot::GetDrive().DriveBR(0.0);
		}


	private:

		static double m_wheels;
		static double m_shoot;

		bool m_IsFinished;
		int m_status;
};

