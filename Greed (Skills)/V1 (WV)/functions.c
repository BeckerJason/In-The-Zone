void Move(float dist,int MobileGoal) // distance in inches (give a value of negative if backwards), 1 if grabbing mobile goal at end of movement
{SensorValue[Renc]=0;
	SensorValue[Lenc]=0;
	dist= (dist*360)/(4*3.14);///Change 261 (IME Turbo), 396 HS,  for 360 for external Motor controllers

	float x;
	float dir,Loffset, Roffset,speed;

	clearTimer(T1);
	while( time1[T1]<7500 && (abs(SensorValue[Lenc])<(abs(dist))   )/*&&abs(SensorValue[gyro])!=(abs(dist)-50)*/)
	{
		x=dist-SensorValue[Renc];
		if (x<0){dir=-1; x=-x;}
		else{dir=1;}

		speed=127;//(-45)*cos((16*abs(x))/(abs(dist)*3.14)+5.6)+35;    //Equation for speed
		speed=dir*speed;																					//Adjust direction

		if (abs(SensorValue[Renc])<(abs(SensorValue[Lenc]))){Loffset=-speed/5; Roffset=0;}
		else if (abs(SensorValue[Lenc])<(abs(SensorValue[Renc]))){Loffset=0; Roffset=-speed/5;}
		else{Loffset=0; Roffset=0;}

		writeDebugStreamLine("%f, %f", speed,x);
		motor[R1]=speed+Roffset;
		motor[R2]=speed+Roffset;
		motor[RM]=speed+Roffset;
		motor[L1]=speed+Loffset;
		motor[L2]=speed+Loffset;
		motor[LM]=speed+Loffset;
		wait1Msec(2);
	}
	if (MobileGoal==0)
	{motor[R1]=-dir*50/2;
		motor[R2]=-dir*50/2;
		motor[RM]=-dir*50/2;
		motor[LM]=-dir*50/2;
		motor[L1]=-dir*50/2;
		motor[L2]=-dir*50/2;
		wait1Msec(200);
	}
	else{}
	motor[R1]=0;
	motor[R2]=0;
	motor[RM]=0;
	motor[LM]=0;
	motor[L1]=0;
	motor[L2]=0;
}




void T(int deg,int speed, int time)
{int dir;
	if (deg>0){dir=1;}
	else if (deg<0){dir=-1;}
	else{}
	while((abs(SensorValue[in7])*0.94/10)<abs(deg))
	{	if ((abs(SensorValue[in7])*0.94/10)<(abs(deg)-30))
		{
			motor[LM] = dir*speed*se.mult;
			motor[L1] = dir*speed*se.mult;
			motor[L2] = dir*speed*se.mult;
			motor[RM] = -dir*speed*se.mult;
			motor[R1] = -dir*speed*se.mult;
			motor[R2] = -dir*speed*se.mult;}
		else if ((abs(SensorValue[in7])*0.973/10)<(abs(deg)-15))
		{
			motor[LM] = dir*speed*se.mult/2;
			motor[L1] = dir*speed*se.mult/2;
			motor[L2] = dir*speed*se.mult/2;
			motor[RM] = -dir*speed*se.mult/2;
			motor[R1] = -dir*speed*se.mult/2;
			motor[R2] = -dir*speed*se.mult/2;}
		else
		{motor[LM] = dir*speed*se.mult/3;
			motor[L1] = dir*speed*se.mult/3;
			motor[L2] = dir*speed*se.mult/3;
			motor[RM] = -dir*speed*se.mult/3;
			motor[R1] = -dir*speed*se.mult/3;
			motor[R2] = -dir*speed*se.mult/3;}
	}
	wait1Msec(time);
	while(abs(SensorValue[in7])*0.973/10>abs(deg))
	{	motor[LM] = -dir*speed*se.mult/2;
		motor[L1] = -dir*speed*se.mult/2;
		motor[L2] = -dir*speed*se.mult/2;
		motor[RM] = dir*speed*se.mult/2;
		motor[R1] = dir*speed*se.mult/2;
		motor[R2] = dir*speed*se.mult/2;}
	wait1Msec(time);
	while(abs(SensorValue[in7])*0.973/10<abs(deg))
	{	motor[LM] = dir*speed*se.mult/3;
		motor[L1] = dir*speed*se.mult/3;
		motor[L2] = dir*speed*se.mult/3;
		motor[RM] = -dir*speed*se.mult/3;
		motor[R1] = -dir*speed*se.mult/3;
		motor[R2] = -dir*speed*se.mult/3;}
	motor[LM] = -dir*10*se.mult;
	motor[L1] = -dir*10*se.mult;
		motor[L2] = -dir*10*se.mult;
	motor[RM] = dir*10*se.mult;
	motor[R1] = dir*10*se.mult;
	motor[R2] = dir*10*se.mult;
	wait1Msec(100);
	motor[R1]=0;
	motor[R2]=0;
	motor[RM]=0;
	motor[LM]=0;
	motor[L1]=0;
	motor[L2]=0;
}



void Grab(int val)
{SensorValue[claw1]=val;SensorValue[claw2]=val;}

void Pusher(int val)
{SensorValue[push]=val;}
