#pragma once

#include <WPILib.h>

class Shoot: public frc::Command
{
	public:
		Shoot();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;

	private:
		bool m_IsFinished;
};

