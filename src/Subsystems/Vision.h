#ifndef VISION_H
#define VISION_H

#include <Subsystems/Vision.h>
#include "Lib/PIXYCam.h"
#include "WPILib.h"

class Vision: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	PIXYCam* m_cam;
public:
	Vision();
	Block readPIXYCam();
	void InitDefaultCommand();
};

#endif
