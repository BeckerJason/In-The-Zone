SensorValue[Claw]=0;
startTask(POTTop);
M(34,75,1);//(float dist, int vel, int MobileGoal)
startTask(MGUpAuto);//First MID MG RIGHT pickup
M(32,50,1);
stopTask(POTStall);
motor[ConeGrab]=-127;
wait1Msec(500);
SensorValue[Claw]=1;
startTask(POTTop);
wait1Msec(600);
startTask(PistonUpAuto);//Second MID MG RIGHT pickup
wait1Msec(100);
M(13,60,0);
wait1Msec(300);

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

M(9,100,1);
playSound(soundBeepBeep);
ForwardToPole();
startTask(throw);
wait1Msec(200);
startTask(MGDown);
wait1Msec(150);//THIS MUST STAY
M(-22,75,0);//2 scored
wait1Msec(100);
T(90,60);
wait1Msec(100);
M(15,75,0);
wait1Msec(100);
T(90,60);
wait1Msec(100);
M(-8,80,1);
wait1Msec(100);
M(10,75,1);//(float dist, int vel, int MobileGoal)
stopTask(POTStall);
SensorValue[Claw]=1;
motor[ConeGrab]=127;
M(24,75,1);//(float dist, int vel, int MobileGoal)
startTask(MGUpAuto);//First MID MG RIGHT pickup
M(10,50,1);
SensorValue[Claw]=0;
motor[ConeGrab]=-127;
M(29,50,1);
wait1Msec(300);
SensorValue[Claw]=1;
stopTask(POTStall);
startTask(POTTop);
wait1Msec(600);
startTask(PistonUpAuto);//Second MID MG RIGHT pickup
wait1Msec(300);
M(12,60,0);
wait1Msec(100);

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
playSound(soundBeepBeep);
ForwardToPole();
Motors(0,0);
startTask(throw);
wait10Msec(25);
startTask(MGDown);
wait1Msec(150);//THIS MUST STAY
M(-24,75,0);//4 scored


//T(105,70);
//M(-2,70,1);
////T(90,70);
////M(-12,75,0);
////T(15,70);
T(105,60);
M(-2,70,1);
BackUpWall();


///////////////////////////////Code to grab 5&6 MG////////////////////////////////
M(5,50,0);
wait1Msec(300);
T(90,65);
motor[rightMG]=10;////These lines make sure the MG is Down
motor[leftMG]=10;///// Here too
///////////Move to get second mobile goals
wait1Msec(100);
M(5,100,1);
RLineTrack(70);
wait1Msec(50);
motor[rightMG]=0;////These lines make sure the MG stops
motor[leftMG]=0;///// Here too
LineTrack(30,0);
M(12,50,0);
//startTask(MGUpAuto);
//wait1Msec(500);

////////////////////////AFTER GRABBING MG GRAB CONE AND NEXT MG
////////NEW CODE////////

	stopTask(POTStall);
	SensorValue[Claw]=1;
motor[ConeGrab]=127;
wait1Msec(800);
M(5,50,0);
SensorValue[Claw]=0;
wait1Msec(200);
startTask(POTTop);
startTask(MGUpAuto);
while(SensorValue[MGlimit]==0){}
//M(-7,50,0);
wait1Msec(100);
SensorValue[in1]=0;
T(-65,60);
wait1Msec(100);
M(3,60,0);
wait1Msec(100);
T(13,60);
wait1Msec(100);
M(15,60,1);
stopTask(POTStall);
motor[ConeGrab]=-127;
M(6,40,1);							//////////While claw coming down holding cone moving forward stack on second mg
//motor[ConeGrab]=-127;
	wait1Msec(100);
	SensorValue[Claw]=1;	//drop cone
	wait1Msec(100);
startTask(POTTop);
wait1Msec(400);
//M(1,40,1);
startTask(PistonUpAuto);
wait1Msec(200);
	T(-45,60);
//////NEW CODE/////
////////////////////FACING THE SCORING ZONE
LineTrack(40,1);
////Move to Scoring zone
M(25,100,1);
M(22,35,0);
T(35,50);
M(1,50,1);
ForwardToPole();
SensorValue[piston]=0;
M(-6,70,0);
wait1Msec(200);
SensorValue[in1]=0;
T(-90, 60);
M(22,60,0);
wait1Msec(200);
SensorValue[in1]=0;
T(90,60);
SensorValue[piston]=1;
M(1,60,1);
ForwardToPole();
startTask(MGDown);
while(SensorValue[MGlimitD]==0){}
M(-8,70,0); //////////////////////////5 AND 6 MG SCORED//////////////////////////////////////////////////






///////////////////////////////Code for last 2 MG////////////////////////////////////////////////////
wait1Msec(200);
T(105,60);
M(-2,70,1);
BackUpWall();
M(5,50,0);
wait1Msec(300);
T(90,65);
motor[rightMG]=10;////These lines make sure the MG is Down
motor[leftMG]=10;///// Here too
///////////Move to get second mobile goals
wait1Msec(100);
M(5,100,1);
RLineTrack(70);
wait1Msec(50);
motor[rightMG]=0;////These lines make sure the MG stops
motor[leftMG]=0;///// Here too
LineTrack(30,0);
M(12,50,0);
//startTask(MGUpAuto);
//wait1Msec(500);

////////////////////////AFTER GRABBING MG GRAB CONE AND NEXT MG
////////NEW CODE////////

	stopTask(POTStall);
	SensorValue[Claw]=1;
motor[ConeGrab]=127;
wait1Msec(800);
M(5,50,0);
SensorValue[Claw]=0;
wait1Msec(200);
startTask(POTTop);
startTask(MGUpAuto);
while(SensorValue[MGlimit]==0){}
//M(-7,50,0);
wait1Msec(100);
SensorValue[in1]=0;
T(-65,60);
wait1Msec(100);
M(3,60,0);
wait1Msec(100);
T(13,60);
wait1Msec(100);
M(15,60,1);
stopTask(POTStall);
motor[ConeGrab]=-127;
M(6,40,1);							//////////While claw coming down holding cone moving forward stack on second mg
//motor[ConeGrab]=-127;
	wait1Msec(100);
	SensorValue[Claw]=1;	//drop cone
	wait1Msec(100);
startTask(POTTop);
wait1Msec(400);
//M(1,40,1);
startTask(PistonUpAuto);
wait1Msec(200);
	T(-45,60);
//////NEW CODE/////
////////////////////FACING THE SCORING ZONE
LineTrack(40,1);
////Move to Scoring zone
M(25,100,1);
M(22,35,0);
T(35,50);
M(1,50,1);
ForwardToPole();
SensorValue[piston]=0;
M(-6,70,0);
wait1Msec(200);
SensorValue[in1]=0;
T(-90, 60);
M(22,60,0);
wait1Msec(200);
SensorValue[in1]=0;
T(90,60);
SensorValue[piston]=1;
M(1,60,1);
ForwardToPole();
startTask(MGDown);
while(SensorValue[MGlimitD]==0){}
M(-8,70,0); //////////////////////////5 AND 6 MG SCORED//////////////////////////////////////////////////