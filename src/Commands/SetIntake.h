#pragma once

#include <WPILib.h>

class SetIntake: public frc::Command
{
	public:
		SetIntake(bool mode);
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;

	private:
		bool m_IsFinished;
		bool m_mode;
};

