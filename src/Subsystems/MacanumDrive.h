#ifndef MACANUM_DRIVE_H
#define MACANUM_DRIVE_H

#include <Commands/Subsystem.h>

#include <CANTalon.h>

class MacanumDrive: public frc::Subsystem {
public:
	MacanumDrive();
	void InitDefaultCommand() override;

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon fRWheel;
	CANTalon fLWheel;
	CANTalon rRWheel;
	CANTalon rLWheel;

};

#endif  // MACANUM_DRIVE_H
