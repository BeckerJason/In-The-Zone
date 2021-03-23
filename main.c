#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in2,    LineM,          sensorLineFollower)
#pragma config(Sensor, in3,    LineL,          sensorLineFollower)
#pragma config(Sensor, in4,    pot,            sensorPotentiometer)
#pragma config(Sensor, in5,    LineR,          sensorLineFollower)
#pragma config(Sensor, in6,    IR2,            sensorAnalog)
#pragma config(Sensor, in7,    gyro,           sensorGyro)
#pragma config(Sensor, in8,    BackUpBattery,  sensorAnalog)
#pragma config(Sensor, dgtl1,  enc,            sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  claw,           sensorDigitalOut)
#pragma config(Sensor, dgtl4,  limit,          sensorTouch)
#pragma config(Sensor, dgtl5,  Lenc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  Renc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  Climit,         sensorTouch)
#pragma config(Sensor, dgtl10, IR,             sensorDigitalIn)
#pragma config(Sensor, dgtl12, Jumper,         sensorDigitalIn)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           RM,            tmotorVex393_HBridge, openLoop, driveRight, encoderPort, dgtl7)
#pragma config(Motor,  port2,           L1,            tmotorVex393_MC29, openLoop, driveLeft, encoderPort, dgtl5)
#pragma config(Motor,  port3,           MG,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightArm1,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port5,           rightArm2,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftArm1,      tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port7,           leftArm2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           ClawM,         tmotorVex393_MC29, openLoop, encoderPort, dgtl1)
#pragma config(Motor,  port9,           R1,            tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, dgtl7)
#pragma config(Motor,  port10,          LM,            tmotorVex393_HBridge, openLoop, reversed, driveLeft, encoderPort, dgtl5)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(45)
#pragma userControlDuration(75)

//~~~~~~~~ MAIN.C V10 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define DEBUG 0
int alliance = 4;
int AllianceColor=1;
int autonomousN = 5;
int NearOrFar;
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
#include "FullAuto.c"
#include "vex.c"
void pre_auton()
{	bStopTasksBetweenModes = true;
stopTask(autonomous);
#include "PreAuto.c";
}


task autonomous()
{C(1);
	clearDebugStream();
	//!!!!!!!!!! CHECK VOLTAGES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	pr.mult=PCheck(nImmediateBatteryLevel/1000.0);
	se.mult=SCheck(SensorValue[BackUpBattery]/280.0);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//!!!!!!!!!! SET INITIAL X AND Y !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	initial.xval=1.0; //Initial X and Y set units of # of Tiles
	initial.yval=3.0;
	initial.angle=-450.0;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	clearDebugStream();
	resetMotorEncoder(rightArm1);
	resetMotorEncoder(leftArm1);
	SensorValue[I2C_1]=0;
	SensorValue[I2C_2]=0;
	SensorValue[gyro]=0;
	///ALWAYS GYRO*0.973
	//#include "TestAuto.c";
	//#include "NearZone.c";
		//#include "RedNearZone.c";
#include "MainAuto.c"
}
task usercontrol()
{stopTask(autonomous);
	//!!!!!!!!!! CHECK VOLTAGES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	pr.mult=PCheck(nImmediateBatteryLevel/1000.0);
	se.mult=SCheck(SensorValue[BackUpBattery]/280.0);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//##########   RECORD  ####################################################
	int record;
	if (SensorValue[Jumper]==0)
	{record=1;}
	else{ record=0;}
	//######o##################################################################
	clearDebugStream();
#include "JuanDriverControl.c";

}
