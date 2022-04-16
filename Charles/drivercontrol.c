

if(abs(vexRT[Ch3])>10 && vexRT[Btn8L]==0 || abs(vexRT[Ch4])>10 && vexRT[Btn5U]==0)
{
	motor[rightDriveBack]=(vexRT[Ch3]-(vexRT[Ch4]*.53))*.85;
	motor[powerCD]=(vexRT[Ch3]-(vexRT[Ch4]*.53))*.85;
	motor[rightDriveFrontMID]=(vexRT[Ch3]-(vexRT[Ch4]*.53))*.85;
	motor[leftDriveBack]=(vexRT[Ch3]+(vexRT[Ch4]*.53))*.85;
	motor[powerAB]=(vexRT[Ch3]+(vexRT[Ch4]*.53))*.85;
	motor[leftDriveFrontMID]=(vexRT[Ch3]+(vexRT[Ch4]*.53))*.85;

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
else
{
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
