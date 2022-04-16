#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  piston,         sensorDigitalOut)
#pragma config(Sensor, dgtl2,  MGlimit,         sensorTouch)
#pragma config(Sensor, I2C_1,  Rencoder,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  Lencoder,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           leftDriveFrontMID, tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           powerAB,       tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftDriveBack, tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           leftMG,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightMG,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightDriveBack, tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           powerCD,       tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           rightDriveFrontMID, tmotorVex393TurboSpeed_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma DebuggerWindows("debugStream")

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(45)
#pragma userControlDuration(75)

#define DEBUG 1
///////////////////////////BEGIN INCLUDED FILES
int alliance = 4;
int autonomousN = 5;
#include "vex.c"
#include "functions.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
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

task autonomous()
{clearDebugStream();
#include "auto.c";
while(1){/*Do nothing*/}
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
{int mgPOS=0;
stopTask(autonomous);
	while (true)
	{
		#include "drivercontrol.c";
	}
}
