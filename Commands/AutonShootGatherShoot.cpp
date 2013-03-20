#include "AutonShootGatherShoot.h"
#include "DeployShooter.h"
#include "ShootTimed.h"
#include "RunGather.h"
#include "StopGather.h"
#include "RetractShooter.h"
#include "DriveForward.h"
#include "DoNothing.h"

AutonShootGatherShoot::AutonShootGatherShoot() {
	AddParallel(new DeployShooter());
	AddSequential(new DoNothing());
	AddSequential(new DriveForward(12.0, 0.25));
	AddSequential(new ShootTimed());
	AddParallel(new RetractShooter());
	AddSequential(new DriveForward(36.0, 0.5));
	AddParallel(new DeployShooter());
	AddSequential(new DriveForward(100.0, 0.5));
	AddSequential(new DriveForward(-136.0, 0.5));
	AddSequential(new ShootTimed());
}
