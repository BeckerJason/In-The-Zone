int mgPOS=0;
void MG(int dir)
{
	if(dir==0)
	{
		SensorValue[piston]=0;
		wait1Msec(300);
		motor[rightMG]=127;
		motor[leftMG]=127;
		wait10Msec(30);
		mgPOS=0;
	}
	else if(dir==1)
	{
				SensorValue[piston]=1;
		motor[rightMG]=-127;
		motor[leftMG]=-127;

		mgPOS=1;
		wait10Msec(30);
	}
	else{}
	if(mgPOS==1)
	{
		motor[rightMG]=-15;
		motor[leftMG]=-15;
	}
	else
	{
		motor[rightMG]=0;
		motor[leftMG]=0;
	}
}

void M(float dist, int vel, int MobileGoal)
{SensorValue[Rencoder]=0;
	SensorValue[Lencoder]=0;
	SensorValue[I2C_1]=0;
	SensorValue[I2C_2]=0;
	dist= (dist*261.33)/(4*3.1415);///Change 261 (IME Turbo) for 360 for external Motor controllers

	int x;
	int q=0;
	int dir,Loffset, Roffset,speed;

	if (dist<0){dir=1;}
	else{dir=-1;}//

	//while(q<2)
	//{
	//wait1Msec(100);
	clearTimer(T3);
	while((abs(SensorValue[Lencoder])<(abs(dist))&&time1[T3]<3000)/*&&abs(SensorValue[gyro])!=(abs(dist)-50)*/)
	{
		if (abs(SensorValue[Rencoder])<(abs(SensorValue[Lencoder]))){Loffset=-dir*5; Roffset=0;}
		else if (abs(SensorValue[Lencoder])<(abs(SensorValue[Rencoder]))){Loffset=0; Roffset=-dir*5;}
		else{Loffset=0; Roffset=0;}

		x=(dist-SensorValue[Lencoder])/*/18*/;
		//if ((pow(x,2))%127>0){speed=-dir*127;}//-127cos(pow((x/57),2)+(127/2)
		//	else{speed=-dir*pow(x,2);}
		speed=vel;/*-100*cos(x/(dist/5))/2+100/2;*/  //abs((80*x)/50);//pow(x/18),2);//127*cos(x/57)/2+(127/2);
		speed=-dir*speed;

writeDebugStreamLine("%d, %d", Loffset, Roffset);
		motor[rightDriveBack]=speed+Roffset;
		motor[powerCD]=speed+Roffset;
		motor[rightDriveFrontMID]=speed+Roffset;
		motor[leftDriveBack]=speed+Loffset;
		motor[powerAB]=speed+Loffset;
		motor[leftDriveFrontMID]=speed+Loffset;

	}
	if (MobileGoal==0)
{motor[rightDriveBack]=dir*50/2;
	motor[powerCD]=dir*50/2;
	motor[rightDriveFrontMID]=dir*50/2;
	motor[leftDriveBack]=dir*50/2;
	motor[powerAB]=dir*50/2;
	motor[leftDriveFrontMID]=dir*50/2;
	//q++;
	wait1Msec(100);
	}
	else{}
	motor[rightDriveBack]=0;
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


void Test(float dist, float vel, int MobileGoal)
{SensorValue[Rencoder]=0;
	SensorValue[Lencoder]=0;
	dist= (dist*261.33)/(4*3.14);///Change 261 (IME Turbo) for 360 for external Motor controllers

	float x;
	//int q=0;
	float dir,Loffset, Roffset,speed;

	//if (dist<0){dir=-1;}
	//else{dir=1;}//

	//while(q<2)
	//{
	//wait1Msec(100);
	clearTimer(T1);
	while( time1[T1]<2000 && (abs(SensorValue[Lencoder])<(abs(dist))   )/*&&abs(SensorValue[gyro])!=(abs(dist)-50)*/)
	{
		x=(abs(dist)-abs(SensorValue[Lencoder]);
			if (x<0){dir=-1; x=-x;}
	else{dir=1;}
	//
		//if (x<0){dir=1:}
		//else{dir=-1;}

		//if ((pow(x,2))%127>0){speed=-dir*127;}//-127cos(pow((x/57),2)+(127/2)
		//	else{speed=-dir*pow(x,2);}
		speed=(-35)*cos(16*abs(x)/(abs(dist)*3.14)+5.75)+30;//vel;
		speed=dir*speed;

		if (abs(SensorValue[Rencoder])<(abs(SensorValue[Lencoder]))){Loffset=-speed/5; Roffset=0;}
		else if (abs(SensorValue[Lencoder])<(abs(SensorValue[Rencoder]))){Loffset=0; Roffset=-speed/5;}
		else{Loffset=0; Roffset=0;}

writeDebugStreamLine("%f, %f", speed,x);
		motor[rightDriveBack]=speed+Roffset;
		motor[powerCD]=speed+Roffset;
		motor[rightDriveFrontMID]=speed+Roffset;
		motor[leftDriveBack]=speed+Loffset;
		motor[powerAB]=speed+Loffset;
		motor[leftDriveFrontMID]=speed+Loffset;
wait1Msec(2);
	}
	if (MobileGoal==0)
{motor[rightDriveBack]=dir*50/2;
	motor[powerCD]=dir*50/2;
	motor[rightDriveFrontMID]=dir*50/2;
	motor[leftDriveBack]=dir*50/2;
	motor[powerAB]=dir*50/2;
	motor[leftDriveFrontMID]=dir*50/2;
	//q++;
	wait1Msec(100);
	}
	else{}
	motor[rightDriveBack]=0;
	motor[powerCD]=0;
	motor[rightDriveFrontMID]=0;
	motor[leftDriveBack]=0;
	motor[powerAB]=0;
	motor[leftDriveFrontMID]=0;
}
