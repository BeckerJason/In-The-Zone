//#include "RedAuto1Failsafe.c"
void RedAuto1(void)
{
	//RESET////////////////
	motor[roller] = 60;
	while(FBControl(1));
	while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(0);
	//////////////////////
	/**/
	//**************PART 1; GO FOR MG AND PRE-LOADS***********************************************************************

	while(MoveDist(69, 65, 5000, 1))
	{
		if(MGControl(1))
		else	motor[MG] = -90;
	}
	motor[MG] = 0;

	while(MgControl(0))
	{
		//rightDrive(20);
		//leftDrive(20);
	}
	StopDrive();

	while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(-30);

	intake(0);

	//ALIGN WITH PRE-LOAD STATION
	//FLIP
	pidTurn(20, 0.4, 0.1, 1.0, 3500);

	while(MoveDist(-18, 100, 5000, 1));
	//FLIPPED
	pidTurn(70, 0.35, 0.05, 1.4, 3500);

	while(MoveDist(3, 80, 2000, 1));

	//PRELOADS////////////////////////////
	//FIRST PRELOAD
	//LIFT CONTROL///////////////////
	startTask(anglePIDControl);
	pidRunning = 1;
	//INCREASED ANGLE FROM 300 TO 350
	RequestedAngle = 400;

	while(angleSentinel==1)wait1Msec(25);
	angleSentinel = 0;
	////////////////////////////////////
	//FB DOWN
	while(FBControl(0));


	for(int i = 0; i<5;i++)
	{
		motor[roller] = 127;
		if(i == 0)
		{
		}
		else
		{
			while(FBControl(0));
			//LIFT CONTROL//
			startTask(anglePIDControl);
			pidRunning = 1;
			//INCREASED ANGLE FROM 310 TO 400
			RequestedAngle = 400;

			while(angleSentinel==1)wait1Msec(25);
			angleSentinel = 0;
			////////////////////
		}

		motor[fb1] = 20;
		motor[fb2] = 20;
		//while(intake(1));
		motor[roller] = 127;
		wait1Msec(100);
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
	LiftPow(-30);
	//GET OUT OF THE WAY OF ANY CONE BEFORE TURNING
	while(MoveDist(-5, 100, 2000, 1));
	//TURN TO GO TO ZONE
	//TURN LESS THAN BEFORE (-105)
	//FLIPPED
	pidTurn(95, 0.35, 0.05, 1.4, 3500);
	//GO FORWARDS MORE THAN BEFORE (45.5) (58)
	while(MoveDist(60, 100, 5000, 1));
	wait1Msec(250);
	//BREAK/////
	//rightDrive(-5);
	//leftDrive(-5);
	//wait1Msec(150);
	//StopDrive();

	////////////

	//align TO ZONE
	//turn less than before (60)
	//FLIP
	pidTurn(-55, 0.37, 0.05, 1.2, 3500);

	while(MoveDist(24, 100, 5000, 0));
	//KILL LIFT BEFORE DEPLOING MG
	LiftPow(0);
	while(MGControl(1))
	{
		//motor[roller] = -127;
		if(SensorValue[MPot] > 500)
		{
			motor[fb1] = 100;
			motor[fb2] = 100;
		}
		LiftPow(0);
		rightDrive(50);
		leftDrive(50);
	}
	StopDrive();

	LiftPow(30);
	motor[roller] = -127;

	//PULL OUT OF MOBILE GOAL
	//
	while(MoveDist(-5, 80, 5000, 1))
	{
		motor[roller] = -127;
		motor[fb1] = -127;
		motor[fb2] = -127;
		motor[MG] = 127;
		//FBControl(1);
		//MGControl(0);
	}
	StopDrive();

	//BRING MG IN BEFORE LIFT
	while(MGControl(0));

	//BRING LIFT DOWN TO AVOID WHEELEES!!
	while(SensorValue[LiftLimit]!=1)LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(-30);

	motor[fb1] = -15;
	motor[fb2] = -15;
	motor[roller] = 0;
	motor[MG] = 0;

	//PULL OUT OF ZONE\\
	while(MoveDist(-12, 100, 5000, 1)){MGControl(0);LiftPow(-60);}

	///*************2nd PART GO FOR SECOND MG AND 3 CONES*********************************************

	//ALIGN PARALLEL TO LINE
	//FLIPPED
	pidTurn(90, 0.35, 0.05, 1.4, 3500);

	//GO TO TURN TOWARDS 2ND MG
	//CHANGED 23.5 TO 22
	while(MoveDist(22, 100, 5000, 1));
	//ALIGN PARALLEL TO 2ND MG
	LiftPow(0);
	motor[MG] = -127;
	//FLIPPED
	pidTurn(45, 0.35, 0.05, 1.4, 3500);
	// GO FOR MG
	while(MoveDist(60, 70, 5000, 1))
	{
		MGControl(1);
		LiftPow(30);
	}
	//BRING MOBILE GOAL IN
	while(MGControl(0));

	//BRING LIFT DOWN
	while(SensorValue[LiftLimit]!=1)LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(-30);

	/*
	//GET 3 CONES//////////////////////////////////////////////////////////////////////
	for(int i = 0; i<3; i++)
	{
	//BRING 4 BAR DOWN
	while(FBControl(0));
	//TAKE OFF LIFT CONTROL//
	pidRunning = 0;
	stopTask(anglePIDControl);
	/////////////////////////
	//BRING LIFT DOWN TO GRAB THE CONES!!
	while(SensorValue[LiftLimit]!=1)LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(-30);

	SensorValue[REnc] = 0;
	SensorValue[LEnc] = 0;
	while(intake(1))
	{
		rightDrive(30+(abs(SensorValue[LEnc])-abs(SensorValue[REnc]))*30/127);
		leftDrive(30-(abs(SensorValue[LEnc])-abs(SensorValue[REnc]))*30/127);
		//wait1Msec(20);
	}
	StopDrive();

	//FOR LAST CONE MOVE BACK B
	if(i<2)
	{
	}
	else
		while(MoveDist(-10, 100, 2500, 1);
	/////////////////////////////

	//LIFT CONTROL
	startTask(anglePIDControl);
	pidRunning = 1;
	RequestedAngle = abs(SensorValue[LiEnc])+i*80;

	while(angleSentinel==1)wait1Msec(25);
	angleSentinel = 0;
	/////////////////////

	//4BAR UP
	while(FBControl(1));
	//DEPLOY CONE
	intake(0);
	}
	*/
	//GO TO DEPLOY 2ND MG//////////////////
	//SINGLE TURN
	//DECREASED DISTANCE FROM -65 TO 60 (60 TO 58)
	while(MoveDist(-58, 100, 5000, 1);
	//FLIPPED
	//-135 CHANGED TO 145
	pidTurn(-145, 0.35, 0.05, 1.4, 3500);
	//while(MoveDist(-10, 100, 5000, 1);
	//pidTurn(90, 0.35, 0.05, 1.4, 3500);

	LiftPow(0);
	while(MGControl(1))
	{
		rightDrive(40);
		leftDrive(40);
		if(SensorValue[MPot] > 1000)
		{
			motor[fb1] = 30;
			motor[fb2] = 30;
		}
}

	StopDrive();

	LiftPow(30);
	motor[roller] = -127;
	//DEPLOY MG
	while(MoveDist(-10, 80, 3000, 1))
	{
		motor[fb1] = -127;
		motor[fb2] = -127;
		motor[MG] = 127;
	}

	while(MGControl(0));

	KIllALL();
	while(1)wait1Msec(1000);;/////////////////////////////////////////////////////////////
}
