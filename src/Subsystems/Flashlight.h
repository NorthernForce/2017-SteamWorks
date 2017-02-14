#pragma once

#include <WPILib.h>
#include "../RobotMap.h"

class Flashlight: public frc::Subsystem
{
	public:
		Flashlight();
		void InitDefaultCommand() override;
		void Set(bool isOn);
		void init();
		bool GetItsLit();

	private:

		frc::Relay *m_relay;
		bool       m_itsLit;
};


