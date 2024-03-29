void BlueAuto2(void)
{
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
	LiftPow(50);
	while(FBControl(0));
	LiftPow(0);
	intake(0);

	//Stop Lift Control
	stopTask(anglePIDControl);
	pidRunning = 0;
	///////////////////

	while(FBControl(1));
	while(MoveDist(-10, 100, 3000, 1))LiftPow(-127);
	//WAIT FOR WHEELY TO STOP
	wait1Msec(250);

	//BRING LIFT DOWN!!
	while(SensorValue[LiftLimit]!=1)LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(-20);

	//pidTurn(-58, 0.35, 0.05, 1.4, 3500);
	//2 TURNS
	pidTurn(-90, 0.35, 0.05, 1.4, 3500);
	while(MoveDist(20, 80, 5000, 1));
	pidTurn(45, 0.35, 0.05, 1.4, 3500);
	//BRING LIFT UP TO NOT JAM MG
	LiftPow(30);
	while(MoveDist(72, 65, 5000, 1))
	{
		if(MGControl(1))
		else	motor[MG] = -90;
	}


	//BING MG IN
	while(MGControl(0));
	//LIFT DOWN
	while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(-30);

	//ALIGN WITH PRE-LOAD STATION
	pidTurn(-20, 0.4, 0.1, 1.0, 3500);

	while(MoveDist(-18, 100, 5000, 1));

	pidTurn(-70, 0.35, 0.05, 1.4, 3500);

	while(MoveDist(3, 80, 2000, 1));
	/*
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
	*/

	//PRELOADS////////////////////////////
	//FIRST PRELOAD
	//LIFT CONTROL///////////////////
	startTask(anglePIDControl);
	pidRunning = 1;
	RequestedAngle = 300;

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
			RequestedAngle = 310;

			while(angleSentinel==1)wait1Msec(25);
			angleSentinel = 0;
			////////////////////
		}

		motor[fb1] = 127;
		motor[fb2] = 127;
		//while(intake(1));
		motor[roller] = 127;
		wait1Msec(200);
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

	/////////////////////////////////////////////////////
	LiftPow(-30);

	//GET OUT OF THE WAY OF ANY CONE BEFORE TURNING
	while(MoveDist(-5, 100, 2000, 1));
	//TURN TO GO TO ZONE
	//TURN LESS THAN BEFORE (-105)
	pidTurn(-95, 0.35, 0.05, 1.4, 3500);
	//GO FORWARDS MORE THAN BEFORE (45.5)
	while(MoveDist(58, 100, 5000, 1));
	wait1Msec(150);
	//BREAK/////
	//rightDrive(-5);
	//leftDrive(-5);
	//wait1Msec(150);
	//StopDrive();

	////////////

	//align TO ZONE
	//turn less than before (60)
	pidTurn(55, 0.37, 0.05, 1.2, 3500);

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
	pidTurn(-90, 0.35, 0.05, 1.4, 3500);

	//GO TO TURN TOWARDS 2ND MG
	while(MoveDist(23.5, 100, 5000, 1));
	//ALIGN PARALLEL TO 2ND MG
	LiftPow(0);
	motor[MG] = -127;
	pidTurn(-45, 0.35, 0.05, 1.4, 3500);
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
	while(MoveDist(-65, 100, 5000, 1);
	pidTurn(135, 0.35, 0.05, 1.4, 3500);
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
