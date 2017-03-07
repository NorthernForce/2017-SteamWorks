#pragma once

#include <WPILib.h>

class AutoMiddle: public frc::Command
{
	public:
		AutoMiddle();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;
};

