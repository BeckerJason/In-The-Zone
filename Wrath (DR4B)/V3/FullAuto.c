//if (c==1)  //If the claw is open and you press or hold the button it will close
//	{motor[roller]=-127;}
//	else	if (c==2)	//when the button is released the claw remains open
//	{motor[roller]=-25;}
//	else if (c==3) //when the button is released the claw stays closed
//	{motor[roller]=127;}
//	else if (c==4)	//when the claw is closed and you press or hold the button it will open
//	{motor[roller]=0;}
//	else{}

void FullAuto(){
	clearDebugStream();
	SensorValue[in7]=0;		//Set gyro to 0
	SensorValue[I2C_1]=0;		//set right base encoder to 0
	SensorValue[I2C_2]=0;		//set left base encoder to 0
		SensorValue[I2C_3]=0;		//set left arm encoder to 0
	SensorValue[I2C_4]=0;		//set right arm encoder to 0
	SensorValue[enc]=0;
	clearTimer(T3);//
	C(2);
FB(-30);
//C(2);//CLOSE CLAW TO GRAB PRE-LOAD
	wait1Msec(100);
	//L(400, 65,0);
liftCont(80);
wait1Msec(1000);
liftCont(20);
	/////////////////////////////////////CM(0,127,1);
	/////////////////////////////////////////CM(30,127,0);
	//MOVE 12 INCHES TO POLL IN FORWARD DIRECTION AT 80 SPEED
//Mover(10, 1); //dist dir mg(1=y 0=n)
	M(5,1,65);
//while(SensorValue[Rarm]>250)
//{	liftCont(-20);}
liftCont(0);
wait1Msec(700);
	C(3);
	liftCont(65);
	wait1Msec(250);
	FB(70);	////4 bar stay up
	liftCont(20);
	wait1Msec(250);
	liftCont(-20);
	wait1Msec(250);
	C(4);
	FB(20);
	//wait1Msec(500);
	Mover(-6,0);
	wait1Msec(200);
	liftCont(0);
	//TURN TO MOBILE GOAL
	SensorValue[gyro]=0;
	//Turning(AllianceColor*60);
	T(AllianceColor*60,100,20);

	writeDebugStreamLine("%f",SensorValue[gyro]);

	wait1Msec(500);
	mobi.val=2;//MG full speed
	startTask(MGGM);
	//wait1Msec(750);
	Mover(120,1);
	//Move(100,70);
	mobi.val=-1;
	startTask(MGGM);
	wait1Msec(2500);
	FB(30);	////4 bar stay up
	//M(3,-1,127);	//Move robot back so it doesnt hit any cones

	//writeDebugStreamLine("%f",SensorValue[gyro]);
	//assuming robot is pointing towards the wall turn left parallel to pre-loads
	//SensorValue[gyro]=0;
	//const float gyroconst=(abs(SensorValue[gyro])-466.0)/10.0;
	//T(gyroconst,127,20);
	int po;
	if (AllianceColor==1)
	{po=60;}
	else{po=-60;}
	while(abs(SensorValue[in7])*0.94>520){
		motor[LM] = -po*pr.mult;
		motor[L1] = -po*pr.mult;
		motor[RM] = po*pr.mult;
		motor[R1] = po*pr.mult;
	}



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

	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
	//GET OUT OF BLUE TILE
	//move back until blue tile

	//M(7,-1,100);

	//move completelly out of tile
	//while(SensorValue[LineM]<1000 ){
	//	motor[LM] = -50;
	//	motor[L1] = -50;
	//	motor[RM] = -50;
	//	motor[R1] = -50;
	//}

	while(SensorValue[LineL]<2600||SensorValue[LineR]<2600){
		if(SensorValue[LineL]<2600)
		{
			motor[LM] = -40;
			motor[L1] = -40;}
		else{	motor[LM] =50;
			motor[L1] = 650;}
		if(SensorValue[LineR]<2600)
		{
			motor[RM] = -40;
			motor[R1] = -40;}
		else{	motor[RM] = 50;
			motor[R1] = 50;}
		//	writeDebugStreamLine("L %d    R %d",SensorValue[LineL],SensorValue[LineR]);
	}

	//get close to the line
	M(7,-1,100);

	motor[LM] = 15;
	motor[L1] = 15;
	motor[RM] = 15;
	motor[R1] = 15;
	wait1Msec(250);
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;


	SensorValue[gyro]=0;
	T(AllianceColor*86,127,25);		//Turn to face preloads

	wait1Msec(500);
	motor[LM] = 40;				///Move forward to hit the wall
	motor[L1] = 40;
	motor[RM] = 40;
	motor[R1] = 40;
	wait1Msec(1250);

	//IR2Sense();//Correct distance from preloads
	M(5,-1,70);





	//////////////////////////////////////////////////////////////////////////////




	if (NearOrFar==0)
	{//Near zone code

		PL(10);

		SensorValue[gyro]=0;
		T(AllianceColor*92,127,25);						//Changed from 92 to 100 during far zone programming

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

		motor[fb1]=15;
		motor[fb2]=15;

		if (AllianceColor==1){
			motor[RM] = 70*se.mult;		//Turn to face scoring zone
			motor[R1] = 70*se.mult;
			motor[LM] = 20*se.mult;
			motor[L1] = 20*se.mult;}
		else{
			motor[RM] = 20*se.mult;		//Turn to face scoring zone
			motor[R1] = 20*se.mult;
			motor[LM] = 70*se.mult;
			motor[L1] = 70*se.mult;}

		wait1Msec(1500);
		motor[roller]=127;
		wait1Msec(300);
		mobi.val=3;
		startTask(MGGM);
		////////////////SensorValue[claw]=0;//mobile goal out half way
		motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] = 0;
		wait1Msec(3000);
		motor[LM] = -40;
		motor[L1] = -40;
		motor[RM] = -40;
		motor[R1] = -40;
		wait1Msec(400);
		mobi.val=-1;
		startTask(MGGM);
		wait1Msec(2000);


		M(4,-1, 127);
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
	{	PL(7);

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

		motor[fb1]=15;
		motor[fb2]=15;

		if (AllianceColor==1){
			motor[RM] = 70*se.mult;		//Turn to face scoring zone
			motor[R1] = 70*se.mult;
			motor[LM] = 20*se.mult;
			motor[L1] = 20*se.mult;}
		else{
			motor[RM] = 20*se.mult;		//Turn to face scoring zone
			motor[R1] = 20*se.mult;
			motor[LM] = 70*se.mult;
			motor[L1] = 70*se.mult;}

		wait1Msec(1500);
		M(7,-1, 127);							//Back up to pole

			motor[RM] =127*se.mult;		//drive into mid scoring zone
			motor[R1] = 127*se.mult;
			motor[LM] = 127*se.mult;
			motor[L1] = 127*se.mult;
			wait1Msec(1500);
			motor[RM] =65*se.mult;		//keep base forward
			motor[R1] = 65*se.mult;
			motor[LM] = 65*se.mult;
			motor[L1] = 65*se.mult;
		motor[roller]=127;				//spin cone out to release top of stack
		wait1Msec(300);
		mobi.val=3;
		startTask(MGGM);					//Start moving mobile goal out
		motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] = 0;
		wait1Msec(2000);				//waiting for mobile goal task to be done
		motor[LM] = -40;				//move away from stack
		motor[L1] = -40;
		motor[RM] = -40;
		motor[R1] = -40;
		wait1Msec(400);
		mobi.val=-1;
		startTask(MGGM);			//Move mobile goal back in
		wait1Msec(500);

		M(18,-1, 127);					//back out of mid zone


//		//T(AllianceColor*105,127,55);						//Changed from 92 to 100 during far zone programming

//		M(32,1, 127);
//		//Changed from 34 to 36during far zone programming
//		motor[LM] = -40;
//		motor[L1] = -40;
//		motor[RM] = -40;
//		motor[R1] = -40;
//		wait1Msec(150);
//		motor[LM] = 0;
//		motor[L1] = 0;
//		motor[RM] = 0;
//		motor[R1] = 0;

//		motor[fb1]=15;
//motor[fb2]=15;

//		if(AllianceColor==1){
//			motor[RM] = 120*se.mult;		//Turn to face scoring zone
//			motor[R1] = 120*se.mult;
//			motor[LM] = -30*se.mult;
//			motor[L1] = -30*se.mult;}
//		else{motor[RM] = -30*se.mult;		//Turn to face scoring zone
//			motor[R1] = -30*se.mult;
//			motor[LM] = 120*se.mult;
//			motor[L1] = 120*se.mult;}




//					wait1Msec(1500);
//		motor[MG]=127;
//		wait1Msec(300);
//		mobi.val=3;
//		startTask(MGGM);
//		////////////////SensorValue[claw]=0;//mobile goal out half way
//		motor[LM] = 0;
//		motor[L1] = 0;
//		motor[RM] = 0;
//		motor[R1] = 0;
//		wait1Msec(3000);
//		motor[LM] = -40;
//		motor[L1] = -40;
//		motor[RM] = -40;
//		motor[R1] = -40;
//		wait1Msec(400);
//		mobi.val=-1;
//		startTask(MGGM);
//		wait1Msec(2000);
//		motor[LM] = -120;
//		motor[L1] = -120;
//		motor[RM] = -120;
//		motor[R1] = -120;
//		wait1Msec(500);









		while(1)
		{
			motor[LM] = 0;
			motor[L1] = 0;
			motor[RM] = 0;
			motor[R1] = 0;
			motor[MG]=	0;
		}
	}
	else if(NearOrFar==2)///Code For grabbing second mobile goal
	{
		PL(4);

		SensorValue[gyro]=0;
		T(AllianceColor*105,127,55);						//Changed from 92 to 100 during far zone programming

		M(50,1, 127);
		//Changed from 34 to 36during far zone programming
		motor[LM] = -40;
		motor[L1] = -40;
		motor[RM] = -40;
		motor[R1] = -40;
		wait1Msec(150);
		motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] = 0;

		motor[fb1]=15;
