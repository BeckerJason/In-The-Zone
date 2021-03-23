
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
liftCont(10);
CM(0,127,1);
SensorValue[enc]=0;
CM(-30,127,0);
 SensorValue[gyro]=0;
//MOVE 12 INCHES TO POLL IN FORWARD DIRECTION AT 80 SPEED
M(10,1,80);
liftCont(-50);

wait1Msec(500);
liftCont(0);

C(0);
wait1Msec(500);
M(6,-1,80);

//TURN TO MOBILE GOAL
T(RB*60,100,20);
motor[MG]=-100;
wait1Msec(1000);
M(70,1,100);
motor[MG]=127;
wait1Msec(2500);


M(6,-1,127);	//Move robot back so it doesnt hit any cones was 6
motor[MG]=0;
writeDebugStreamLine("%f",SensorValue[gyro]);
//assuming robot is pointing towards the wall turn left parallel to pre-loads
//SensorValue[gyro]=0;
//const float gyroconst=(abs(SensorValue[gyro])-466.0)/10.0;
//T(gyroconst,127,20);
int po = RB*60;
while(abs(SensorValue[in7])*0.973>420){
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

motor[LM] = RB*15;
	motor[L1] = RB*15;
	motor[RM] = -RB*15;
	motor[R1] = -RB*15;
	wait1Msec(200);
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;

motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;

	motor[MG]=10;
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


//motor[LM] = 15;
//	motor[L1] = 15;
//	motor[RM] = 15;
//	motor[R1] = 15;
while(SensorValue[LineL]<1000&&SensorValue[LineR]<1000 ){
	if(SensorValue[LineR]<1000)
	{
		motor[LM] = -30;
	motor[L1] = -30;}
	else{	motor[LM] = 20;
	motor[L1] = 20;}
	if(SensorValue[LineL]<1000)
	{
		motor[RM] = -30;
	motor[R1] = -30;}
	else{	motor[RM] = 20;
	motor[R1] = 20;}

}


//get close to the line
M(9,-1,100);

motor[LM] = 15;
	motor[L1] = 15;
	motor[RM] = 15;
	motor[R1] = 15;
	wait1Msec(250);
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;

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
T(RB*92,127,25);		//Turn to face preloads

wait1Msec(500);
	motor[LM] = 60;				///Move forward to hit the wall
	motor[L1] = 60;
	motor[RM] = 60;
	motor[R1] = 60;
wait1Msec(500);

//IR2Sense();//Correct distance from preloads
M(3,-1,127);

PL(9);

SensorValue[gyro]=0;
T(RB*100,127,25);						//Changed from 92 to 100 during far zone programming

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
//
//	motor[RM] = 70*se.mult;
//	motor[R1] = 70*se.mult;
//MGM(-127,2000);

if (RB==-1)
{
	motor[RM] = 30*se.mult;		//Turn to face scoring zone
	motor[R1] = 30*se.mult;
		motor[LM] = 70*se.mult;
	motor[L1] = 70*se.mult;
}
else{	motor[RM] = 70*se.mult;		//Turn to face scoring zone
	motor[R1] = 70*se.mult;
		motor[LM] = 30*se.mult;
	motor[L1] = 30*se.mult;}

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
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
/*motor[MG]=5;
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
	//wait1Msec(300);

	while (SensorValue[pot]<3750)//Lift mobile goal slightly to pull out
	{motor[MG]=90;}
motor[MG]=-5;
wait1Msec(500);
	motor[LM] = -100;
	motor[L1] = -100;
	motor[RM] = -100;
	motor[R1] = -100;
	wait1Msec(1000);
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

SensorValue[gyro]=0;
T(46,127,25);		//Turn to face second mobile goal
MGM(-127,3000);

M(32,1,127);
MGM(127,3000);

S();

*/
while(1);
