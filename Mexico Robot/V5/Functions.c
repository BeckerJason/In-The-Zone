void D(	int bL,int	bR,int	l,int cm,int mg,int c,int as, float pm, float sm)
{
	if(as==1)
	{	motor[LM] = 0;
	motor[L1] = 0;
	motor[L2] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
	motor[R2] = 0;

	motor[leftArm] = 0;
	motor[rightArm] = 0;

	motor[ClawM]=0;

	motor[MG]=15;

	/*clearTimer(T3);
	while(time1[T3]<5000&&vexRT[Btn5D]==0)
	{*/
	motor[ClawM]=15*pm;
	//while sonar sees cone {go up}
	while(SensorValue[IR] ==0&&vexRT[Btn5D]==0)
	{
		if (SensorValue[enc]<-450&&vexRT[Btn5D]==0)
		{
			motor[ClawM]=127*pm;
		}
		else{motor[ClawM]=15;}
		/*if (abs(SensorValue[I2C_1])<abs(SensorValue[I2C_1])+10)
		{motor[leftArm] = 127*pm*.9;
		motor[rightArm] =127*pm;}

			else if (abs(SensorValue[I2C_1])>abs(SensorValue[I2C_1])-10)
		{motor[leftArm] = 127*pm;
		motor[rightArm] =127*pm*.9;}

		else{motor[leftArm] = 127*pm;
		motor[rightArm] =127*pm;}
		*/motor[leftArm] = 127*pm;
		motor[rightArm] =127*pm;
		}
	//claw forward preset
	//while (SensorValue[enc]>-460&&vexRT[Btn5D]==0)
	//{motor[ClawM]=-127*pm;}
	while (SensorValue[enc]<-450&&vexRT[Btn5D]==0)
	{
		motor[ClawM]=127*pm;
	}
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
	motor[leftArm] = 15*pm;
	motor[rightArm] =15*pm;
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
	{motor[leftArm] = -70*pm;
		motor[rightArm] =-70*pm;}
	//claw down preset
	clearTimer(T1);
	while (abs(SensorValue[enc])<580&&vexRT[Btn5D]==0&&time1(T1)<1000)
	{motor[ClawM]=-80*pm;}
	}
	else
	{
		motor[LM] = bL;
		motor[L1] = bL;
		motor[L2] = bL;
		motor[RM] = bR;
		motor[R1] = bR;
		motor[R2] = bR;

		motor[leftArm] = l;
		motor[rightArm] = l;

		motor[ClawM]=cm;

		motor[MG]=mg;

		SensorValue[claw]=c;
		wait1Msec(30);// REFRESH SPEED
	}

}

