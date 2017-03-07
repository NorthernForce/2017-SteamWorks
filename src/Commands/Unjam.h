#pragma once

#include <WPILib.h>

class Unjam: public frc::Command
{
	public:
		Unjam();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;

	private:

		bool m_IsFinished;
};

