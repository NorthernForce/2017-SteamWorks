#pragma once

#include <WPILib.h>

class AutoRight: public frc::Command
{
	public:
		AutoRight();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;
};

