#include "AutonShootGatherAllShoot.h"
#include "DeployShooter.h"
#include "ShootTimed.h"
#include "RunGather.h"
#include "StopGather.h"
#include "RetractShooter.h"
#include "DriveForward.h"
#include "DoNothing.h"

AutonShootGatherAllShoot::AutonShootGatherAllShoot() {
	AddParallel(new DeployShooter());
	AddSequential(new DoNothing());
	AddSequential(new DriveForward(12.0, 0.25));
	AddSequential(new ShootTimed());
	AddParallel (new RunGather());
	AddSequential(new DriveForward(136.0, 0.5));
	AddSequential(new DriveForward(-136.0, 0.5));
	AddParallel (new StopGather());
	AddSequential(new ShootTimed());
}
