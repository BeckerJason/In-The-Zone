void FullAuto(){
	C(1);//CLOSE CLAW TO GRAB PRE-LOAD
	SensorValue[gyro]=0;		//Set gyro to 0
	SensorValue[I2C_1]=0;		//set right arm encoder to 0
	SensorValue[I2C_2]=0;		//set right arm encoder to 0
	clearTimer(T3);//
	//C(1);
	//wait1Msec(500);

	liftCont(80);
	CM(120,127,0);
	writeDebugStreamLine("%f",T3);
	liftCont(10);
	CM(0,127,1);
	SensorValue[enc]=0;
	CM(-30,127,0);
	writeDebugStreamLine("%f",T3);
	//MOVE 12 INCHES TO POLL IN FORWARD DIRECTION AT 80 SPEED
	M(10,1,80);
	liftCont(-100);
	writeDebugStreamLine("%f",T3);
	wait1Msec(500);
	liftCont(0);
	writeDebugStreamLine("%f",T3);
	C(0);
	wait1Msec(500);
	M(6,-1,80);
	writeDebugStreamLine("%f",T3);
	//TURN TO MOBILE GOAL
	T(AllianceColor*60,100,20);
	writeDebugStreamLine("%f",T3);
	writeDebugStreamLine("%f",SensorValue[gyro]);


	motor[MG]=-127;
	wait1Msec(1000);
	motor[MG]=-50;
	M(70,1,100);
	writeDebugStreamLine("%f",T3);
	motor[MG]=127;
	wait1Msec(2500);
	writeDebugStreamLine("%f",T3);
	M(6,-1,127);	//Move robot back so it doesnt hit any cones
	writeDebugStreamLine("%f",T3);
	writeDebugStreamLine("%f",SensorValue[gyro]);
	//assuming robot is pointing towards the wall turn left parallel to pre-loads
	//SensorValue[gyro]=0;
	//const float gyroconst=(abs(SensorValue[gyro])-466.0)/10.0;
	//T(gyroconst,127,20);
	if (AllianceColor==1)
	{int po=60;
		while(abs(SensorValue[in7])*0.973>420){
			motor[LM] = -po*pr.mult;
			motor[L1] = -po*pr.mult;
			motor[RM] = po*pr.mult;
			motor[R1] = po*pr.mult;
		}
	}
	else
	{int po=-60;
		while(abs(SensorValue[in7])*0.973<-420){
			motor[LM] = -po*pr.mult;
			motor[L1] = -po*pr.mult;
			motor[RM] = po*pr.mult;
			motor[R1] = po*pr.mult;}
	}

	writeDebugStreamLine("%f",T3);
	//wait1Msec(20);
	//po=30;
	//while(abs(SensorValue[in7])*0.973<420){
	//motor[LM] = po;
	//	motor[L1] = po;
	//	motor[RM] = -po;
	//	motor[R1] = -po;
	//}

	motor[LM] = AllianceColor*15;
	motor[L1] = AllianceColor*15;
	motor[RM] = -AllianceColor*15;
	motor[R1] = -AllianceColor*15;
	wait1Msec(200);
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
	writeDebugStreamLine("%f",T3);
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;

	motor[MG]=10;
	//GET OUT OF BLUE TILE
	//move back until blue tile
	writeDebugStreamLine("%f",T3);
	//M(7,-1,100);
	writeDebugStreamLine("%f",T3);
	//move completelly out of tile
	//while(SensorValue[LineM]<1000 ){
	//	motor[LM] = -50;
	//	motor[L1] = -50;
	//	motor[RM] = -50;
	//	motor[R1] = -50;
	//}

	while(SensorValue[LineL]<1000||SensorValue[LineR]<1000){
		if(SensorValue[LineL]<1000)
		{
			motor[LM] = -40;
			motor[L1] = -40;}
		else{	motor[LM] =60;
			motor[L1] = 60;}
		if(SensorValue[LineR]<1000)
		{
			motor[RM] = -40;
			motor[R1] = -40;}
		else{	motor[RM] = 60;
			motor[R1] = 60;}
		//	writeDebugStreamLine("L %d    R %d",SensorValue[LineL],SensorValue[LineR]);
	}
	writeDebugStreamLine("%f",T3);
	//get close to the line
	M(9,-1,100);
	writeDebugStreamLine("%f",T3);
	motor[LM] = 15;
	motor[L1] = 15;
	motor[RM] = 15;
	motor[R1] = 15;
	wait1Msec(250);
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
	writeDebugStreamLine("%f",T3);

	SensorValue[gyro]=0;
	T(AllianceColor*92,127,25);		//Turn to face preloads
	writeDebugStreamLine("%f",T3);
	wait1Msec(500);
	motor[LM] = 60;				///Move forward to hit the wall
	motor[L1] = 60;
	motor[RM] = 60;
	motor[R1] = 60;
	wait1Msec(500);
	writeDebugStreamLine("%f",T3);
	//IR2Sense();//Correct distance from preloads
	M(3,-1,127);
	writeDebugStreamLine("%f",T3);




	//////////////////////////////////////////////////////////////////////////////




	if (NearOrFar==0)
	{//Near zone code

		PL(9);

		SensorValue[gyro]=0;
		T(AllianceColor*100,127,25);						//Changed from 92 to 100 during far zone programming

		M(32,1, 127);								//Changed from 34 to 36during far zone programming
		motor[LM] = -50;
		motor[L1] = -50;
		motor[RM] = -50;
		motor[R1] = -50;
		wait1Msec(50);
		motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] = 0;

		motor[ClawM]=15;

		if (AllianceColor==1){
			motor[RM] = 70*se.mult;		//Turn to face scoring zone
			motor[R1] = 70*se.mult;
			motor[LM] = 30*se.mult;
			motor[L1] = 30*se.mult;}
		else{
			motor[RM] = 30*se.mult;		//Turn to face scoring zone
			motor[R1] = 30*se.mult;
			motor[LM] = 70*se.mult;
			motor[L1] = 70*se.mult;}

		wait1Msec(1500);
		motor[MG]=-127;
		SensorValue[claw]=0;//mobile goal out half way
		motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] = 0;
		wait1Msec(2000);
		motor[MG]=0;
		wait1Msec(500);


		M(7,-1, 127);
		while(1)
		{
			motor[LM] = 0;
			motor[L1] = 0;
			motor[RM] = 0;
			motor[R1] = 0;
			motor[MG]=	0;
		}

	}
	else if(NearOrFar==1)//Far zone code
	{	PL(8);
		writeDebugStreamLine("%f",T3);
		SensorValue[gyro]=0;
		T(AllianceColor*100,127,25);						//Changed from 92 to 100 during far zone programming
		writeDebugStreamLine("%f",T3);
		M(36,1, 127);								//Changed from 34 to 36during far zone programming
		motor[LM] = -50;
		motor[L1] = -50;
		motor[RM] = -50;
		motor[R1] = -50;
		wait1Msec(50);
		motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] = 0;
		writeDebugStreamLine("%f",T3);
		motor[ClawM]=15;
		writeDebugStreamLine("%f",T3);

		if(AllianceColor==1){
			motor[RM] = 100*se.mult;		//Turn to face scoring zone
			motor[R1] = 100*se.mult;
			motor[LM] = 50*se.mult;
			motor[L1] = 50*se.mult;}
		else{motor[RM] = 50*se.mult;		//Turn to face scoring zone
			motor[R1] = 50*se.mult;
			motor[LM] = 100*se.mult;
			motor[L1] = 100*se.mult;}
		motor[MG]=-127;								//mobile goal out half way
		wait1Msec(1000);

		motor[MG]=5;
		motor[LM] = 100*se.mult;		//Move to scoring zone
		motor[L1] = 100*se.mult;
		wait1Msec(1000);
		C(0);								//Open claw to score
		motor[MG]=-127;			//Mobile goal down all the way
		wait1Msec(2500);


		motor[LM] = 80;
		motor[L1] = 80;
		motor[RM] = 80;
		motor[R1] = 80;
		wait1Msec(300);

		while (SensorValue[pot]>3850)//Lift mobile goal slightly to pull out
		{motor[MG]=90;}
		motor[MG]=-5;
		wait1Msec(500);
		motor[LM] = -100;
		motor[L1] = -100;
		motor[RM] = -100;
		motor[R1] = -100;
		wait1Msec(2000);
		while(1)
		{
			motor[LM] = 0;
			motor[L1] = 0;
			motor[RM] = 0;
			motor[R1] = 0;
			motor[MG]=	0;
		}
	}
	else{}
	while(1);
}
