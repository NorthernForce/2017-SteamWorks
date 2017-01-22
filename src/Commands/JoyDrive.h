#ifndef JOYDRIVE_H
#define JOYDRIVE_H

#include "../CommandBase.h"

class JoyDrive: public CommandBase {
public:
	JoyDrive();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};



#endif  // JOYDRIVE_H
