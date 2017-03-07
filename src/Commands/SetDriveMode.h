#pragma once

#include <WPILib.h>

class SetDriveMode: public frc::Command
{
	public:
		SetDriveMode();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;

	private:
		bool m_IsFinished;
};

