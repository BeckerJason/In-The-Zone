void DebugCode(void)
{
	//GET 3 CONES//////////////////////////////////////////////////////////////////////
	for(int i = 0; i<3; i++)
	{
		//BRING LIFT DOWN
	while(SensorValue[LiftLimit]!=1)LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(-30);

		//BRING 4 BAR DOWN
		motor[roller] = 127;
		while(FBControl(0));


		while(MoveDist(5, 80, 2000, 1);

		motor[roller] = 30;

		//LIFT CONTROL
		startTask(anglePIDControl);
		pidRunning = 1;
		RequestedAngle = abs(SensorValue[LiEnc])+i*50;

		while(angleSentinel==1)wait1Msec(25);
		angleSentinel = 0;
		/////////////////////

		while(FBControl(1));
		intake(0);

		//TAKE OFF LIFT CONTROL//
		pidRunning = 0;
		stopTask(anglePIDControl);
		/////////////////////////

		/*
		//TAKE OFF LIFT CONTROL//
		pidRunning = 0;
		stopTask(anglePIDControl);
		/////////////////////////
		//BRING LIFT DOWN TO GRAB THE CONES!!
		while(SensorValue[LiftLimit]!=1)LiftPow(-127);
		SensorValue[LiEnc] = 0;
		LiftPow(-30);

		motor[roller] = 127;
		while(FBControl(0));




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
		*/
	}
	while(1)
	{KIllALL();
		wait1Msec(20);
	}

}
