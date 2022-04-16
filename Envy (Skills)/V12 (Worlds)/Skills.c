Test(12,0); ///Forward to Stationary
motor[ConeGrab]=127;	//Place cone
wait1Msec(750);
motor[ConeGrab]=-60;//Pull back grabber
wait1Msec(500);
motor[ConeGrab]=0;//Kill grabber motor
//BackUpPole();
LineTrack(-25, 0);	//Back up untill the robot sees scoring zone line
wait1Msec(1000);
//Test(4,0);
M(2,40,0);	//Move Forward to get away from mid zone pole
wait1Msec(500);
SensorValue[gyro]=0;
T(-60);			//Turn to face right mobile goal
motor[rightMG]=-127;	//Bring MG lift down
motor[leftMG]=-127;
SensorValue[piston]=1; //release piston
wait1Msec(750);
motor[rightMG]=-20;	//Keep MG lift down
motor[leftMG]=-20;
//Test(66,1); ///Move to right mobile goal
M(50,60,0);	//Move Forward to get away from mid zone pole
wait1Msec(250);
T(20);
M(6,60,0);
T(-10);
LineTrack(30,0);
M(12,60,1);	//Move Forward to get MG
SensorValue[piston]=0; //Bring piston up to grab MG
wait1Msec(100);
motor[rightMG]=127;	//Pick up MG
motor[leftMG]=127;
wait1Msec(750);
motor[rightMG]=0;
motor[leftMG]=0;
M(-12,60,0);	//Move Back with mg
T(-20);
M(-10,60,0);
SensorValue[gyro]=0;
T(-160);
LineTrack(-25,0);
M(50,60,1);
SensorValue[piston]=1; //Release MG
M(-10,60,0);
//SensorValue[piston]=0;
//wait1Msec(100);
//motor[rightMG]=127;
//motor[leftMG]=127;
//wait1Msec(750);
//Test(-85,0);
//wait1Msec(500);
//T(-120);
