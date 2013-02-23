#ifndef IDLESHOOTER_H
#define IDLESHOOTER_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Idleshooter: public Command {
public:
	Idleshooter();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
