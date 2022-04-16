#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, in3,    LLine,          sensorLineFollower)
#pragma config(Sensor, in4,    RLine,          sensorLineFollower)
#pragma config(Sensor, in5,    BLine,          sensorLineFollower)
#pragma config(Sensor, in7,    POT,            sensorPotentiometer)
#pragma config(Sensor, in8,    BackUpBattery,  sensorAnalog)
#pragma config(Sensor, dgtl1,  piston,         sensorDigitalOut)
#pragma config(Sensor, dgtl2,  MGlimit,        sensorTouch)
#pragma config(Sensor, dgtl3,  thrower,        sensorDigitalOut)
#pragma config(Sensor, dgtl4,  throwerIN,      sensorDigitalOut)
#pragma config(Sensor, dgtl5,  MGlimitD,       sensorTouch)
#pragma config(Sensor, dgtl6,  Claw,           sensorDigitalOut)
#pragma config(Sensor, dgtl10, IR,             sensorDigitalIn)
#pragma config(Sensor, dgtl11, IR2,             sensorDigitalIn)
#pragma config(Sensor, I2C_1,  Rencoder,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  Lencoder,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           leftDriveFrontMID, tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           powerAB,       tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftDriveBack, tmotorVex393TurboSpeed_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port5,           leftMG,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightMG,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightDriveBack, tmotorVex393TurboSpeed_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port8,           powerCD,       tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           rightDriveFrontMID, tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          ConeGrab,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//BEST RUN pr0.937 se0.897
//				pr 8.39  SE 8.76

//V11

//(998.22/v)/271
#pragma DebuggerWindows("debugStream")

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(45)
#pragma userControlDuration(75)

#define DEBUG 1
///////////////////////////BEGIN INCLUDED FILES
int alliance = 4;
int autonomousN = 5;
int AutoRun = 0;
int Encoders = 0;
#include "CompensationCheck.c";
//VVVVVVVVVVVVVVVVVVVVVV Class Structure VVVVVVVVVVVVVVVV
typedef struct
{
	float mult;
}TVoltage;
TVoltage pr;
TVoltage se;

//VVVVVVVVVVVVVVVVVVVVVV Class Structure VVVVVVVVVVVVVVVV
#include "vex.c"
#include "functions.c"



task VoltageCheck()
{while(1)
	{
		//!!!!!!!!!! CHECK VOLTAGES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		pr.mult=PCheck(nImmediateBatteryLevel/1000.0);
		se.mult=SCheck(SensorValue[BackUpBattery]/280.0);
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		wait1Msec(2000);
	}
}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the auto\nomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
	SensorType[in1] = sensorNone;
	wait1Msec(1000);
	//Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
	SensorType[in1] = sensorGyro;
	wait1Msec(2000);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
#include "ArcTurn.c";
#include "Double Pickup Auto.c";
task autonomous()
{clearTimer(T4);
	//startTask(VoltageCheck);
	clearDebugStream();

	//!!!!!!!!!! CHECK VOLTAGES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	pr.mult=PCheck(nImmediateBatteryLevel/1000.0);
	se.mult=SCheck(SensorValue[BackUpBattery]/280.0);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	writeDebugStreamLine("%f",timer4);
	startTask(MidRightAuto);
	while(1){}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


task usercontrol()
{	stopTask(autonomous);
	startTask(VoltageCheck);
	float Loffset, Roffset, speed,dir;
	int ddir=1;
	while (1)
	{
#include "Driver.c";
	}
}
