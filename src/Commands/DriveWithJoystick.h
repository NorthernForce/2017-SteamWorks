#pragma once

#include "../CommandBase.h"

class DriveWithJoystick: public CommandBase
{
	public:
		DriveWithJoystick();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

