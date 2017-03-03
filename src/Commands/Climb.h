//775pro lock at 2v with power spike or ultrasonic or light sensor?

#pragma once

#include <WPILib.h>

class Climb: public frc::Command
{
	public:
		Climb();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;

	private:
		bool m_IsFinished;
};

