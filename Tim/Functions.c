void M(int speed, int time)
{
	motor[driveLeft]=speed;
	motor[driveRight]=speed;
	wait1Msec(time*1000);
	motor[driveLeft]=-speed/10;
	motor[driveRight]=-speed/10;
	wait1Msec(200);
	motor[driveLeft]=0;
	motor[driveRight]=0;
}



void T(int deg,int speed, int time)
{int dir;
	if (deg>0){dir=1;}
	else if (deg<0){dir=-1;}
	else{}

	while((abs(SensorValue[gyro])*0.973/10)<abs(deg))
	{
		if ((abs(SensorValue[gyro])*0.973/10)<(abs(deg)-30))
		{
			motor[driveLeft] = dir*speed;
			motor[driveRight] = -dir*speed;}
		else if ((abs(SensorValue[gyro])*0.973/10)<(abs(deg)-15))
		{
			motor[driveLeft] = dir*speed/2;
			motor[driveRight] = -dir*speed/2;}
		else
		{motor[driveLeft] = dir*speed/3;
			motor[driveRight] = -dir*speed/3;}
	}
	wait1Msec(time);
	while(abs(SensorValue[gyro])*0.973/10>abs(deg))
	{	motor[driveLeft] = -dir*speed/2;
		motor[driveRight] = dir*speed/2;}
	wait1Msec(time);
	while(abs(SensorValue[gyro])*0.973/10<abs(deg))
	{	motor[driveLeft] = dir*speed/3;
		motor[driveRight] = -dir*speed/3;}
	motor[driveLeft] = -dir*10;
	motor[driveRight] = dir*10;
	wait1Msec(100);
	motor[driveLeft] = 0;
	motor[driveRight] = 0;
}



void C(int value)
{SensorValue[claw]=value;}



void F(int speed, int POTvalue, int cone)
{
	while(SensorValue[fourPOT]!=POTvalue)
	{
		if(SensorValue[fourPOT]<POTvalue)
		{
			motor[FourBar]=speed;
		}
		else if(SensorValue[fourPOT]>POTvalue)
		{
			motor[FourBar]=-speed;
		}
		else if (cone==1)
		{
			motor[FourBar]=15;
		}
		else //no cone
		{
			motor[FourBar]=10;
		}
	}
}

//void Sup(int dir)
//{
//	while(SensorValue[IR]==1}
//	{
//	motor[RSlideFr]=127;
//	motor[RSlideBa]=127;
//	motor[LSlideFr]=127;
//	motor[LSlideBa]=127;
//}
//wait1Msec(200)
//motor[RSlideFr]=127;
//	motor[RSlideBa]=127;
//	motor[LSlideFr]=127;
//	motor[LSlideBa]=127;
//}
void stack()
{ F(127, 420,1);
	while (SensorValue[IR]==0&&vexRT[Btn7U])
	{
		motor[RSlideFr]=127;
		motor[RSlideBa]=127;
		motor[LSlideFr]=127;
		motor[LSlideBa]=127;
	}
	motor[RSlideFr]=15;
	motor[RSlideBa]=15;
	motor[LSlideFr]=15;
	motor[LSlideBa]=15;
	F(127, 800,1);
	wait1Msec(200);
	C(0);
	wait1Msec(500);
	F(127, 420,0);
	while (SensorValue[liftlimit]==0&&vexRT[Btn7U])
	{
		motor[RSlideFr]=-127;
		motor[RSlideBa]=-127;
		motor[LSlideFr]=-127;
		motor[LSlideBa]=-127;
	}
	motor[RSlideFr]=0;
	motor[RSlideBa]=0;
	motor[LSlideFr]=0;
	motor[LSlideBa]=0;
	F(127, 0,0);
}

void MGL(int dir, int time)
{
	if(dir==1)
	{
		motor[MG]=127;
		wait1Msec(time*1000);
		motor[MG]=15;
	}
	else if(dir==-1)
	{
		motor[MG]=127;
		wait1Msec(time*1000);
		motor[MG]=0;
	}
}
