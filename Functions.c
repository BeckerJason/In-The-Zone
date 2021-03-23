void Do(	int bL,int	bR,int	l,int cm,int mg,int c,int as, float pm, float sm)
{
	if(as==1)
	{
			motor[LM] = bL;
	motor[L1] = bL;
	motor[RM] = bR;
	motor[R1] = bR;

	motor[leftArm1] = l;
	motor[leftArm2] = l;
	motor[rightArm1] = l;
	motor[rightArm2] = l;

	motor[ClawM]=cm;

	motor[MG]=15;

			/*clearTimer(T3);
		while(time1[T3]<5000&&vexRT[Btn5D]==0)
		{*/
		//claw forward preset
		while (SensorValue[enc]>-460&&vexRT[Btn5D]==0)
		{motor[ClawM]=-127*pm;}
		while (SensorValue[enc]<-450&&vexRT[Btn5D]==0)
		{
			motor[ClawM]=127*pm;
		}
		motor[ClawM]=15*pm;
		//while sonar sees cone {go up}
		while(SensorValue[IR] ==0&&vexRT[Btn5D]==0)
		{motor[leftArm1] = 127*pm;
			motor[leftArm2] = 127*pm;
			motor[rightArm1] =127*pm;
			motor[rightArm2] =127*pm;}
		wait1Msec(125);
		//while(SensorValue[sonar] <  13|| SensorValue[sonar] >50 &&vexRT[Btn6D]==0 )
		//{motor[leftArm1] = 127*pm;
		//motor[leftArm2] = 127*pm;
		//motor[rightArm1] =127*pm;
		//motor[rightArm2] =127*pm;}*/

		//motor[leftArm1] = 0;
		//motor[leftArm2] = 0;
		//motor[rightArm1] = 0;
		//motor[rightArm2] = 0;
		//wait1Msec(100);
		//then scissor = 10 to stay up
		motor[leftArm1] = 15*pm;
		motor[leftArm2] =15*pm;
		motor[rightArm1] =15*pm;
		motor[rightArm2] =15*pm;
		//then claw up
	//	while (SensorValue[enc]<-30&&vexRT[Btn5D]==0)//~~~~~~~~~~~~Add Limit here instead of encoder
			while (SensorValue (Climit)==0&&vexRT[Btn5D]==0)
		{motor[ClawM]=127*pm;}
		motor[ClawM]=10*pm;
		//SensorValue[enc]=0;
		//claw open
				wait1Msec(100);
		SensorValue[claw]=0;
		//ClawStep=4;
		wait1Msec(250);
	/*	while(SensorValue[sonar] >1 && SensorValue[sonar] <7 &&vexRT[Btn5D]==0 ) 		//make the arm go up over the cones

		{motor[leftArm1] = -127*pm;
			motor[leftArm2] = -127*pm;
			motor[rightArm1] =-127*pm;
			motor[rightArm2] =-127*pm;}
			*/
		//claw forward
		while (SensorValue[enc]>-430&&vexRT[Btn5D]==0)
		{motor[ClawM]=-127*pm;}
		motor[ClawM]=10*pm;
		wait1Msec(100);
		//while limit isnt pressed {arm down}
		clearTimer(T1);
		while(SensorValue[limit] ==0&&vexRT[Btn5D]==0&& time1(T1)<2000)
		{motor[leftArm1] = -70*pm;
			motor[leftArm2] = -70*pm;
			motor[rightArm1] =-70*pm;
			motor[rightArm2] =-70*pm;}
		//claw down preset
			clearTimer(T1);
		while (SensorValue[enc]>-580&&vexRT[Btn5D]==0&&time1(T1)<1000)
		{motor[ClawM]=-80*pm;}

		//}
	}
else
{
	motor[LM] = bL;
	motor[L1] = bL;
	motor[RM] = bR;
	motor[R1] = bR;

	motor[leftArm1] = l;
	motor[leftArm2] = l;
	motor[rightArm1] = l;
	motor[rightArm2] = l;

	motor[ClawM]=cm;

	motor[MG]=mg;

	SensorValue[claw]=c;
	wait1Msec(20);// REFRESH SPEED
}

}
