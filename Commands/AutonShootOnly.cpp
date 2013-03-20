#include "AutonShootOnly.h"
#include "DeployShooter.h"
#include "DoNothing.h"
#include "ShootTimed.h"
#include "DriveForward.h"

AutonShootOnly::AutonShootOnly() {
	AddSequential(new DeployShooter());
	AddSequential(new DoNothing());
	//AddSequential(new DriveForward(12.0, 0.25));
	AddSequential(new ShootTimed());
}
