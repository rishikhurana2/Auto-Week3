/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/Turn.h>

Turn::Turn(double anglePoint, double turnVal) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::turn);
	setpoint = anglePoint;
	thisTurnVal = turnVal;
}

// Called just before this Command runs the first time
void Turn::Initialize() {
	CommandBase::turn->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute() {
	if (thisTurnVal < 0) {
		CommandBase::turn->tankDrive(0.25, 0.5);
	}
	if (thisTurnVal > 0) {
		CommandBase::turn->tankDrive(0.5, 0.25);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TurnLeft::IsFinished() {
	return (CommandBase::turn->getAngle() > setpoint);
}

// Called once after isFinished returns true
void TurnLeft::End() {
	CommandBase::turn->tankDrive(0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnLeft::Interrupted() {

}
