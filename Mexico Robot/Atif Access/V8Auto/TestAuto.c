//CLOSE CLAW TO GRAB PRE-LOAD

C(1);
wait1Msec(500);

liftCont(80);
CM(120,127,0);
liftCont(10);
CM(0,127,1);
SensorValue[enc]=0;
CM(-30,127,0);
//MOVE 12 INCHES TO POLL IN FORWARD DIRECTION AT 80 SPEED
M(10,1,80);
liftCont(-100);
wait1Msec(500);
liftCont(0);
C(0);
wait1Msec(500);
M(6,-1,80);
//TURN TO MOBILE GOAL
T(60,100,20);

motor[MG]=-127;
wait1Msec(1000);
M(70,1,100);

motor[MG]=127;
wait1Msec(3000);
motor[MG]=0;

M(24,-1,100);
//GO BACK UNTIL LINE//
while(SensorValue[LineM]>1000){
	motor[LM] = -50;
	motor[L1] = -50;
	motor[RM] = -50;
	motor[R1] = -50;
}
	motor[LM] = 15;
	motor[L1] = 15;
	motor[RM] = 15;
	motor[R1] = 15;
	wait1Msec(250);

//SensorValue[gyro]=0;
//T(80,100,20);
//M(20,-1,100);
int po = 100;
while(abs(SensorValue[in7])<1345){
motor[LM] = po;
	motor[L1] = po;
	motor[RM] = -po+30;
	motor[R1] = -po+30;
}
motor[LM] = -15;
	motor[L1] = -15;
	motor[RM] = 15;
	motor[R1] = 15;
	wait1Msec(250);
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;

//T(80,100,20);

while(1);
