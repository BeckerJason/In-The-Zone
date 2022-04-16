if(abs(vexRT[Ch3])>10)
{
	//motor[driveLeft]=vexRT[Ch3];
	motor[LDriveMid]=vexRT[Ch3];
	motor[CDpower]=vexRT[Ch3];

}
else
{
//	motor[driveLeft]=0;
		motor[RDriveMid]=0;
	motor[ABpower]=0;
}


if(abs(vexRT[Ch2])>10)
{
	//motor[driveRight]=vexRT[Ch2];
		motor[RDriveMid]=vexRT[Ch2];
	motor[ABpower]=vexRT[Ch2];
}
else
{
	//motor[driveLeft]=0;
		motor[RDriveMid]=0;
	motor[ABpower]=0;
}



if(vexRT[Btn5U]==1&&vexRT[Btn5D]==0)
{
	motor[RSlideFr]=127;
	motor[RSlideBa]=127;
	motor[LSlideFr]=127;
	motor[LSlideBa]=127;
}
else if(vexRT[Btn5U]==0&&vexRT[Btn5D]==1)
{
	motor[RSlideFr]=-127;
	motor[RSlideBa]=-127;
	motor[LSlideFr]=-127;
	motor[LSlideBa]=-127;
}
else
{
	motor[RSlideFr]=0;
	motor[RSlideBa]=0;
	motor[LSlideFr]=0;
	motor[LSlideBa]=0;
}



if(vexRT[Btn6U]==1&&vexRT[Btn6D]==0)
{
	motor[FourBar]=127;
}
else if(vexRT[Btn6U]==0&&vexRT[Btn6D]==1)
{
	motor[FourBar]=-127;
}
else
{
	motor[FourBar]=0;
}



if(vexRT[Btn8U]==1&&vexRT[Btn8D]==0)
{
	motor[MG]=127;
}
else if(vexRT[Btn8U]==0&&vexRT[Btn8D]==1)
{
	motor[MG]=-127;
}
else
{
	motor[MG]=0;
}
if(vexRT(Btn8R)==1)
{
	stack();
}
///writeDebugStreamLine("%d", vexRT[Ch3]);
wait1Msec(20);
