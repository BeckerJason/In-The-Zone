//CLOSE CLAW TO GRAB PRE-LOAD
SensorValue[gyro]=0;
SensorValue[I2C_1]=0;
SensorValue[I2C_2]=0;
clearTimer(T3);
//C(1);
//wait1Msec(500);
writeDebugStreamLine("%d",T3);
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
T(60,100,20);
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
int po = 60;
while(abs(SensorValue[in7])*0.973>420){
	motor[LM] = -po*pr.mult;
	motor[L1] = -po*pr.mult;
	motor[RM] = po*pr.mult;
	motor[R1] = po*pr.mult;
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

motor[LM] = 15;
motor[L1] = 15;
motor[RM] = -15;
motor[R1] = -15;
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
	//writeDebugStreamLine("%f",SensorValue[LineM]);


	//This code leaves the robot on top of the line so that only if the second condition is true the robot goes backwards:
	//add something if the robot is not on top of the line

	//point right turn until line is detected or the robot is almost parallel to line
	//po = 80;
	//while(SensorValue[LineM]>1500 && (abs(SensorValue[in7])*0.973<1000)){//abs(SensorValue[in7])*0.973<1345){
	//motor[LM] = po/4;
	//	motor[L1] = po/4;
	//	motor[RM] = -po;
	//	motor[R1] = -po;
	//}
	//wait1Msec(500);
	////motor[LM] = -15;
	////	motor[L1] = -15;
	////	motor[RM] = 15;
	////	motor[R1] = 15;
	////	wait1Msec(150);
	////	motor[LM] = 0;
	////	motor[L1] = 0;
	////	motor[RM] = 0;
	////	motor[R1] = 0;
	//writeDebugStreamLine("%f	%f	%f", SensorValue[LineL], SensorValue[LineM],SensorValue[LineR]);
	//while(SensorValue[LineM]>1500){
	//	motor[LM] = -30;
	//	motor[L1] = -30;
	//	motor[RM] = -30;
	//	motor[R1] = -30;
	//}
	//	motor[LM] = 0;
	//	motor[L1] = 0;
	//	motor[RM] = 0;
	//	motor[R1] = 0;
	//	wait1Msec(500);
	////motor[LM] = -15;
	////	motor[L1] = -15;
	////	motor[RM] = 15;
	////	motor[R1] = 15;
	////	wait1Msec(250);
	////	motor[LM] = 0;
	////	motor[L1] = 0;
	////	motor[RM] = 0;
	////	motor[R1] = 0;
	//	//po = 30
	//	//while(SensorValue[LineM]>1500){
	//	//	motor[LM] = -po;
	//	//motor[L1] = -po;
	//	//motor[RM] = po;
	//	//motor[R1] = po;
	//	//}
	//	motor[LM] = 0;
	//	motor[L1] = 0;
	//	motor[RM] = 0;
	//	motor[R1] = 0;
	//	writeDebugStreamLine("%f	%f	%f", SensorValue[LineL], SensorValue[LineM],SensorValue[LineR]);
	//	//MOVE FORWARD FOLLOWING THE LINE FOR 12 INCHES
	//	SensorValue[Lenc]=0;
	//	SensorValue[Renc]=0;
	//	while((SensorValue[Lenc]+SensorValue[Renc])/2<172)FollowLine(30);
	////T(80,100,20);


	//SensorValue[Lenc]=0;
	//	SensorValue[Renc]=0;
	//	while((SensorValue[Lenc]+SensorValue[Renc])/2<172)FollowLine(30);

	SensorValue[gyro]=0;
	T(92,127,25);		//Turn to face preloads
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
	PL(8);
	writeDebugStreamLine("%f",T3);
	SensorValue[gyro]=0;
	T(100,127,25);						//Changed from 92 to 100 during far zone programming
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
	/*while(SensorValue[IR]==0)					//Commented out during far zone programming but not technically need
	{int l=127;
	motor[leftArm1] = l*pr.mult;
	motor[leftArm2] = l*pr.mult;
	motor[rightArm1] = l*pr.mult;
	motor[rightArm2] = l*pr.mult;}
	int l=10;
	motor[leftArm1] = l*pr.mult;
	motor[leftArm2] = l*pr.mult;
	motor[rightArm1] = l*pr.mult;
	motor[rightArm2] = l*pr.mult;
	CM(0,127,1);
	*/
	//Original Auto Code for scoring in near zone
	//writeDebugStreamLine("%f",T3);
	//	motor[RM] = 70*se.mult;
	//	motor[R1] = 70*se.mult;
	//MGM(-127,2000);


	motor[RM] = 100*se.mult;		//Turn to face scoring zone
	motor[R1] = 100*se.mult;
	motor[LM] = 50*se.mult;
	motor[L1] = 50*se.mult;
	motor[MG]=-127;								//mobile goal out half way
	wait1Msec(1000);

	motor[MG]=5;
	motor[LM] = 100*se.mult;		//Move to scoring zone
	motor[L1] = 100*se.mult;
	wait1Msec(1000);
	C(0);								//Open claw to score
	motor[MG]=-127;			//Mobile goal down all the way
	wait1Msec(2500);
	//motor[LM] = 0;
	//motor[L1] = 0;
	//motor[RM] = 0;
	//motor[R1] = 0;
	//motor[MG]=	0;



	motor[LM] = 80;
	motor[L1] = 80;
	motor[RM] = 80;
	motor[R1] = 80;
	//motor[MG]=	-50;
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
	while(1){
		motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] = 0;
		motor[MG]=	0;
	}

	//M(5,-1, 127);

	//MGM(127,3000);


	/*
	SensorValue[gyro]=0;
	T(92,127,25);		//Turn to face wall
	wait1Msec(500);
	M(32,1,127);
	writeDebugStreamLine("%f",T3);
	SensorValue[gyro]=0;
	T(46,127,25);		//Turn to face second mobile goal
	MGM(-127,3000);
	writeDebugStreamLine("%f",T3);
	M(32,1,127);
	MGM(127,3000);
	writeDebugStreamLine("%f",T3);
	S();
	writeDebugStreamLine("%f",T3);
	*/
	while(1){}
