motor[ConeGrab]=127;
SensorValue[Claw]=1;
wait1Msec(300);
M(34,75,1);//(float dist, int vel, int MobileGoal)
startTask(MGUpAuto);//First MID MG RIGHT pickup
M(10,50,1);
SensorValue[Claw]=0;
motor[ConeGrab]=-127;
M(28,50,1);
wait1Msec(200);
SensorValue[Claw]=1;
startTask(POTTop);
wait1Msec(400);
startTask(PistonUpAuto);//Second MID MG RIGHT pickup
wait1Msec(300);
M(15,60,0);
wait1Msec(200);

////Comment out
//T(30,50);
//wait1Msec(200);
//M(21,70,0);
//wait1Msec(200);
//T(-30,50);//lined up to far zone
///////////////////
ArcTurn(55,11,'f','l');
ArcTurn(55,11,'f','r');


wait1Msec(300);
M(8,100,1);
playSound(soundBeepBeep);
ForwardToPole();
startTask(throw);
wait1Msec(250);
startTask(MGDown);
wait1Msec(150);//THIS MUST STAY
M(-22,75,0);//2 scored
wait10Msec(25);
T(90,60);
wait10Msec(25);
M(10,75,0);
wait10Msec(25);
T(90,60);
wait10Msec(25);
M(-8,80,1);
wait1Msec(300);
M(18,75,1);//(float dist, int vel, int MobileGoal)
stopTask(POTStall);
SensorValue[Claw]=1;
motor[ConeGrab]=127;
M(16,75,1);//(float dist, int vel, int MobileGoal)
startTask(MGUpAuto);//First MID MG RIGHT pickup
M(10,50,1);
SensorValue[Claw]=0;
motor[ConeGrab]=-127;
M(28,50,1);
wait1Msec(800);
SensorValue[Claw]=1;
startTask(POTTop);
wait1Msec(400);
startTask(PistonUpAuto);//Second MID MG RIGHT pickup
wait1Msec(300);
motor[ConeGrab]=0;
M(15,60,0);
wait1Msec(200);
//T(30,50);
//wait1Msec(400);
//M(22,75,0);
//wait1Msec(400);
//T(-25,50);//lined up to far zone

ArcTurn(45,11,'f','l');
ArcTurn(45,11,'f','r');


wait1Msec(400);
M(10,100,1);
playSound(soundBeepBeep);
ForwardToPole();
Motors(0,0);
startTask(throw);
wait10Msec(25);
startTask(MGDown);
wait1Msec(150);//THIS MUST STAY
M(-24,75,0);//4 scored
T(105,70);
M(-2,70,1);
//T(90,70);
//M(-12,75,0);
//T(15,70);
BackUpWall();
M(5,60,0);
wait1Msec(200);
T(90,55);
motor[rightMG]=10;////These lines make sure the MG is Down
motor[leftMG]=10;///// Here too
///////////Move to get second mobile goals
M(20,70,1);
M(10,30,1);
motor[rightMG]=0;////These lines make sure the MG stops
motor[leftMG]=0;///// Here too
LineTrack(30,0);
M(8,70,1);
startTask(MGUpAuto);
wait1Msec(500);


////////NEW CODE////////
	M(8,50,0);
	stopTask(POTStall);
	SensorValue[Claw]=1;
motor[ConeGrab]=127;
wait1Msec(800);
M(5,50,0);
SensorValue[Claw]=0;
wait1Msec(100);
startTask(POTTop);
M(-8,50,0);
wait1Msec(300);
SensorValue[in1]=0;
T(-30,60);
wait1Msec(300);
M(24,60,1);
stopTask(POTStall);
motor[ConeGrab]=-127;
	wait1Msec(400);
	SensorValue[Claw]=1;	//drop cone
startTask(POTTop);
startTask(PistonUpAuto);
wait1Msec(200);
motor[ConeGrab]=0;
M(6,50,0);
	T(-60,60);
//////NEW CODE/////



//T(-10,50);
//startTask(MGDown);
//wait1Msec(500);
//M(10,60,0);
//startTask(MGUpAuto);
//wait1Msec(500);
//StopTask(MGUpAuto);
//motor[rightMG]=-50;
//motor[leftMG]=-50;
//SensorValue[in1]=0;
//wait1Msec(20);
//T(-50,50);
//startTask(MGUpAuto);
//wait1Msec(500);
//M(12,60,1);
//startTask(MGUpAuto);//First Left MG Back pickup
//while( SensorValue[MGlimit]==0){}
//M(6,50,1);
//startTask(PistonUpAuto);//Second MID MG RIGHT pickup
//wait1Msec(500);
//T(-35,50);
LineTrack(30,1);
////Move to Scoring zone
M(45,80,0);
ForwardToPole();
T(35,50);
SensorValue[piston]=0;
M(-8,70,0);
wait1Msec(200);
SensorValue[in1]=0;
T(-90, 60);
M(20,60,0);
wait1Msec(200);
SensorValue[in1]=0;
T(90,60);
SensorValue[piston]=1;
M(1,40,1);
ForwardToPole();
startTask(MGDown);
while(SensorValue[MGlimitD]==0){}
M(-8,70,0);
