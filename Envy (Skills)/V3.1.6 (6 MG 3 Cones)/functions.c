void ForwardToPole()
{	int EncoderValueL=0;
	int EncoderValueR=0;
	while ((abs(SensorValue[Lencoder])-EncoderValueL)>5)
	{		if ((abs(SensorValue[Lencoder])-EncoderValueL)>5)
		{
			motor[leftDriveBack]=25;
			motor[powerAB]=25;
			motor[leftDriveFrontMID]=25;
		}
		else {
			motor[leftDriveBack]=0;
			motor[powerAB]=0;
			motor[leftDriveFrontMID]=0;
		}
		if ((abs(SensorValue[Rencoder])-EncoderValueR)>5)
		{
			motor[rightDriveBack]=25;
			motor[powerCD]=25;
			motor[rightDriveFrontMID]=25;
		}
		else{motor[rightDriveBack]=0;
			motor[powerCD]=0;
			motor[rightDriveFrontMID]=0;}

			EncoderValueL=abs(SensorValue[Lencoder]);
			EncoderValueR=abs(SensorValue[Rencoder]);
			wait1Msec(350);
	}
	motor[rightDriveBack]=0;
	motor[powerCD]=0;
	motor[rightDriveFrontMID]=0;
	motor[leftDriveBack]=0;
	motor[powerAB]=0;
	motor[leftDriveFrontMID]=0;
}
void BackUpWall()
{	int EncoderValueL=0;
	int EncoderValueR=0;
	while ((abs(SensorValue[Lencoder])-EncoderValueL)>5)
	{		if ((abs(SensorValue[Lencoder])-EncoderValueL)>5)
		{
			motor[leftDriveBack]=-50;
			motor[powerAB]=-50;
			motor[leftDriveFrontMID]=-50;
		}
		else {
			motor[leftDriveBack]=0;
			motor[powerAB]=0;
			motor[leftDriveFrontMID]=0;
		}
		if ((abs(SensorValue[Rencoder])-EncoderValueR)>5)
		{
			motor[rightDriveBack]=-50;
			motor[powerCD]=-50;
			motor[rightDriveFrontMID]=-50;
		}
		else{motor[rightDriveBack]=0;
			motor[powerCD]=0;
			motor[rightDriveFrontMID]=0;}

			EncoderValueL=abs(SensorValue[Lencoder]);
			EncoderValueR=abs(SensorValue[Rencoder]);
			wait1Msec(350);
	}
	motor[rightDriveBack]=0;
	motor[powerCD]=0;
	motor[rightDriveFrontMID]=0;
	motor[leftDriveBack]=0;
	motor[powerAB]=0;
	motor[leftDriveFrontMID]=0;
}



