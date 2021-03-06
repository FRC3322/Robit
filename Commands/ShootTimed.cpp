#include "ShootTimed.h"
ShootTimed::ShootTimed(double timeNeeded) {
	defaultTimeNeeded = timeNeeded;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void ShootTimed::Initialize() {
	Robot::shooter->StartSpinning();
	SetTimeout((defaultTimeNeeded == 0.0) ? SmartDashboard::GetNumber("AutonShootDuration") : defaultTimeNeeded);
}
// Called repeatedly when this Command is scheduled to run
void ShootTimed::Execute() {
	Robot::shooter->ContinueShooting();
}
// Make this return true when this Command no longer needs to run execute()
bool ShootTimed::IsFinished() {
	// TODO detect when the frisbees are gone and stop shooting before the timeout.
	return IsTimedOut();
}
// Called once after isFinished returns true
void ShootTimed::End() {
	Robot::shooter->StopShooting();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootTimed::Interrupted() {
	End();
}
