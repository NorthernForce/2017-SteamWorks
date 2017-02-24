#ifndef DRIVE_WITH_VISION_H
#define DRIVE_WITH_VISION_H

#include "CommandBase.h"
#include <Subsystems/Vision.h>
#include "WPILib.h"

class DriveWithVision: public CommandBase
{
public:
	DriveWithVision();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
