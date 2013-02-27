#ifndef SHOOTTIMED_H
#define SHOOTTIMED_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ShootTimed: public Command {
public:
	double defaultTimeNeeded;
	ShootTimed(double timeNeeded = 0.0);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
