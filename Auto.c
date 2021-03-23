SensorValue[gyro]=0;
Pusher(0);
Grab(0);
mobi.val=-1;
startTask(MGGM);
wait1Msec(1000);
Move(85,1);		//move to grab 2 goals
Grab(1);
mobi.val=1;
startTask(MGGM);		//lift mg
wait1Msec(2000);
Move(5,0);					//move forward to clear pole
SensorValue[gyro]=0;
T(65,100,20);				//turn to middle of scoring area
Move(18,0);					//move into middle
wait1Msec(300);
SensorValue[gyro]=0;
T(-65,100,20);			//turn to scoring zone
Grab(0);						//open front for grabber
Move(18,0);					//move to far zone pole
Pusher(1);					//push goals out
Move(-20,0);				//move backwards to drop mgs and move back towards pole
Pusher(0);					//bring piston back in
Move(7,0);
Move(-7,0);
SensorValue[gyro]=0;
T(115,70,20);					// turn right to repeat grabbing goals
Move(18,0);
SensorValue[gyro]=0;
T(65,70,20);						//turn to face mobile goals
SensorValue[gyro]=0;
Pusher(0);
Grab(0);
mobi.val=-1;
startTask(MGGM);
wait1Msec(1000);
Move(85,1);
Grab(1);
mobi.val=1;
startTask(MGGM);
wait1Msec(2000);
Move(5,0);
SensorValue[gyro]=0;
T(65,100,20);
Move(20,0);
wait1Msec(300);
SensorValue[gyro]=0;
T(-65,100,20);
Grab(0);
Move(18,0);
Pusher(1);
Move(-18,0);
Pusher(0);
