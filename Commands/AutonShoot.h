#ifndef AUTONSHOOT_H
#define AUTONSHOOT_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutonShoot: public Command {
public:
	double defaultTimeNeeded;
	AutonShoot(double timeNeeded = 0.0);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
