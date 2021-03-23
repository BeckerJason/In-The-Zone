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
int record;
#include "Functions.c"

void pre_auton()
{
  bStopTasksBetweenModes = true;
	#include "preAuto2.c"
}

task autonomous()
{
	while(1)
	#include "TestAuto.c";
}

task usercontrol()
{
  while (1)
		#include "JuanDriverControl.c";
}
