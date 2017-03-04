#pragma once

#include <WPILib.h>
#include "RobotMap.h"


class Ultrasonic: public Subsystem
{
	public:

		Ultrasonic();
		void init();
		void GetGyro();
		void Zero();
		float GetAngle();
		float GetDisplacement();
		AHRS* GetGyroObject();

	private:
		frc::Ultrasonic* m_ultra;

};




