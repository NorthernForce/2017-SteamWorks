#pragma once

#include <WPILib.h>

class SetFlashlight: public frc::Command
{
	public:
		SetFlashlight();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();

	private:
		bool m_IsFinished;
};


