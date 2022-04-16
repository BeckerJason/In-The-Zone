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

#pragma DebuggerWindows("debugStream")
#include"CompensationCheck.c";
#include "Functions.c";
task B()
{//VOLTAGE COMPENSATION-------------------------
	float PMult/*, SMult,Pin*/; //primary multiplier, secondary multiplier
	float MainBattery=nImmediateBatteryLevel; //Main Battery input
	float Batt=MainBattery/1000; //Division by 1000 to get true voltage value of battery
	PMult=PCheck(Batt); //Create Multiplier Based On Battery Voltage
	while(1)
	{
		int bL,	bR;
		//#### DRIVE BASE ########################################################################
		if(vexRT[Ch3] > 10 || vexRT[Ch4] > 10 || vexRT[Ch3] < -10 || vexRT[Ch4] < -10) //JOYSTICK DEADBAND
		{
			bL = vexRT[Ch3]*PMult + vexRT[Ch4]*PMult;		//Base Left Side
			bR = vexRT[Ch3]*PMult - vexRT[Ch4]*PMult;		//Base Right Side
		}
		else
		{
			bL=0;						//Stop Base Left Side
			bR=0;						//Stop Base Right Side
		}
		//#########################################################################################
		DoB(	bL,	bR); 				//Base Left Side, Base Right Side
	}
}

task A()
{//VOLTAGE COMPENSATION-------------------------
	float PMult/*, SMult,Pin*/; //primary multiplier, secondary multiplier
	float MainBattery=nImmediateBatteryLevel; //Main Battery input
	float Batt=MainBattery/1000; //Division by 1000 to get true voltage value of battery
	PMult=PCheck(Batt); //Create Multiplier Based On Battery Voltage
	while(1)
	{int l, cp, cm, mg, c, as;
		//~~~~ LIFT VALUES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		if(vexRT[Ch2] > 15 || vexRT[Ch2] < -15)
		{
			l = vexRT[Ch2]*PMult; //Lift Motors
		}
		else
		{
			l =0;	//Stop Lift Motors
		}
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		//++++ CLAW ARM PRESETS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		/*if (vexRT[Btn7U]==1)
		{
		cp=3;			//Claw Preset Up
		}
		else  if (vexRT[Btn7R==1)
		{
		cp=2;			//Claw Preset Horizontal
		}
		else  if (vexRT[Btn7D==1)
		{
		cp=1;			//Claw Preset Down*/
		cp=0; //TEMPORARY FOR CLAW PRESET
		if (vexRT[Btn6U]==1&&vexRT[Btn6D]==0)
		{
			cm=127*PMult;
		}
		else if (vexRT[Btn6D]==1&&vexRT[Btn6U]==0)
		{
			cm=-127*PMult;
		}
		else
		{
			cm=10;
		}
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


		//@@@@ MOBILE GOAL @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		if (vexRT[Btn8D]==1&&vexRT[Btn8U]==0)
		{
			mg=100*PMult; //Mobile Goal Up
		}
		else if (vexRT[Btn8U]==1&&vexRT[Btn8D]==0)
		{
			mg=-127*PMult; //Mobile Goal Down
		}
		else
		{
			mg=15*PMult;		//Value To Keep Mobile Goal Back
		}
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

		//#### CLAW############################################################
		if (vexRT[Btn5U]==1){c=1;} //Claw Close
		else{c=0;}//Claw Open
		//########################################################################
				//#### CLAW############################################################
		if (vexRT[Btn8L]==1){as=1;} //Claw Close
		else{as=0;}//Claw Open
		//########################################################################
		AoB(l, cp, cm, mg, c, PMult, as);	// Lift Motors, Claw Preset, Claw Motor, Mobile Goal, Claw, Auto Stack
	}
}
task main()
{SensorValue[enc]=0;
	startTask(B);
	startTask(A);
while(1){}

}
