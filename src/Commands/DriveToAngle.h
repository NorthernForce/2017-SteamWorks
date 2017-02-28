#pragma once

#include <WPILib.h>

class DriveToAngle: public frc::Command
{
	public:
		DriveToAngle();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();

	private:
		bool m_IsFinished;
};

