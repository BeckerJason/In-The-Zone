int mgPOS=0; // position of hook for mobile goal. 0 = carry 1 = docking

void MG(int dir) // function for hook . input as direction
{
	if(dir==0) // bring mobile goal and body up to carrying
	{
		SensorValue[piston]=0; // hook up and lock mobile goal
		wait1Msec(300);
		motor[rightMG]=127; //move mobile goal body up
		motor[leftMG]=127; // move mobile goal body up
		wait10Msec(30);
		mgPOS=0; // in carrying position
	}
	else if(dir==1) //setting body down to ready load mobile goal
	{
		SensorValue[piston]=1; //hook down. This works to get goal in
		motor[rightMG]=-127; //move mobile goal body down
		motor[leftMG]=-127; //move mobile goal body down

		mgPOS=1; // in docking position
		wait10Msec(30);
	}
	else{}
	if(mgPOS==1) // if in docking position
	{
		motor[rightMG]=-15; // keep in docking position
		motor[leftMG]=-15; // keep in docking position
	}
	else // if not in docking postion
	{
		motor[rightMG]=0; // motor offline. don't do anything
		motor[leftMG]=0; // motor offline. don't do anything
	}
}

void M(float dist) // movement function
{SensorValue[Rencoder]=0; // Initialize right encoder
	SensorValue[Lencoder]=0; // Initialize left encoder

	dist= (dist*360/*261.33*/)/(4*3.1415);///Change 261 (IME Turbo) for 360 for external Motor controllers

	int x;
	int dir,Loffset, Roffset,speed;

	if (dist<0){dir=1;} //one direction
	else{dir=-1;} // or the other

	//while(q<2)
	//{
	//wait1Msec(100);
	while(abs(SensorValue[Lencoder])<(abs(dist))/*&&abs(SensorValue[gyro])!=(abs(dist)-50)*/)
	{
		if (abs(SensorValue[Rencoder])<(abs(SensorValue[Lencoder]))){Loffset=-dir*10; Roffset=0;}
		else if (abs(SensorValue[Lencoder])<(abs(SensorValue[Rencoder]))){Loffset=0; Roffset=-dir*10;}
		else{Loffset=0; Roffset=0;} // Corrects the orientation of moving robot

		x=(dist-SensorValue[Lencoder])/*/18*/;
		//if ((pow(x,2))%127>0){speed=-dir*127;}//-127cos(pow((x/57),2)+(127/2)
		//	else{speed=-dir*pow(x,2);}
		speed=65;/*-100*cos(x/(dist/5))/2+100/2;*/  //abs((80*x)/50);//pow(x/18),2);//127*cos(x/57)/2+(127/2);
		speed=-dir*speed;

writeDebugStreamLine("%d, %d", Loffset, Roffset);
		motor[rightDriveBack]=speed+Roffset;
		motor[powerCD]=speed+Roffset;
		motor[rightDriveFrontMID]=speed+Roffset;
		motor[leftDriveBack]=speed+Loffset;
		motor[powerAB]=speed+Loffset;
		motor[leftDriveFrontMID]=speed+Loffset; //Jason's debug program

	}
	motor[rightDriveBack]=dir*50/2; // robot very near end of path
	motor[powerCD]=dir*50/2;
	motor[rightDriveFrontMID]=dir*50/2;
	motor[leftDriveBack]=dir*50/2;
	motor[powerAB]=dir*50/2;
	motor[leftDriveFrontMID]=dir*50/2;
	//q++;
	wait1Msec(100);
	//}
	motor[rightDriveBack]=0; //robot end of path
	motor[powerCD]=0;
	motor[rightDriveFrontMID]=0;
	motor[leftDriveBack]=0;
	motor[powerAB]=0;
	motor[leftDriveFrontMID]=0;
}

void T(float degree)
{clearTimer(T1);
	SensorValue[Rencoder]=0;
	SensorValue[Lencoder]=0;
	SensorValue[gyro]=0;
	//90 degrees

	int x;
	int dir,Loffset, Roffset,speed;

	if (degree<0){dir=-1;}
	else{dir=1;}//
	degree=degree*9.2;//Correction factor for this specific gyro

	while(abs(SensorValue[gyro])>(abs(degree)+10)||abs(SensorValue[gyro])<(abs(degree)-10) && time1[T1]<2500)
	{
		if (abs(SensorValue[Rencoder])<abs(SensorValue[Lencoder])){Loffset=dir*10; Roffset=0;}
		else if (abs(SensorValue[Lencoder])<abs(SensorValue[Rencoder])){Loffset=0; Roffset=-dir*10;}
		else{Loffset=0; Roffset=0;}

		x=(degree-SensorValue[gyro])/10;
		/*if ((pow(x,2)+20)%127>0){speed=dir*127;}
		else{speed=dir*pow(x,2)+20;}
		*/
		speed=70;//abs(100*x/(degree*1.25))+20;/*pow((x/16),2);*//*100*cos(x/2)/2+(100/2);*/
		speed=dir*speed;

		//writeDebugStreamLine("%d, %d", x, speed);


		//	writeDebugStreamLine("%d", speed);
		//writeDebugStreamLine("%d", SensorValue[gyro]);
		motor[rightDriveBack]=speed+Roffset;
		motor[powerCD]=speed+Roffset;
		motor[rightDriveFrontMID]=speed+Roffset;
		motor[leftDriveBack]=-speed+Loffset;
		motor[powerAB]=-speed+Loffset;
		motor[leftDriveFrontMID]=-speed+Loffset;

	}
	motor[rightDriveBack]=-dir*50;
	motor[powerCD]=-dir*50;
	motor[rightDriveFrontMID]=-dir*50;
	motor[leftDriveBack]=dir*50;
	motor[powerAB]=dir*50;
	motor[leftDriveFrontMID]=dir*50;
	wait1Msec(100);

	motor[rightDriveBack]=0;
	motor[powerCD]=0;
	motor[rightDriveFrontMID]=0;
	motor[leftDriveBack]=0;
	motor[powerAB]=0;
	motor[leftDriveFrontMID]=0;
}

void L(int val)
{
	SensorValue[piston]=val;
}
