void DoB(	int bL,int	bR)
{
	motor[LM] = bL;
	motor[L1] = bL;
	motor[RM] = bR;
	motor[R1] = bR;

}
void AoB(int	l,int cp,int cm,int mg,int c, int PMult, int as)
{
	if(as==1)
	{
		/*clearTimer(T3);
		while(time1[T3]<5000&&vexRT[Btn5D]==0)
		{*/
		//claw forward preset
		while (SensorValue[enc]>-460)
		{motor[ClawM]=-127*PMult;}
		while (SensorValue[enc]<-450)
		{
			motor[ClawM]=127;
			}
		motor[ClawM]=15*PMult;
		//while sonar sees cone {go up}
		while(SensorValue[sonar] >1 && SensorValue[sonar] <8 &&vexRT[Btn6D]==0)
		{motor[leftArm1] = 127*PMult;
			motor[leftArm2] = 127*PMult;
			motor[rightArm1] =127*PMult;
			motor[rightArm2] =127*PMult;}
			wait1Msec(100);
		//while(SensorValue[sonar] <  13|| SensorValue[sonar] >50 &&vexRT[Btn6D]==0 )
		//{motor[leftArm1] = 127*PMult;
		//motor[leftArm2] = 127*PMult;
		//motor[rightArm1] =127*PMult;
		//motor[rightArm2] =127*PMult;}*/

		//motor[leftArm1] = 0;
		//motor[leftArm2] = 0;
		//motor[rightArm1] = 0;
		//motor[rightArm2] = 0;
		//wait1Msec(100);
		//then scissor = 10 to stay up
		motor[leftArm1] = 15*PMult;
		motor[leftArm2] =15*PMult;
		motor[rightArm1] =15*PMult;
		motor[rightArm2] =15*PMult;
		//then claw up
		while (SensorValue[enc]<-30)//~~~~~~~~~~~~Add Limit here instead of encoder
		{motor[ClawM]=127*PMult;}
		motor[ClawM]=10*PMult;
		wait1Msec(100);
		SensorValue[enc]=0;
		//claw open
		SensorValue[claw]=0;
		//ClawStep=4;
		wait1Msec(100);
		while(SensorValue[sonar] >1 && SensorValue[sonar] <7 &&vexRT[Btn6D]==0 )
		{motor[leftArm1] = 127*PMult;
			motor[leftArm2] = 127*PMult;
			motor[rightArm1] =127*PMult;
			motor[rightArm2] =127*PMult;}
		//claw forward
		while (SensorValue[enc]>-430)
		{motor[ClawM]=-127*PMult;}
		motor[ClawM]=10*PMult;
		wait1Msec(100);
		//while limit isnt pressed {arm down}
		while(SensorValue[limit] ==0)
		{motor[leftArm1] = -50*PMult;
			motor[leftArm2] = -50*PMult;
			motor[rightArm1] =-50*PMult;
			motor[rightArm2] =-50*PMult;}
		//claw down preset
		while (SensorValue[enc]>-630)
		{motor[ClawM]=-80*PMult;}

		//}
	}
	else
	{
		motor[leftArm1] = l;
		motor[leftArm2] = l;
		motor[rightArm1] = l;
		motor[rightArm2] = l;

		motor[ClawM]=cm;

		motor[MG]=mg;

		SensorValue[claw]=c;
	}
}
