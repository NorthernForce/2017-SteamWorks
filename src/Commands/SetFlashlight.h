#pragma once

#include "../CommandBase.h"

class SetFlashlight: public CommandBase
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

