#pragma once

#include <WPILib.h>
#include "../RobotMap.h"

class Flashlight: public frc::Subsystem
{
	public:
		Flashlight();
		~Flashlight();
		void InitDefaultCommand();
		void Set(bool isOn);
		void init();
		bool GetItsLit();

	private:

		bool       m_itsLit;
		frc::Relay *m_relay;

};





