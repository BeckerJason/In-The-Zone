M(34,75,1);//(float dist, int vel, int MobileGoal)
startTask(MGUpAuto);//First MID MG RIGHT pickup
M(38,50,1);
startTask(PistonUpAuto);//Second MID MG RIGHT pickup
wait1Msec(300);
M(15,60,0);
wait10Msec(50);
T(25,50);
wait10Msec(50);
M(25,75,0);
wait10Msec(50);
T(-25,50);//lined up to far zone
wait10Msec(50);
M(5,100,1);
PlaySound(soundBeepBeep);
Motors(40,1000);
Motors(0,0);
startTask(throw);
wait10Msec(25);
startTask(MGDown);
M(-24,75,0);//2 scored
wait10Msec(25);
T(90,70);
wait10Msec(25);
M(14,100,0);
wait10Msec(25);
T(90,70);
wait10Msec(25);
M(-10,100,1);
wait10Msec(25);
M(34,75,1);//(float dist, int vel, int MobileGoal)
startTask(MGUpAuto);//First MID MG LEFT pickup
M(38,50,1);
startTask(PistonUpAuto);//Second MID MG LEFT pickup
wait1Msec(300);
M(15,60,0);
wait10Msec(50);
T(25,50);
wait10Msec(50);
M(25,75,0);
wait10Msec(50);
T(-25,50);//lined up to far zone
wait10Msec(50);
M(20,100,1);
PlaySound(soundBeepBeep);
Motors(50,1000);
Motors(0,0);
startTask(throw);
wait10Msec(25);
startTask(MGDown);
M(-24,75,0);//2 scored
T(90);
M(-12,75,0);
T(15);
