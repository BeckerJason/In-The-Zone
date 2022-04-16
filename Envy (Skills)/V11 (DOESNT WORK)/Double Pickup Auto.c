task MidRightAuto();
task MidLeftAuto();
task FarLeftAuto();
task FarRightAuto();



task MidRightAuto()
{
	SensorValue[Claw]=0;
	startTask(POTTop);
	M(34,75,1);//(float dist, int vel, int MobileGoal)
	startTask(MGUpAuto);//First MID MG RIGHT pickup
	M(32,50,1);
	stopTask(POTStall);
	motor[ConeGrab]=-127;
	M(16, 60, 0);
	SensorValue[Claw]=1;
	startTask(POTTop);
	wait1Msec(300);
	//M(1, 60, 1);
	startTask(PistonUpAuto);//Second MID MG RIGHT pickup
	//M(3, 60, 0);

	////Comment out
	//T(30,50);
	//wait1Msec(200);
	//M(21,70,0);
	//wait1Msec(200);
	//T(-30,50);//lined up to far zone
	///////////////////
	ArcTurn(55,11,'f','l');
	ArcTurn(55,11,'f','r');

	wait1Msec(700);

	M(10,100,1);
	ForwardToPole(45);
	//wait1Msec(100);//shortened from 200
	startTask(MGDown);
	wait1Msec(100);//THIS MUST STAY
	M(-22,70,0);//2 scored
	wait1Msec(100);
	T(90,60);
	wait1Msec(100);
	M(14,60,0);
	wait1Msec(100);
	T(90,60);
	wait1Msec(100);
	M(-8,60,1);
	wait1Msec(300);
	startTask(MidLeftAuto);
	stopTask(MidRightAuto);
}






task MidLeftAuto()
{
	motor[rightMG] = 30;////These lines make sure the MG is Down
	motor[leftMG] = 30;///// Here too
	M(14, 75, 1);//(float dist, int vel, int MobileGoal)
	stopTask(POTStall);
	SensorValue[Claw] = 1;
	motor[ConeGrab] = 127;
	M(20, 75, 1);//(float dist, int vel, int MobileGoal)
	startTask(MGUpAuto);//First MID MG RIGHT pickup
	M(10, 50, 1);
	SensorValue[Claw] = 0;
	startTask(POTTop);
	M(29, 50, 1);
	stopTask(POTTop);
	stopTask(POTStall);
	motor[ConeGrab] = -127;
	M(14, 60, 0);
	SensorValue[Claw] = 1;
	stopTask(POTStall);
	startTask(POTTop);
		wait1Msec(300);
	//M(1, 60, 1);
	startTask(PistonUpAuto);//Second MID MG RIGHT pickup

		//M(3, 60, 0);
	////Comment out
	//T(30,50);
	//wait1Msec(200);
	//M(21,70,0);
	//wait1Msec(200);
	//T(-30,50);//lined up to far zone
	///////////////////
	ArcTurn(55, 11, 'f', 'l');
	ArcTurn(55, 11, 'f', 'r');


	wait1Msec(700);//shortened from 700
	M(10, 100, 1);
	ForwardToPole(45);
	//wait1Msec(100);//shortened from 200
	startTask(MGDown);
	wait1Msec(100);//THIS MUST STAY
	M(-24, 70, 0);//4 scored


				  //T(105,70);
				  //M(-2,70,1);
				  ////T(90,70);
				  ////M(-12,75,0);
				  ////T(15,70);
	T(105, 60);
	M(-20, 100, 1);
	BackUpWall();
	startTask(FarLeftAuto);
	stopTask(MidLeftAuto);
}





