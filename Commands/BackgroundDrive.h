
#ifndef BACKGROUNDDRIVE_H
#define BACKGROUNDDRIVE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class BackgroundDrive: public Command {
public:
	BackgroundDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
