#include "Gatherer.h"
#include "../Robotmap.h"
#include "../Commands/BackgroundGather.h"
Gatherer::Gatherer() : Subsystem("Gatherer") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	motor = RobotMap::gathererMotor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
void Gatherer::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Gatherer::DeployGather() {
	//deploy->Set(DoubleSolenoid::kForward);
}
void Gatherer::RetractGather() {
	//deploy->Set(DoubleSolenoid::kReverse);
}
