/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveForward.h"

DriveForward::DriveForward(double distance) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	setpoint = distance;
	Requires(CommandBase::drive);
}

// Called just before this Command runs the first time
void DriveForward::Initialize() {
	CommandBase::drive->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute() {
	CommandBase::drive->tankDrive(0.5,0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	return (CommandBase::drive->leftDistance() + CommandBase::drive->rightDistance())/2 > setpoint;
}

// Called once after isFinished returns true
void DriveForward::End() {
	CommandBase::drive->tankDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {

}
