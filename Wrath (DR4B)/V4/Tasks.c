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

task S()
{
	//************************************************************************ STACK ****************************

	motor[roller]=-25;
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;

	motor[leftArm1] = 0;
	motor[rightArm1] = 0;

	motor[fb1]=0;
	motor[fb2]=0;

	motor[MG]=0;
	motor[fb1]=15*pr.mult;motor[fb2]=15*pr.mult;


	while(SensorValue[IR] ==0&&vexRT[Btn5D]==0) ///while the robot sees a cone
	{
		motor[leftArm1] = 127*pr.mult;	///Bring lift up
		motor[rightArm1] =127*pr.mult;
	}

	motor[leftArm1] = 15*pr.mult;  //Keep lift up
	motor[rightArm1] =15*pr.mult;

	while (SensorValue[Climit]==0&&vexRT[Btn5D]==0)
	{
		motor[fb1]=127*pr.mult;/////Bring 4 bar up
		motor[fb2]=127*pr.mult;
	}
	motor[MG]=-5;
	motor[fb1]=15*pr.mult;		//Keep 4 bar up
	motor[fb2]=15*pr.mult;
	motor[leftArm1] = -40*pr.mult;	//Bring Lift down to stack cone
	motor[rightArm1] =-40*pr.mult;
	wait1Msec(250);
	motor[roller]=127; //Roll cone out
	wait1Msec(100);
	playSoundFile("boom3.wav");
	while(SensorValue[IR] ==0&&vexRT[Btn5D]==0)
	{
		motor[roller]=127; //Roll cone out
		motor[leftArm1] = 65*pr.mult;	//Bring Lift up while rolling cone out
		motor[rightArm1] =65*pr.mult;
	}
	motor[leftArm1] = 15*pr.mult;  //Keep lift up
	motor[rightArm1] =15*pr.mult;
	motor[fb1]=-127*pr.mult;/////Bring 4 bar down before bringing lift down
	motor[fb2]=-127*pr.mult;
	wait1Msec(300);
	motor[fb1]=-10*pr.mult;/////Bring 4 bar down before bringing lift down
	motor[fb2]=-10*pr.mult;
	while (SensorValue[limit]==0&&vexRT[Btn5D]==0)
	{
		motor[leftArm1] = -30*pr.mult;	//Bring Lift down to puck up next cone
		motor[rightArm1] =-30*pr.mult;
	}
	motor[MG]=0;
	motor[fb1]=0;
	motor[fb2]=0;
	motor[leftArm1] = 0;	//kill all
	motor[rightArm1] =0;
	mobi.stack=0;
stopTask(S);
}
//************************************************************************ STACK ****************************
