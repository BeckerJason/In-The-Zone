#pragma config(Sensor, in8,    BackUpBattery,  sensorAnalog)
#pragma config(Sensor, dgtl1,  enc,            sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  claw,           sensorDigitalOut)
#pragma config(Sensor, dgtl4,  limit,          sensorTouch)
#pragma config(Sensor, dgtl11, sonar,          sensorSONAR_inch)
#pragma config(Motor,  port1,           RM,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           L1,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           MG,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightArm1,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rightArm2,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftArm1,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftArm2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           ClawM,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           R1,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          LM,            tmotorVex393_HBridge, openLoop, reversed)

//#pragma DebuggerWindows("debugStream")
#include"CompensationCheck.c";
#include "Functions.c";
task main()
{
	SensorValue[enc]=0;
	while (1)
	{
		//#include "DriverControl.c";
#include "JuanDriverControl.c";
	}
}