#include "BackgroundDrive.h"
BackgroundDrive::BackgroundDrive() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void BackgroundDrive::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void BackgroundDrive::Execute() {
	Joystick *stick = Robot::oi->getDriveStick();
	if (Robot::drivetrain->leftMotorA->GetControlMode() != CANJaguar::kVoltage) {
			Robot::drivetrain->leftMotorA->ChangeControlMode(CANJaguar::kVoltage);
			Robot::drivetrain->leftMotorA->SetVoltageRampRate(48.0);
			Robot::drivetrain->leftMotorA->ConfigFaultTime(0.5);
			Robot::drivetrain->leftMotorA->EnableControl();
	}
	if (Robot::drivetrain->leftMotorB->GetControlMode() != CANJaguar::kVoltage) {
			Robot::drivetrain->leftMotorB->ChangeControlMode(CANJaguar::kVoltage);
			Robot::drivetrain->leftMotorB->SetVoltageRampRate(48.0);
			Robot::drivetrain->leftMotorB->ConfigFaultTime(0.5);
			Robot::drivetrain->leftMotorB->EnableControl();
	}
	if (Robot::drivetrain->rightMotorA->GetControlMode() != CANJaguar::kVoltage) {
			Robot::drivetrain->rightMotorA->ChangeControlMode(CANJaguar::kVoltage);
			Robot::drivetrain->rightMotorA->SetVoltageRampRate(48.0);
			Robot::drivetrain->rightMotorA->ConfigFaultTime(0.5);
			Robot::drivetrain->rightMotorA->EnableControl();
	}
	if (Robot::drivetrain->rightMotorB->GetControlMode() != CANJaguar::kVoltage) {
			Robot::drivetrain->rightMotorB->ChangeControlMode(CANJaguar::kVoltage);
			Robot::drivetrain->rightMotorB->SetVoltageRampRate(48.0);
			Robot::drivetrain->rightMotorB->ConfigFaultTime(0.5);
			Robot::drivetrain->rightMotorB->EnableControl();
	}
	Robot::drivetrain->drive->ArcadeDrive(stick, Joystick::kDefaultYAxis,
			                              stick, Joystick::kDefaultTwistAxis);
}
// Make this return true when this Command no longer needs to run execute()
bool BackgroundDrive::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void BackgroundDrive::End() {
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BackgroundDrive::Interrupted() {
	End();
}