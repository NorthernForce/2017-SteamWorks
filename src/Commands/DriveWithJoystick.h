#pragma once

#include <WPILib.h>

class DriveWithJoystick: public frc::Command
{
	public:
		DriveWithJoystick();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

