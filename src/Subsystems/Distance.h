#pragma once

#include <WPILib.h>
//#include "../Commands/RangeReadout.h"
#include <RobotMap.h>


class Distance: public SubsystemWithCommand<void>
{
	public:
		Distance(int analogChannel, int serialChannel, int onChannel);
///       analogChannel = 1, serialChannel = 5, onChannel = 1



		double GetRangeInInches() const;

	private:

		const float kMinVoltage;
		const float kVoltageRange;
		const float kMinDistance;
		const float kDistanceRange;
		mutable AnalogInput m_distanceChannel;

		DigitalOutput m_serialMode;

		DigitalOutput m_sensorOn;
};

