void DebugCode(void)
{
	BlueAuto1();
	//BlueAuto2();
	//RedAuto3();
	//BlueAuto3();

	//RESET////////////////
	motor[roller] = 50;
	while(FBControl(1));
	while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(0);
	///////////////////////
	//START BRINGING OUT MG BEFORE TURN TO FACE MG
	//motor[MG] = -127;
	//pidTurn(35, 0.4, 0.1, 1.0, 3500);
	//while(1)KIllALL();
	//BlueAuto3();

	//#include "Auto.c"
	//RESET////////////////
	motor[roller] = 30;
	while(FBControl(1));


	//////////////////////
	/**/
	//PRELOADS////////////////////////////
	//FIRST PRELOAD
	//LIFT CONTROL///////////////////
	startTask(anglePIDControl);
	pidRunning = 1;
	RequestedAngle = 270;

	while(angleSentinel==1)wait1Msec(25);
	angleSentinel = 0;
	////////////////////////////////////
	//FB DOWN
	while(FBControl(0));


	for(int i = 0; i<5;i++)
	{
		if(i == 0)
		{
		}
		else
		{
			while(FBControl(0));
			//LIFT CONTROL//
			startTask(anglePIDControl);
			pidRunning = 1;
			RequestedAngle = 300;

			while(angleSentinel==1)wait1Msec(25);
			angleSentinel = 0;
			////////////////////
		}

		motor[fb1] = 127;
		motor[fb2] = 127;
		//while(intake(1));
		motor[roller] = 127;
		wait1Msec(300);
		motor[roller] = 30;
		motor[fb1] = 0;
		motor[fb2] = 0;

		//STOP LIFT CONTROL//
		stopTask(anglePIDControl);
		pidRunning = 0;
		/////////////////////

		//RequestedAngle = 50;
		//while(angleSentinel==1)wait1Msec(25);
		//angleSentinel = 0;
		//LIFT UP UNTIL END OF STACK//
		while(SensorValue[IRLift] < 1000)	LiftPow(127);
		LiftPow(0);
		/////////////////////////////

		while(FBControl(1));

		LiftPow(-127);
		wait1Msec(250);
		LiftPow(0);

		if(i < 4)
		{
			LiftPow(127);
			intake(0);
			//wait1Msec(100);
			while(SensorValue[IRLift] < 1500)	LiftPow(127);
		}
		LiftPow(-20);

	}
	/*
	motor[roller] = 30;
	//RESET//////////////
	while(FBControl(1));
	//RING LIFT DOWN
	while(SensorValue[LiftLimit]!=1)LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(-30);
	////////////////

	//LIFT CONTROL
	//startTask(anglePIDControl);
	//pidRunning = 1;
	//RequestedAngle = 600;
	//while(angleSentinel==1)wait1Msec(25);
	//angleSentinel = 0;
	/////////////////////

	motor[roller] = 127;
	while(MoveDist(9, 100, 3000, 1))
	{
	LiftPow(127);
	}
	LiftPow(70);
	while(FBControl(0));
	LiftPow(0);
	intake(0);

	//Stop Lift Control
	stopTask(anglePIDControl);
	pidRunning = 0;
	///////////////////

	while(FBControl(1));
	while(MoveDist(-4, 100, 3000, 1))LiftPow(-127);

	//BRING LIFT DOWN!!
	while(SensorValue[LiftLimit]!=1)LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(-30);

	pidTurn(-60, 0.35, 0.05, 1.4, 3500);

	LiftPow(0);
	while(MoveDist(82, 80, 5000, 1))
	{
	MGControl(1);
	//else	motor[MG] = -90;
	}
	motor[MG] = 0;

	while(MGControl(0));

	//ALIGN WITH TILE
	while(SensorValue[LLine] < 1500 || SensorValue[RLine] < 1500)
	{
	if(SensorValue[LLine] < 1500)
	{
	leftDrive(-40);
	}
	else
	{
	leftDrive(30);
	}
	if(SensorValue[RLine] < 1500)
	{
	rightDrive(-40);
	}
	else
	{
	rightDrive(30);
	}
	wait1Msec(20);
	}
	StopDrive();

	while(MoveDist(-6, 80, 3000, 1));
	pidTurn(-88, 0.35, 0.05, 1.4, 3500);

	//RUN REST OF AUTO
#include "Auto.c"
	*/
	/*
	for(int i = 0; i<3; i++)
	{

	//BRING 4 BAR DOWN
	while(FBControl(0));

	SensorValue[REnc] = 0;
	SensorValue[LEnc] = 0;
	while(intake(1))
	{
	rightDrive(30+(abs(SensorValue[LEnc])-abs(SensorValue[REnc])));
	leftDrive(30-(abs(SensorValue[LEnc])-abs(SensorValue[REnc])));
	//wait1Msec(20);
	}
	StopDrive();

	if(i<2)
	{
	}
	else
	while(MoveDist(-10, 100, 2500, 1);

	//LIFT CONTROL
	startTask(anglePIDControl);
	pidRunning = 1;
	RequestedAngle = abs(SensorValue[LiEnc])+i*100;

	while(angleSentinel==1)wait1Msec(25);
	angleSentinel = 0;
	/////////////////////

	//4BAR UP
	while(FBControl(1));
	//DEPLOY CONE
	intake(0);
	}
	*/
}
