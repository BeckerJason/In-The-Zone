
if(vexRT[Ch3] > 15 || vexRT[Ch3] < -15 || vexRT[Ch4] > 15 || vexRT[Ch4] < -15)
{
	motor[RM]  = (vexRT[Ch3] - vexRT[Ch4]);
	motor[R1]  = (vexRT[Ch3] - vexRT[Ch4]);
	motor[R2]  = (vexRT[Ch3] - vexRT[Ch4]);
	motor[LM]  = (vexRT[Ch3] + vexRT[Ch4]);
	motor[L2]  = (vexRT[Ch3] + vexRT[Ch4]);
	motor[L1]  = (vexRT[Ch3] + vexRT[Ch4]);
}
else
{
	motor[RM]  = 0;
	motor[R1]  = 0;

	motor[R2]  = 0;

	motor[MG2]  = 0;
	motor[MG1]  = 0;
	motor[L2]  = 0;
	motor[LM]  = 0;
	motor[L1]  = 0;
}
if(vexRT[Btn5D] == 1&& SensorValue[limit]==0)
{
	motor[MG1] = 127;
	motor[MG2] = 127;
}
else if(vexRT[Btn5U] == 1)
{
	motor[MG1] = -127;
	motor[MG2] = -127;
}
else if(SensorValue[limit]==1)
{
	motor[MG1] = 10;
	motor[MG2] = 10;
}
else
{
	motor[MG1] = 0;
	motor[MG2] = 0;
}
if(vexRT[Btn6U] == 1)
{
	SensorValue[claw1]=1;
	SensorValue[claw2]=1;

}
else{

	SensorValue[claw1]=0;
	SensorValue[claw2]=0;
}
if(vexRT[Btn6D] == 1)
{
	SensorValue[push]=1;


}
else{

	SensorValue[push]=0;

}


wait1Msec(20);
