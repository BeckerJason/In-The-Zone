//CLOSE CLAW TO GRAB PRE-LOAD

clearTimer(T3);
C(1);
wait1Msec(500);
writeDebugStreamLine("%f",T3);
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

motor[MG]=-127;
wait1Msec(1000);
M(70,1,100);
writeDebugStreamLine("%f",T3);
motor[MG]=127;
wait1Msec(3000);
motor[MG]=0;
writeDebugStreamLine("%f",T3);
M(4,-1,127);	//Move robot back so it doesnt hit any cones
writeDebugStreamLine("%f",T3);

//assuming robot is pointing towards the wall turn left parallel to pre-loads
int po = 60;
while(abs(SensorValue[in7])*0.973>420){
motor[LM] = -po;
	motor[L1] = -po;
	motor[RM] = po;
	motor[R1] = po;
}
writeDebugStreamLine("%f",T3);
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
	wait1Msec(150);
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
writeDebugStreamLine("%f",T3);
motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
//GET OUT OF BLUE TILE
	//move back until blue tile
	writeDebugStreamLine("%f",T3);
M(10,-1,100);
writeDebugStreamLine("%f",T3);
	//move completelly out of tile
while(SensorValue[LineM]<1000 ){
	motor[LM] = -50;
	motor[L1] = -50;
	motor[RM] = -50;
	motor[R1] = -50;
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
PL(10);
writeDebugStreamLine("%f",T3);
SensorValue[gyro]=0;
T(92,127,25);
writeDebugStreamLine("%f",T3);
M(34,1, 127);
writeDebugStreamLine("%f",T3);
motor[ClawM]=15;
writeDebugStreamLine("%f",T3);
while(SensorValue[IR]==0)
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
writeDebugStreamLine("%f",T3);
	motor[RM] = 70*se.mult;
	motor[R1] = 70*se.mult;
	wait1Msec(2000);
	writeDebugStreamLine("%f",T3);
	motor[RM] = 0;
	motor[R1] = 0;
MGM(-127,3000);
M(5,-1, 127);
MGM(127,3000);

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

while(1);
