void BlueAuto3(void)
{
	//RESET////////////////
	motor[roller] = 50;
	while(FBControl(1));
	while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(0);


	//////////////////////
	/**/
	//**************PART 1; GO FOR MG AND PRE-LOADS***********************************************************************

	while(MoveDist(10, 65, 5000, 1))
	{
		//if(MGControl(1))
		//else	motor[MG] = -90;
	}
	motor[MG] = 0;

	while(MgControl(0))
	{
		//rightDrive(20);
		//leftDrive(20);
	}
	StopDrive();

	//while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	//SensorValue[LiEnc] = 0;
	//LiftPow(-30);


	//ALIGN WITH MID CONES
	//NO MOBILE GOAL ON
	pidTurn(47, 0.35, 0.08, 1.4, 3500);
	//pidTurn(45, 0.4, 0.1, 1.0, 3500);

	while(MoveDist(100,100, 5000, 1));
	while(MoveDist(5, 20, 2000, 1));
	while(MoveDist(-38,100, 5000, 1));


	//START BRINGING OUT MG BEFORE TURN TO FACE MG
		motor[MG] = -127;
		pidTurn(35, 0.4, 0.1, 1.0, 3500);
		while(MoveDist(15, 40, 5000, 1))
	{	if(MgControl(1)){}
		else
			motor[MG] = -90;
	}
	motor[MG] = 0;
	StopDrive();
	while(MgControl(0)){}


	///DROP THE CONE
	while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(-30);

	intake(0);
	wait1Msec(300);


	while(MoveDist(-25,100, 5000, 1)){}
	wait1Msec(250);
	pidTurn(110, 0.35, 0.05, 1.4, 3500);
		while(MoveDist(40,100, 5000, 1)){}
				pidTurn(40, 0.4, 0.1, 1.0, 3500);
		while(MoveDist(25, 40, 5000, 1)){}
			LiftPow(30);
				while(MgControl(1)){}
	//PULL OUT OF ZONE\\
	while(MoveDist(-10, 100, 5000, 1)){MGControl(0);LiftPow(-60);}
		//ALIGN PARALLEL TO LINE
	pidTurn(-90, 0.35, 0.05, 1.4, 3500);

	//GO TO TURN TOWARDS 2ND MG
	while(MoveDist(42, 100, 5000, 1));
	//ALIGN PARALLEL TO 2ND MG
	pidTurn(-44, 0.35, 0.08, 1.4, 3500);
	// GO FOR MG
	while(MoveDist(60, 50, 5000, 1))
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
	LiftPow(-40);

	SensorValue[REnc] = 0;
	SensorValue[LEnc] = 0;
	while(intake(1))
	{
		rightDrive(25+(abs(SensorValue[LEnc])-abs(SensorValue[REnc])));
		leftDrive(25-(abs(SensorValue[LEnc])-abs(SensorValue[REnc])));
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
	while(MoveDist(-70, 100, 5000, 1);
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

	while(MoveDist(-10, 80, 3000, 1))
	{
		motor[fb1] = -127;
		motor[fb2] = -127;
		motor[MG] = 127;
	}

	while(MGControl(0));


	while(1)wait1Msec(1000);/////////////////////////////////////////////////////////////
}