void BackUpPole()
{
	while(SensorValue[BLine]>1200)
	{
		motor[rightDriveBack]=-40;
		motor[powerCD]=-40;
		motor[rightDriveFrontMID]=-40;
		motor[leftDriveBack]=-40;
		motor[powerAB]=-40;
		motor[leftDriveFrontMID]=-40;
	}
	motor[rightDriveBack]=0;
	motor[powerCD]=0;
	motor[rightDriveFrontMID]=0;
	motor[leftDriveBack]=0;
	motor[powerAB]=0;
	motor[leftDriveFrontMID]=0;
}



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
	dist= (dist*261.33)/(4*3.1415);///Change 261 (IME Turbo) for 360 for external Motor controllers

	//int x;
	float dir,Loffset, Roffset,speed;

	if (dist<0){dir=-1;}
	else{dir=1;}//

	//while(q<2)
	//{
	//wait1Msec(100);
	clearTimer(T3);
	while(((abs(SensorValue[Lencoder])<(abs(dist))&&time1[T3]<3000))/*&&abs(SensorValue[gyro])!=(abs(dist)-50)*/)
	{


		//x=(dist-SensorValue[Lencoder])/*/18*/;
		//if ((pow(x,2))%127>0){speed=-dir*127;}//-127cos(pow((x/57),2)+(127/2)
		//	else{speed=-dir*pow(x,2);}
		speed=dir*vel*se.mult;/*-100*cos(x/(dist/5))/2+100/2;*/  //abs((80*x)/50);//pow(x/18),2);//127*cos(x/57)/2+(127/2);
		//speed=-dir*speed;

		if ((abs(SensorValue[Rencoder])<abs(SensorValue[Lencoder]))/*&&time1[T3]>250*/){Loffset=-dir*5; Roffset=0;}
		else if ((abs(SensorValue[Lencoder])<abs(SensorValue[Rencoder]))/*&&time1[T3]>250*/){Loffset=0; Roffset=-dir*5;}
		//else if(time1[T3]>250)
		//{
		//	Loffset=0;
		//	Roffset=0;
		//	SensorValue[I2C_1]=0;
		//	SensorValue[I2C_2]=0;
		//}
		else{Loffset=0; Roffset=0;}

		writeDebugStreamLine("%d, %d", Loffset, Roffset);
		motor[rightDriveBack]=speed+Roffset;
		motor[powerCD]=speed+Roffset;
		motor[rightDriveFrontMID]=speed+Roffset;
		motor[leftDriveBack]=speed+Loffset;
		motor[powerAB]=speed+Loffset;
		motor[leftDriveFrontMID]=speed+Loffset;

	}
	if (MobileGoal==0)
	{motor[rightDriveBack]=-dir*50/2;
		motor[powerCD]=-dir*50/2;
		motor[rightDriveFrontMID]=-dir*50/2;
		motor[leftDriveBack]=-dir*50/2;
		motor[powerAB]=-dir*50/2;
		motor[leftDriveFrontMID]=-dir*50/2;
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

void T(float degree, float vel)
{clearTimer(T1);
	SensorValue[Rencoder]=0;
	SensorValue[Lencoder]=0;
	SensorValue[in1]=0;
	//90 degrees

	float x;
	float dir,Loffset, Roffset,speed;

	if (degree<0){dir=-1;}
	else{dir=1;}//
	degree=degree*9.29;//Correction factor for this specific gyro

	while(abs(SensorValue[in1])>(abs(degree)+10)||abs(SensorValue[in1])<(abs(degree)-10) && time1[T1]<2500)
	{
		writeDebugStreamLine("%f",SensorValue(in1));
		if (abs(SensorValue[Rencoder])<abs(SensorValue[Lencoder])){Loffset=dir*10; Roffset=0;}
		else if (abs(SensorValue[Lencoder])<abs(SensorValue[Rencoder])){Loffset=0; Roffset=-dir*10;}
		else{Loffset=0; Roffset=0;}

		x=(degree-SensorValue[in1])/10;
		/*if ((pow(x,2)+20)%127>0){speed=dir*127;}
		else{speed=dir*pow(x,2)+20;}
		*/
		speed=vel;//abs(100*x/(degree*1.25))+20;/*pow((x/16),2);*//*100*cos(x/2)/2+(100/2);*/
		speed=dir*speed*se.mult;

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


void Motors(float speed, int time)
{
	float Loffset=0; float Roffset=0;

	writeDebugStreamLine("%d, %d", Loffset, Roffset);
	motor[rightDriveBack]=speed+Roffset;
	motor[powerCD]=speed+Roffset;
	motor[rightDriveFrontMID]=speed+Roffset;
	motor[leftDriveBack]=speed+Loffset;
	motor[powerAB]=speed+Loffset;
	motor[leftDriveFrontMID]=speed+Loffset;
	wait1Msec(time);
}

void LineTrack(int speed, int track )
{if (track==0)
	{
		while (SensorValue[LLine]>1000||SensorValue[RLine]>1000)
		{
			if (SensorValue[LLine]>1000)
			{	motor[leftDriveBack]=speed;
				motor[powerAB]=speed;
				motor[leftDriveFrontMID]=speed;
			}
			else
			{
				motor[leftDriveBack]=-speed/3;
				motor[powerAB]=-speed/3;
				motor[leftDriveFrontMID]=-speed/3;
			}
			if (SensorValue[RLine]>1000)
			{
				motor[rightDriveBack]=speed;
				motor[powerCD]=speed;
				motor[rightDriveFrontMID]=speed;
			}
			else
			{
				motor[rightDriveBack]=-speed/3;
				motor[powerCD]=-speed/3;
				motor[rightDriveFrontMID]=-speed/3;
			}
		}
	}
	else {
		while (SensorValue[LLine]<1000||SensorValue[RLine]<1000)
		{
			if (SensorValue[LLine]<1000)
			{	motor[leftDriveBack]=speed;
				motor[powerAB]=speed;
				motor[leftDriveFrontMID]=speed;
			}
			else
			{
				motor[leftDriveBack]=-speed;
				motor[powerAB]=-speed;
				motor[leftDriveFrontMID]=-speed/2;
			}
			if (SensorValue[RLine]<1000)
			{
				motor[rightDriveBack]=speed;
				motor[powerCD]=speed;
				motor[rightDriveFrontMID]=speed;
			}
			else
			{
				motor[rightDriveBack]=-speed;
				motor[powerCD]=-speed;
				motor[rightDriveFrontMID]=-speed;
			}
		}
	}
	motor[rightDriveBack]=0;
	motor[powerCD]=0;
	motor[rightDriveFrontMID]=0;
	motor[leftDriveBack]=0;
	motor[powerAB]=0;
	motor[leftDriveFrontMID]=0;
}

task MGUp()
{
	SensorValue[piston]=0;
	while(SensorValue[MGlimit]==0)
	{
		motor[rightMG]=-127;
		motor[leftMG]=-127;
	}
	motor[rightMG]=0;
	motor[leftMG]=0;
	stopTask(MGUp);
}

task MGUpAuto()
{
	SensorValue[piston]=0;
	motor[rightMG]=65;
	motor[leftMG]=65;
	wait10Msec(25);
	while(SensorValue[MGlimit]==0)
	{
		motor[rightMG]=-127;
		motor[leftMG]=-127;
	}
	motor[rightMG]=0;
	motor[leftMG]=0;
	stopTask(MGUpAuto);
}

task MGDown()
{	stopTask(MGUp);
	stopTask(MGUpAuto);
	SensorValue[piston]=0;
	while(SensorValue[MGlimitD]==0||SensorValue[MGlimit]==1)
	{
		motor[rightMG]=127;
		motor[leftMG]=127;
	}
	motor[rightMG]=0;
	motor[leftMG]=0;
	stopTask(MGDown);
}
task throw()
{
	SensorValue[thrower]=1;
	wait10Msec(25);
	SensorValue[thrower]=0;
	SensorValue[throwerIN]=1;
	stopTask(throw);
}

task PistonUp()
{
	//stopTask(throw);
	startTask(MGUp);
	wait10Msec(50);
	SensorValue[piston]=1;

	stopTask(PistonUp);
}

task PistonUpAuto()
{
	SensorValue[piston]=1;

	stopTask(PistonUp);
}

task POTStall()
{while(1)
{if(SensorValue[POT]<2000){motor[ConeGrab]=10;}
else if(SensorValue[POT]>2400){motor[ConeGrab]=-10;}
else{motor[ConeGrab]=0;}
wait1Msec(20);
}
}
task POTTop()
{while(SensorValue[POT]<2000){motor[ConeGrab]=90;wait1Msec(20);}
while(SensorValue[POT]>2400){motor[ConeGrab]=-90;wait1Msec(20);}
motor[ConeGrab]=0;
startTask(POTStall);
stopTask(POTTop);
}