motor[fb2]=15;

		if(AllianceColor==1){
			motor[RM] = 120*se.mult;		//Turn to face scoring zone
			motor[R1] = 120*se.mult;
			motor[LM] = -30*se.mult;
			motor[L1] = -30*se.mult;}
		else{motor[RM] = -30*se.mult;		//Turn to face scoring zone
			motor[R1] = -30*se.mult;
			motor[LM] = 120*se.mult;
			motor[L1] = 120*se.mult;}



		wait1Msec(400);
		motor[MG]=-127;								//mobile goal out half way
		wait1Msec(400);

		motor[RM] = 100;
		motor[R1] = 100;



		motor[MG]=5;
		motor[LM] = 100*se.mult;		//Move to scoring zone
		motor[L1] = 100*se.mult;
		wait1Msec(1000);
		C(0);								//Open claw to score
		motor[MG]=-127;			//Mobile goal down all the way
		wait1Msec(1000);


		motor[LM] = 80;
		motor[L1] = 80;
		motor[RM] = 80;
		motor[R1] = 80;
		wait1Msec(300);

		while (SensorValue[pot]>1850)//Lift mobile goal slightly to pull out
		{motor[MG]=90;}
		motor[MG]=10;
		wait1Msec(500);
		motor[LM] = -120;
		motor[L1] = -120;
		motor[RM] = -120;
		motor[R1] = -120;
		wait1Msec(1200);
		motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] = 0;
		motor[MG]=	0;

		Turn(-1,130);

		wait1Msec(200);

		M(11,1, 127);

		wait1Msec(200);

		SensorValue[gyro]=0;
		Turn(-1,30);

		wait1Msec(200);

		SensorValue[gyro]=0;
		motor[MG]=-127;

		wait1Msec(400);

		M(48,1, 127);

		wait1Msec(200);

		motor[MG]=127;

		wait1Msec(1000);

		M(45,-1, 127);

		wait1Msec(600);
		SensorValue[gyro]=0;
		Turn(-1,180);
		motor[MG]=-127;




	}
		else if(NearOrFar==1)//Far zone code
	{	PL(7);

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

		motor[fb1]=15;
		motor[fb2]=15;

		if (AllianceColor==1){
			motor[RM] = 70*se.mult;		//Turn to face scoring zone
			motor[R1] = 70*se.mult;
			motor[LM] = 20*se.mult;
			motor[L1] = 20*se.mult;}
		else{
			motor[RM] = 20*se.mult;		//Turn to face scoring zone
			motor[R1] = 20*se.mult;
			motor[LM] = 70*se.mult;
			motor[L1] = 70*se.mult;}

		wait1Msec(1500);
		M(7,-1, 127);							//Back up to pole

			motor[RM] =127*se.mult;		//drive into mid scoring zone
			motor[R1] = 127*se.mult;
			motor[LM] = 127*se.mult;
			motor[L1] = 127*se.mult;
			wait1Msec(1500);
			motor[RM] =65*se.mult;		//keep base forward
			motor[R1] = 65*se.mult;
			motor[LM] = 65*se.mult;
			motor[L1] = 65*se.mult;
		motor[roller]=127;				//spin cone out to release top of stack
		wait1Msec(300);
		mobi.val=3;
		startTask(MGGM);					//Start moving mobile goal out
		motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] = 0;
		wait1Msec(2000);				//waiting for mobile goal task to be done
		motor[LM] = -40;				//move away from stack
		motor[L1] = -40;
		motor[RM] = -40;
		motor[R1] = -40;
		wait1Msec(400);
		mobi.val=-1;
		startTask(MGGM);			//Move mobile goal back in
		wait1Msec(500);

		M(18,-1, 127);					//back out of mid zone



		while(1)
		{
			motor[LM] = 0;
			motor[L1] = 0;
			motor[RM] = 0;
			motor[R1] = 0;
			motor[MG]=	0;
		}
	}
	else{while(1){}}

}
