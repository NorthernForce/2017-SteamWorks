#pragma once

#include <WPILib.h>

class Auto: public frc::Command
{
	public:
		Auto();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;
};

