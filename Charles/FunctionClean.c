int position; // 0=carrying/up and 1=docking/down

void mobilelift (int direction){ //mobile goal lift
	if (direction == 0){
		sensorValue[piston]=0; //hook up. lock in.
		wait1Msec(300);
		motor[rightmobilelift]=127; //lift arms up
		motor[leftmobilelift]=127;
		wait10Msec(30);
		position=0; // set to carrying
	}
	else (direction == 1){
		SensorValue[piston]=1; // hook down. accepting mobile goals.
		motor[rightmobilelift]=-127; //put arms down
		motor[leftmobilelift]=-127;
		position=1; // set to docking
		wait10Msec(30);
	}
	if (position == 1){
		motor[rightmobilelift]=-15; // keep in docking position.
		motor[leftmobilelift]=-15;
	}
	else{
		motor[rightmobilelift]=0; //keep arms up in carrying.
		motor[leftmobilelift]=0;
}

void movement (float distance){
	/////////// Jason's convienent code to make precise paths///////
	SensorValue[rightencoder]=0; // initialize encoders
	SensorValue[leftencoder]=0;

	distance=(distance*360)/(4*PI);
	// change 360 to 261 (IME Turbo) for external motor controllers
	// aka the connectors from 3 pins to 2 pins

	int direction, leftoffset, rightoffset;
	int speed =-orientation*65;

	if (distance<0){direction=1;}
	else {direction=-1;}

	while(abs(SensorValue[leftencoder])<abs(distance)){
		if(abs(SensorValue[rightencoder])<abs(SensorValue[leftencoder])){leftoffset=-direction*10; rightoffset=0;}
		else if (abs(SensorValue[leftencoder])<abs(SensorValue[rightencoder])){rightoffset=-direction*10; leftoffset=0;}
		else{leftoffset=0; rightoffset=0;}

		// writeDebugStreamLine("%d, %d", leftoffset, rightoffset);

		motor[rightDriveBack]=speed+rightoffset;
		motor[powerCD]=speed+rightoffset;
		motor[rightDriveFrontMID]=speed+rightoffset;
		motor[leftDriveBack]=speed+leftoffset;
		motor[powerAB]=speed+leftoffset;
		motor[leftDriveFrontMID]=speed+leftoffset;
	}
	motor[rightDriveBack]=direction*50/2; // robot very near end of path
	motor[powerCD]=direction*50/2;
	motor[rightDriveFrontMID]=direction*50/2;
	motor[leftDriveBack]=direction*50/2;
	motor[powerAB]=direction*50/2;
	motor[leftDriveFrontMID]=direction*50/2;

	wait1Msec(100);

	motor[rightDriveBack]=0; //robot end of path
	motor[powerCD]=0;
	motor[rightDriveFrontMID]=0;
	motor[leftDriveBack]=0;
	motor[powerAB]=0;
	motor[leftDriveFrontMID]=0;
}

void turn(float degree){
	clearTimer(T1);

