task MGGM()
{clearTimer(T3);
	if(mobi.val<0)
	{
		while (time1[T3]<2000)
		{motor[MG1]=80;motor[MG2]=80;}
	motor[MG1]=0;motor[MG2]=0;
	}
	else{
		while (SensorValue[limit]==0&&time1[T3]<2000)
		{motor[MG1]=-127;motor[MG2]=-127;}
	motor[MG1]=-10;motor[MG2]=-10;
	}
	mobi.val=0;
	stopTask(MGGM);
}


task runD()
{
	if (vexRT[Ch3] > 15 || vexRT[Ch3] < -15 || vexRT[Ch4] > 15 || vexRT[Ch4] < -15)
	{
		dr = (vexRT[Ch3] - vexRT[Ch4]);
		dl = (vexRT[Ch3] + vexRT[Ch4]);
	}
	else
	{
		dr = 0;
		dl = 0;
	}
	if (vexRT[Btn5D] == 1 && SensorValue[limit] == 0)
	{
		mg = 127;
	}
	else if (vexRT[Btn5U] == 1)
	{
		mg = -127;
	}
	else if (SensorValue[limit] == 1)
	{
		mg = 10;
	}
	else
	{
		mg = 0;
	}
	if (vexRT[Btn6U] == 1)
	{
		c = 1;

	}
	else {

		c = 0;
	}
	if (vexRT[Btn6D] == 1)
	{
		p = 1;


	}
	else {

		p = 0;

	}
}