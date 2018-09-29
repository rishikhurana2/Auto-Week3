/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Turn.h"
#include "../RobotMap.h"

Turn::Turn() : Subsystem("ExampleSubsystem") {
	left(new TalonSRX(LEFTMOTOR)), right(new TalonSRX(RIGHTMOTOR)), gyro(new ADXRS450_Gyro())
}

void Turn::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
double Turn::Limit(double num, double max) {
	if (num > max)
		return max;

	if (num < -max)
		return -max;

	return num;
}
double Turn::getAngle() {
	double angle = gyro->GetAngle();
	//-180 to 180
	while (angle > 180) {
		angle -= 360;
	}
	while (angle < -180) {
		angle += 360;
	}
	return angle;
}
void Turn::gyroReset() {
	gyro->Calibrate();
}
void Turn::gyroCalibrate() {
	gyro->Calibrate();
}
void Turn::tankDrive(double leftVal, double rightVal) {
	left->Set(ControlMode::PercentOutput, Turn::Limit(-leftVal, 1.0));
	right->Set(ControlMode::PercentOutput, Turn::Limit(-rightVal, 1.0));
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
