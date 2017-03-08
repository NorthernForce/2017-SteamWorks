#pragma once

#include "WPILib.h"
#include "AHRS.h"
#include "../RobotMap.h"


class GyroIMU : public frc::Subsystem, public PIDOutput
{
	public:
		GyroIMU();
		~GyroIMU();
		GyroIMU(const GyroIMU&);
		GyroIMU& operator = (const GyroIMU&);
		void init();
		void InitDefaultCommand();
		float GetXDisplacement();
		float GetYDisplacement();
		float GetZDisplacement();
		float GetAngleX();
		float GetAngleY();
		float GetAngleZ();
		void ResetGyro();
		float GetGyroAngle();
		void RotateToAngle(float angle);

		virtual void PIDWrite(double output)
		{
		     m_rotateToAngleRate = output;

		     std::cout << "PIDWrite  " << output << std::endl;
		}


	private:
		AHRS *m_gyro;
		PIDController *m_turnController;

		double m_rotateToAngleRate;

};
