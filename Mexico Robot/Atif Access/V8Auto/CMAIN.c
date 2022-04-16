#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    LineR,          sensorLineFollower)
#pragma config(Sensor, in2,    LineM,          sensorLineFollower)
#pragma config(Sensor, in3,    LineL,          sensorLineFollower)
#pragma config(Sensor, in4,    pot,            sensorPotentiometer)
#pragma config(Sensor, in7,    gyro,           sensorGyro)
#pragma config(Sensor, in8,    BackUpBattery,  sensorAnalog)
#pragma config(Sensor, dgtl1,  enc,            sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  claw,           sensorDigitalOut)
#pragma config(Sensor, dgtl4,  limit,          sensorTouch)
#pragma config(Sensor, dgtl5,  Lenc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  Renc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  Climit,         sensorTouch)
#pragma config(Sensor, dgtl10, IR,             sensorDigitalIn)
#pragma config(Sensor, dgtl11, IR2,            sensorTouch)
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
// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

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


void pre_auton()
{
  bStopTasksBetweenModes = true;
}

task autonomous()
{
	//!!!!!!!!!! CHECK VOLTAGES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	pr.mult=PCheck(nImmediateBatteryLevel/1000.0);
	se.mult=SCheck(SensorValue[BackUpBattery]/280.0);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//!!!!!!!!!! SET INITIAL X AND Y !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	initial.xval=1; //Initial X and Y set units of # of Tiles
	initial.yval=3;
	initial.angle=-450.0;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	clearDebugStream();
	resetMotorEncoder(rightArm1);
	resetMotorEncoder(leftArm1);
	SensorValue[I2C_2]=0;
	SensorValue[gyro]=0;
	///ALWAYS GYRO*0.973

	//##########   RECORD  ####################################################
	int record;
	if (SensorValue[Jumper]==1)
	{record=1;}
	else{	int record=0;}
	//########################################################################


	//*****************RESET GYRO***************************
	//Completely clear out any previous sensor readings by setting the port to "sensorNone"
	SensorType[gyro] = sensorNone;
	wait1Msec(1000);
	//Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
	SensorType[gyro] = sensorGyro;
	wait1Msec(2000);
	while(1)
	#include "TestAuto.c";
}

task usercontrol()
{
	//!!!!!!!!!! CHECK VOLTAGES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	pr.mult=PCheck(nImmediateBatteryLevel/1000.0);
	se.mult=SCheck(SensorValue[BackUpBattery]/280.0);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//!!!!!!!!!! SET INITIAL X AND Y !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	initial.xval=1; //Initial X and Y set units of # of Tiles
	initial.yval=3;
	initial.angle=-450.0;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	clearDebugStream();
	resetMotorEncoder(rightArm1);
	resetMotorEncoder(leftArm1);
	SensorValue[I2C_2]=0;
	SensorValue[gyro]=0;
	///ALWAYS GYRO*0.973

	//##########   RECORD  ####################################################
	int record;
	if (SensorValue[Jumper]==1)
	{record=1;}
	else{	int record=0;}
	//########################################################################


	//*****************RESET GYRO***************************
	//Completely clear out any previous sensor readings by setting the port to "sensorNone"
	SensorType[gyro] = sensorNone;
	wait1Msec(1000);
	//Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
	SensorType[gyro] = sensorGyro;
	wait1Msec(2000);
  while (1)
	{
		//#include "TestAuto.c";
#include "JuanDriverControl.c";
	}
}