task FarLeftAuto()
{
	///////////////////////////////Code to grab 5&6 MG////////////////////////////////
	M(6, 50, 0);
	wait1Msec(100);
	T(90, 75);
	motor[rightMG] = 30;////These lines make sure the MG is Down
	motor[leftMG] = 30;///// Here too
					   ///////////Move to get second mobile goals
	wait1Msec(100);
	M(5, 70, 1);
	RLineTrack(60);
	wait1Msec(50);
	motor[rightMG] = 0;////These lines make sure the MG stops
	motor[leftMG] = 0;///// Here too
	LineTrack(30, 0);
	M(12, 60, 0);
	//startTask(MGUpAuto);
	//wait1Msec(500);

	////////////////////////AFTER GRABBING MG GRAB CONE AND NEXT MG
	////////NEW CODE////////

	stopTask(POTStall);
	SensorValue[Claw] = 1;
	motor[ConeGrab] = 127;
	wait1Msec(600);//shortened from 800
	M(5, 60, 0);
	SensorValue[Claw] = 0;
	wait1Msec(100);//shortened from 200
	startTask(POTTop);
	startTask(MGUpAuto);
	//while(SensorValue[MGlimit]==0){}
	wait1Msec(1000);
	SensorValue[in1] = 0;

	//////////////Code For Turning To Grab MG On Side
	T(-80, 100);
	wait1Msec(100);
	LineTrack(30, 1);
	motor[rightDriveBack] = -50;
	motor[powerCD] = -50;
	motor[rightDriveFrontMID] = -50;
	motor[leftDriveBack] = -50;
	motor[powerAB] = -50;
	motor[leftDriveFrontMID] = -50;
	wait1Msec(100);
	motor[rightDriveBack] = 0;
	motor[powerCD] = 0;
	motor[rightDriveFrontMID] = 0;
	motor[leftDriveBack] = 0;
	motor[powerAB] = 0;
	motor[leftDriveFrontMID] = 0;
	//T(25,60);


	TrackMG(1);
	TrackMG(0);
	TrackMG(1);
	motor[rightDriveBack] = -50;
	motor[powerCD] = -50;
	motor[rightDriveFrontMID] = -50;
	motor[leftDriveBack] = 50;
	motor[powerAB] = 50;
	motor[leftDriveFrontMID] = 50;
	wait1Msec(100);
	motor[rightDriveBack] = 0;
	motor[powerCD] = 0;
	motor[rightDriveFrontMID] = 0;
	motor[leftDriveBack] = 0;
	motor[powerAB] = 0;
	motor[leftDriveFrontMID] = 0;


	wait1Msec(100);
	MGM(11, 50, 0);
	stopTask(POTStall);
	motor[ConeGrab] = -127;
	M(5, 60, 1);							//////////While claw coming down holding cone moving forward stack on second mg
	motor[ConeGrab] = 0;
	//wait1Msec(100);
	SensorValue[Claw] = 1;	//drop cone
	wait1Msec(100);
	startTask(POTTop);
	wait1Msec(400);
	M(1, 60, 1);
	SensorValue(piston) = 1;
	wait1Msec(100);
	T(-35, 120);
	wait1Msec(100);
	M(8, 70, 1);
	//wait1Msec(100);
	//	T(-10,100);
	//wait1Msec(100);
	//////NEW CODE/////
	////////////////////FACING THE SCORING ZONE
	LineTrack(40, 1);


	////Move to Scoring zone
	MGM(7, 70, 1);
	MGM(10, 100, 1);
	M(8, 35, 1);
	///////////////////////////////////
	ArcTurn(55, 9, 'f', 'r');
	ArcTurn(55, 9, 'f', 'l');



	T(35, 60);
	M(1, 50, 1);
	//ForwardToPole(25);
	M(10, 100, 1);
	ForwardToPole(60);
	//wait1Msec(100);//shortened from 200
	startTask(MGDown);
	wait1Msec(100);//THIS MUST STAY
	M(-22, 70, 0);//6 scored
	wait1Msec(100);//6 scored//////////////////////////5 AND 6 MG SCORED//////////////////////////////////////////////////

	T(90, 70);
	M(-30, 100, 1);
	T(25, 60);
	BackUpWall();
	startTask(FarRightAuto);
	stopTask(FarLeftAuto);
}






