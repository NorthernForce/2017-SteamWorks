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

};




