#ifndef DONOTHING_H
#define DONOTHING_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
//this just blocks for specified time (in seconds)
class DoNothing: public Command {
public:
	double defaultDelay;
	double actualDelay;
	DoNothing(double time = 0.0);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
