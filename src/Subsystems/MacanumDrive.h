#ifndef MACANUM_DRIVE_H
#define MACANUM_DRIVE_H

#include <Commands/Subsystem.h>

class MacanumDrive: public frc::Subsystem {
public:
	MacanumDrive();
	void InitDefaultCommand() override;

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
};

#endif  // MACANUM_DRIVE_H