task FarRightAuto()
{
	///////////////////////////////Code to grab 5&6 MG////////////////////////////////
	M(6, 50, 0);
	wait1Msec(100);
	T(90, 75);
	motor[rightMG] = 30;////These lines make sure the MG is Down
	motor[leftMG] = 30;///// Here too
					   ///////////Move to get second mobile goals
	wait1Msec(100);
	M(5, 70, 1);
	RLineTrack(60);
	wait1Msec(50);
	motor[rightMG] = 0;////These lines make sure the MG stops
	motor[leftMG] = 0;///// Here too
	LineTrack(30, 0);
	M(12, 60, 0);
	//startTask(MGUpAuto);
	//wait1Msec(500);

	////////////////////////AFTER GRABBING MG GRAB CONE AND NEXT MG
	////////NEW CODE////////

	stopTask(POTStall);
	SensorValue[Claw] = 1;
	motor[ConeGrab] = 127;
	wait1Msec(600);//shortened from 800
	M(5, 60, 0);
	SensorValue[Claw] = 0;
	wait1Msec(100);//shortened from 200
	startTask(POTTop);
	startTask(MGUpAuto);
	//while(SensorValue[MGlimit]==0){}
	wait1Msec(1000);
	SensorValue[in1] = 0;

	//////////////Code For Turning To Grab MG On Side
	T(-80, 100);
	wait1Msec(100);
	LineTrack(30, 1);
	motor[rightDriveBack] = -50;
	motor[powerCD] = -50;
	motor[rightDriveFrontMID] = -50;
	motor[leftDriveBack] = -50;
	motor[powerAB] = -50;
	motor[leftDriveFrontMID] = -50;
	wait1Msec(100);
	motor[rightDriveBack] = 0;
	motor[powerCD] = 0;
	motor[rightDriveFrontMID] = 0;
	motor[leftDriveBack] = 0;
	motor[powerAB] = 0;
	motor[leftDriveFrontMID] = 0;
	//T(25,60);


	TrackMG(1);
	TrackMG(0);
	TrackMG(1);
	motor[rightDriveBack] = -50;
	motor[powerCD] = -50;
	motor[rightDriveFrontMID] = -50;
	motor[leftDriveBack] = 50;
	motor[powerAB] = 50;
	motor[leftDriveFrontMID] = 50;
	wait1Msec(100);
	motor[rightDriveBack] = 0;
	motor[powerCD] = 0;
	motor[rightDriveFrontMID] = 0;
	motor[leftDriveBack] = 0;
	motor[powerAB] = 0;
	motor[leftDriveFrontMID] = 0;


	wait1Msec(100);
	MGM(11, 50, 0);
	stopTask(POTStall);
	motor[ConeGrab] = -127;
	M(5, 60, 1);							//////////While claw coming down holding cone moving forward stack on second mg
	motor[ConeGrab] = 0;
	//wait1Msec(100);
	SensorValue[Claw] = 1;	//drop cone
	wait1Msec(100);
	startTask(POTTop);
	wait1Msec(400);
	M(1, 60, 1);
	SensorValue(piston) = 1;
	wait1Msec(100);
	T(-35, 120);
	wait1Msec(100);
	M(8, 70, 1);
	//wait1Msec(100);
	//	T(-10,100);
	//wait1Msec(100);
	//////NEW CODE/////
	////////////////////FACING THE SCORING ZONE
	LineTrack(40, 1);


	////Move to Scoring zone
	MGM(7, 70, 1);
	MGM(10, 100, 1);
	M(8, 35, 1);
	///////////////////////////////////
	ArcTurn(55, 9, 'f', 'r');
	ArcTurn(55, 9, 'f', 'l');



	T(35, 60);
	M(1, 50, 1);
	//ForwardToPole(25);
	M(10, 100, 1);
	ForwardToPole(60);
	//wait1Msec(100);//shortened from 200
	startTask(MGDown);
	wait1Msec(100);//THIS MUST STAY
	M(-22, 70, 0);//6 scored

	T(-35, 70);
	M(-40, 100, 1);
	stopTask(FarRightAuto);
}