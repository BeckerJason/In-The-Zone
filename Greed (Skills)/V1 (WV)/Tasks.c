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
