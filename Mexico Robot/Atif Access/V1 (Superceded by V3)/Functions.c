void Do(	int bL,int	bR,int	l,int cp,int cm,int mg,int c)
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
}
