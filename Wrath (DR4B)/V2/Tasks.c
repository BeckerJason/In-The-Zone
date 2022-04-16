task MGGM()
{clearTimer(T3);
	SensorValue[Larm]=0;
	while	(SensorValue(Climit)==0&&vexRT[Btn5D]==0)
	{motor[fb1]=60;
		motor[fb2]=60;
	}
	motor[fb1]=10;
	motor[fb2]=10;
	while (abs(SensorValue[Larm])< 90&&vexRT[Btn5D]==0)
	{motor[rightArm1]=80;
		motor[leftArm1]=80;
	}
	motor[rightArm1]=30;
	motor[leftArm1]=30;
	clearTimer(T3);
	if (mobi.val>2){
		motor[roller]=127;
		motor[rightArm1]=80;
		motor[leftArm1]=80;
		wait1Msec(500);
		motor[rightArm1]=20;
		motor[leftArm1]=20;
		while (SensorValue[pot]<2600&&vexRT[Btn5D]==0){	motor[MG]=127;}
		while (SensorValue[pot]<2600&&vexRT[Btn5D]==0){motor[MG]=50;}}
	else if (mobi.val>1){while (SensorValue[pot]<2600&&vexRT[Btn5D]==0){motor[MG]=127;}}
	else if(mobi.val>0){while (SensorValue[pot]<1000&&vexRT[Btn5D]==0){motor[MG]=127;}
		while (SensorValue[pot]<2600&&vexRT[Btn5D]==0){motor[MG]=50;}}
	else{while (SensorValue[pot]>250&&vexRT[Btn5D]==0){motor[MG]=-127;}}

	motor[MG]=0;

	motor[rightArm1]=0;
	motor[leftArm1]=0;
	motor[fb1]=0;
	motor[fb2]=0;
	mobi.val=0;
	stopTask(MGGM);
}
