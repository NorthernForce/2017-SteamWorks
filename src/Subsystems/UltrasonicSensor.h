#pragma once

#include <WPILib.h>
#include "RobotMap.h"


class UltrasonicSensor: public Subsystem
{
	public:

		UltrasonicSensor();
		void init();
		double GetUltra();

	private:
		frc::AnalogInput* m_ultra;
		frc::DigitalOutput* m_pinOutZero;
		frc::DigitalOutput* m_pinOutOne;

};




