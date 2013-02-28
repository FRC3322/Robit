#ifndef BACKGROUNDHOLDCAMERA_H
#define BACKGROUNDHOLDCAMERA_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class BackgroundHoldCamera: public Command {
public:
	BackgroundHoldCamera();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
