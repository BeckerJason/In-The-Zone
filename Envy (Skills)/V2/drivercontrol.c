
int Loffset, Roffset, speed,dir;

if (vexRT[Btn6U]==1){SensorValue[kicker]=1;}
else if(vexRT[Btn6D]==1SensorValue[kicker]=0;}
if(vexRT[Btn5U]==1){ddir=1;}
else if (vexRT[Btn5D]==1){ddir=-1;}
else{}
if(abs(vexRT[Ch3])>10 && vexRT[Btn8L]==0 || abs(vexRT[Ch4])>10)
{
	SensorValue[Rencoder]=0;
	SensorValue[Lencoder]=0;
	motor[rightDriveBack]=(ddir*vexRT[Ch3]-(ddir*vexRT[Ch4]*.53));
	motor[powerCD]=(ddir*vexRT[Ch3]-(ddir*vexRT[Ch4]*.53));
	motor[rightDriveFrontMID]=(ddir*vexRT[Ch3]-(ddir*vexRT[Ch4]*.53));
	motor[leftDriveBack]=(ddir*vexRT[Ch3]+(ddir*vexRT[Ch4]*.53));
	motor[powerAB]=(ddir*vexRT[Ch3]+(ddir*vexRT[Ch4]*.53));
	motor[leftDriveFrontMID]=(ddir*vexRT[Ch3]+(ddir*vexRT[Ch4]*.53));

}
//else if(abs(vexRT[Ch3])>10 || abs(vexRT[Ch4])>10&& vexRT[Btn5U]==1)
//{
//	motor[rightDriveBack]=vexRT[Ch3]-vexRT[Ch4];
//	motor[rightDriveBackMID]=vexRT[Ch3]-vexRT[Ch4];
//	motor[rightDriveFrontMID]=vexRT[Ch3]-vexRT[Ch4];
//	motor[rightDriveFront]=vexRT[Ch3]-vexRT[Ch4];
//	motor[leftDriveBack]=vexRT[Ch3]+vexRT[Ch4];
//	motor[leftDriveBackMID]=vexRT[Ch3]+vexRT[Ch4];
//	motor[leftDriveFrontMID]=vexRT[Ch3]+vexRT[Ch4];
//	motor[leftDriveFront]=vexRT[Ch3]+vexRT[Ch4];
//}
else if (abs(vexRT[Ch2])>10)
{if(vexRT[Ch2]>0){dir=1;}
	else{dir=-1;}
	if (abs(SensorValue[Rencoder])<(abs(SensorValue[Lencoder]))){Loffset=-dir*10; Roffset=0;}
		else if (abs(SensorValue[Lencoder])<(abs(SensorValue[Rencoder]))){Loffset=0; Roffset=-dir*10;}
		else{Loffset=0; Roffset=0;}
speed=vexRT[Ch2]*.85;
		motor[rightDriveBack]=speed+Roffset;
		motor[powerCD]=speed+Roffset;
		motor[rightDriveFrontMID]=speed+Roffset;
		motor[leftDriveBack]=speed+Loffset;
		motor[powerAB]=speed+Loffset;
		motor[leftDriveFrontMID]=speed+Loffset;

}
else
{
	SensorValue[Rencoder]=0;
	SensorValue[Lencoder]=0;
	motor[rightDriveBack]=0;
	motor[powerCD]=0;
	motor[rightDriveFrontMID]=0;
	motor[leftDriveBack]=0;
	motor[powerAB]=0;
	motor[leftDriveFrontMID]=0;

}



if(vexRT[Btn8U]==1&&vexRT[Btn8R]==0)
{
	SensorValue[piston]=0;
	wait10Msec(4);
	motor[rightMG]=127;
	motor[leftMG]=127;
	mgPOS=0;
}
else if(vexRT[Btn8U]==0&&vexRT[Btn8R]==1&&SensorValue[MGlimit]==0)
{
	motor[rightMG]=-127;
	motor[leftMG]=-127;
	SensorValue[piston]=1;
	mgPOS=1;
}
else if(vexRT[Btn8U]==0&&vexRT[Btn8R]==1&&SensorValue[MGlimit]==1)
{
	motor[rightMG]=-20;
	motor[leftMG]=-20;
}
else if(mgPOS==1)
{
	motor[rightMG]=-5;
	motor[leftMG]=-5;
}
else
{
	motor[rightMG]=0;
	motor[leftMG]=0;
}

if(vexRT[Btn8D]==1)
{SensorValue[piston]=1;}

if(vexRT[Btn8L]==1)
{SensorValue[piston]=0;}