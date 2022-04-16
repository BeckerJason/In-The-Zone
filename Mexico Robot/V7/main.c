#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    Line1,          sensorLineFollower)
#pragma config(Sensor, in2,    Line2,          sensorLineFollower)
#pragma config(Sensor, in3,    Line3,          sensorLineFollower)
#pragma config(Sensor, in8,    BackUpBattery,  sensorAnalog)
#pragma config(Sensor, dgtl1,  enc,            sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  claw,           sensorDigitalOut)
#pragma config(Sensor, dgtl4,  limit,          sensorTouch)
#pragma config(Sensor, dgtl5,  Lenc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  Renc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  Climit,         sensorTouch)
#pragma config(Sensor, dgtl10, IR,             sensorDigitalIn)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           RM,            tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           L1,            tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           MG,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightArm1,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port5,           rightArm2,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftArm1,      tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port7,           leftArm2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           ClawM,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           R1,            tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port10,          LM,            tmotorVex393_HBridge, openLoop, reversed, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//~~~~~~~~ MAIN.C V6 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#pragma DebuggerWindows("debugStream")
#include "CompensationCheck.c";


//VVVVVVVVVVVVVVVVVVVVVV Class Structure VVVVVVVVVVVVVVVV
typedef struct
{
	float mult;
}TVoltage;
TVoltage pr;
TVoltage se;

typedef struct
{
	float xval;
	float yval;
	float angle;
}TPositionRecord;
TPositionRecord initial;
//VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV


#include "Functions.c"

task main()
{
	//!!!!!!!!!! CHECK VOLTAGES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	pr.mult=PCheck(nImmediateBatteryLevel/1000.0);
	se.mult=SCheck(SensorValue[BackUpBattery]/280.0);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//!!!!!!!!!! SET INITIAL X AND Y !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
initial.xval=1.75; //Initial X and Y set units of # of Tiles
initial.yval=0.75;
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	clearDebugStream();
	SensorValue[enc]=0;


	//##########   RECORD  ####################################################
	int record=0;
	//########################################################################


	//*****************RESET GYRO***************************
	//Completely clear out any previous sensor readings by setting the port to "sensorNone"
	SensorType[in7] = sensorNone;
	wait1Msec(1000);
	//Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
	SensorType[in7] = sensorGyro;
	wait1Msec(2000);
	//*****************************************************************
	SensorValue[in7]=0;
	writeDebugStreamLine("%f   %f  %d  %d  %d",pr.mult, se.mult,SensorValue[Line1],SensorValue[Line2],SensorValue[Line3]);
	while(1)
	{	if(vexRT[Btn7D]==1)
	{float gyro=SensorValue[in7]/10;
		writeDebugStreamLine("%f",gyro%360);
		wait1Msec(200);
	}
	else{}
	if(vexRT[Btn7U]==1)
	{
	MoveToPosition(1,3,127,127,20,0);
	MoveToPosition(4,1,127,127,20,0);
}
else{}
}
	//Song();
//	while (1)
//	{
//		//#include "TestAuto.c";
//#include "JuanDriverControl.c";
//	}
}