void M(int count,int dir,int speed, float pm) //encoder count, direction , speed, primary voltage mult
{SensorValue[Renc]=0;
	SensorValue[Lenc]=0;
	if (dir==-1)
	{
		while (abs(SensorValue[enc])<count)
		{
			if(abs(SensorValue[Lenc])>abs(SensorValue[Renc])+5)
			{
				motor[LM] = speed*pm*.8;
				motor[L1] = speed*pm*.8;
				motor[L2] = speed*pm*.8;
				motor[RM] = speed*pm;
				motor[R1] = speed*pm;
				motor[R2] = speed*pm;
			}
			else if(abs(SensorValue[Lenc])<abs(SensorValue[Renc])-5)
			{
				motor[LM] = speed*pm;
				motor[L1] = speed*pm;
				motor[L2] = speed*pm;
				motor[RM] = speed*pm*.8;
				motor[R1] = speed*pm*.8;
				motor[R2] = speed*pm*.8;
			}
			else
			{
				motor[LM] = speed*pm;
				motor[L1] = speed*pm;
				motor[L2] = speed*pm;
				motor[RM] = speed*pm;
				motor[R1] = speed*pm;
				motor[R2] = speed*pm;
			}
		}
	}

	else if (dir==1)
	{
		while (abs(SensorValue[enc])<count)
		{
			if(abs(SensorValue[Lenc])>abs(SensorValue[Renc])-5)
			{
				motor[LM] = -speed*pm*.8;
				motor[L1] = -speed*pm*.8;
				motor[L2] = -speed*pm*.8;
				motor[RM] = -speed*pm;
				motor[R1] = -speed*pm;
				motor[R2] = -speed*pm;
			}


			else if(abs(SensorValue[Lenc])<abs(SensorValue[Renc])+5)
			{
				motor[LM] = -speed*pm;
				motor[L1] = -speed*pm;
				motor[L2] = -speed*pm;
				motor[RM] = -speed*pm*.8;
				motor[R1] = -speed*pm*.8;
				motor[R2] = -speed*pm*.8;
			}
			else
			{
				motor[LM] = -speed*pm;
				motor[L1] = -speed*pm;
				motor[L2] = -speed*pm;
				motor[RM] = -speed*pm;
				motor[R1] = -speed*pm;
				motor[R2] = -speed*pm;
			}
		}
	}
	else{}
}
void T(int deg,int speed, int time,int pm)
{int dir;
	if (deg>0){dir=1;}
	else if (deg<0){dir=-1;}
	else{}
	while(abs(SensorValue[gyro])<deg)
	{	motor[LM] = dir*speed*pm;
		motor[L1] = dir*speed*pm;
		motor[L2] = dir*speed*pm;
		motor[RM] = -dir*speed*pm;
		motor[R1] = -dir*speed*pm;
		motor[R2] = -dir*speed*pm;}
	wait1Msec(time);
	while(abs(SensorValue[gyro])>deg)
	{	motor[LM] = -dir*speed*pm/2;
		motor[L1] = -dir*speed*pm/2;
		motor[L2] = -dir*speed*pm/2;
		motor[RM] = dir*speed*pm/2;
		motor[R1] = dir*speed*pm/2;
		motor[R2] = dir*speed*pm/2;}
	wait1Msec(time);
	while(abs(SensorValue[gyro])<deg)
	{	motor[LM] = dir*speed*pm/4;
		motor[L1] = dir*speed*pm/4;
		motor[L2] = dir*speed*pm/4;
		motor[RM] = -dir*speed*pm/4;
		motor[R1] = -dir*speed*pm/4;
		motor[R2] = -dir*speed*pm/4;}
}
void S(int pm, int sm )// Primary Voltage Mult, Secondary Voltage Mult
{	motor[LM] = 0;
	motor[L1] = 0;
	motor[L2] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
	motor[R2] = 0;

	motor[leftArm] = 0;
	motor[rightArm] = 0;

	motor[ClawM]=0;

	motor[MG]=15;

	/*clearTimer(T3);
	while(time1[T3]<5000&&vexRT[Btn5D]==0)
	{*/
	motor[ClawM]=15*pm;
	//while sonar sees cone {go up}
	while(SensorValue[IR] ==0&&vexRT[Btn5D]==0)
	{
		if (SensorValue[enc]<-450&&vexRT[Btn5D]==0)
		{
			motor[ClawM]=127*pm;
		}
		else{motor[ClawM]=15;}
		motor[leftArm] = 127*pm;
		motor[rightArm] =127*pm;}
	//claw forward preset
	//while (SensorValue[enc]>-460&&vexRT[Btn5D]==0)
	//{motor[ClawM]=-127*pm;}
	while (SensorValue[enc]<-450&&vexRT[Btn5D]==0)
	{
		motor[ClawM]=127*pm;
	}
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
	motor[leftArm] = 15*pm;
	motor[rightArm] =15*pm;
	//then claw up
	//	while (SensorValue[enc]<-30&&vexRT[Btn5D]==0)//~~~~~~~~~~~~Add Limit here instead of encoder
	while (SensorValue (Climit)==0&&vexRT[Btn5D]==0)
	{motor[ClawM]=127*pm;}
	motor[ClawM]=10*pm;
	//SensorValue[enc]=0;
	//claw open
	wait1Msec(100)

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
	{motor[leftArm] = -70*pm;
		motor[rightArm] =-70*pm;}
	//claw down preset
	clearTimer(T1);
	while (abs(SensorValue[enc])<580&&vexRT[Btn5D]==0&& time1(T1)<1000)
	{motor[ClawM]=-80*pm;}
motor[ClawM]=0;
}

void CM(int count, int speed, int pm, int sm)
{int T3;
	clearTimer(T3);
	if(SensorValue[enc]>count){
		while (SensorValue[enc]>count)
		{motor[ClawM]=-127*pm;}}
	if(SensorValue[enc]<count){
		while (SensorValue[enc]<count)
		{motor[ClawM]=127*pm;}}
}



//Forward 360 ticks speed 127 :: M(360,1,127, pm);
//Turn left 90 at 127					:: T(-90, 127, 200, pm);
//Stack a cone 								:: S(pm, sm);
//Claw motor up at 127
