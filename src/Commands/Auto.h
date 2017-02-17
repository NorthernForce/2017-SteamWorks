#pragma once

#include "../CommandBase.h"

class Auto: public CommandBase
{
	public:
		Auto();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;
};

