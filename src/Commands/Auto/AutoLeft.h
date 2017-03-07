#pragma once

#include <WPILib.h>

class AutoLeft: public frc::Command
{
	public:
		AutoLeft();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;
};

