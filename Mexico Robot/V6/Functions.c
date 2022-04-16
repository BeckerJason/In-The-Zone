void D(	int bL,int	bR,int	l,int cm,int mg,int c,int as, float pm, float sm)
{
	if(as==1)
	{	motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] = 0;

		motor[leftArm1] = 0;
		motor[leftArm2] = 0;
		motor[rightArm1] = 0;
		motor[rightArm2] = 0;

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
			*/motor[leftArm1] = 127*pm;
			motor[leftArm2] = 127*pm;
			motor[rightArm1] =127*pm;
			motor[rightArm2] =127*pm;
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
		motor[leftArm1] = 15*pm;
		motor[leftArm2] = 15*pm;
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
		{motor[leftArm1] =-70*pm;
			motor[leftArm2] = -70*pm;
			motor[rightArm1] =-70*pm;
			motor[rightArm2] =-70*pm;}
		//claw down preset
		clearTimer(T1);
		while (abs(SensorValue[enc])<580&&vexRT[Btn5D]==0&&time1(T1)<1000)
		{motor[ClawM]=-80*pm;}
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

void M(int count,int dir,int speed, float sm) //encoder count, direction , speed, primary voltage mult
{SensorValue[Renc]=0;
	SensorValue[Lenc]=0;
	if (dir==1)
	{
		while (abs(SensorValue[Lenc])<count)
		{
			if(abs(SensorValue[Lenc])>abs(SensorValue[Renc])+5)
			{
				motor[LM] = speed*sm*.8;
				motor[L1] = speed*sm*.8;
				motor[RM] = speed*sm;
				motor[R1] = speed*sm;
			}
			else if(abs(SensorValue[Lenc])<abs(SensorValue[Renc])-5)
			{
				motor[LM] = speed*sm;
				motor[L1] = speed*sm;
				motor[RM] = speed*sm*.8;
				motor[R1] = speed*sm*.8;
			}
			else
			{
				motor[LM] = speed*sm;
				motor[L1] = speed*sm;
				motor[RM] = speed*sm;
				motor[R1] = speed*sm;
			}
		}
				motor[LM] = -speed*sm/4;
				motor[L1] = -speed*sm/4;
				motor[RM] = -speed*sm/4;
				motor[R1] = -speed*sm/4;
				wait1Msec(200);
		}

	else if (dir==-1)
	{
		while (abs(SensorValue[Lenc])<count)
		{
			if(abs(SensorValue[Lenc])>abs(SensorValue[Renc])-5)
			{
				motor[LM] = -speed*sm*.8;
				motor[L1] = -speed*sm*.8;
				motor[RM] = -speed*sm;
				motor[R1] = -speed*sm;
			}


			else if(abs(SensorValue[Lenc])<abs(SensorValue[Renc])+5)
			{
				motor[LM] = -speed*sm;
				motor[L1] = -speed*sm;
				motor[RM] = -speed*sm*.8;
				motor[R1] = -speed*sm*.8;
			}
			else
			{
				motor[LM] = -speed*sm;
				motor[L1] = -speed*sm;
				motor[RM] = -speed*sm;
				motor[R1] = -speed*sm;
			}

		}
				motor[LM] = speed*sm/4;
				motor[L1] = speed*sm/4;
				motor[RM] = speed*sm/4;
				motor[R1] = speed*sm/4;
				wait1Msec(100);
	}
	else{}
	motor[LM] = 0;
				motor[L1] = 0;
				motor[RM] = 0;
				motor[R1] = 0;
}


void T(int deg,int speed, int time,float sm)
{int dir;
	if (deg>0){dir=1;}
	else if (deg<0){dir=-1;}
	else{}
	while((abs(SensorValue[in7])/10)<abs(deg))
	{	if ((abs(SensorValue[in7])/10)<(abs(deg)-30))
	{
		motor[LM] = dir*speed*sm;
		motor[L1] = dir*speed*sm;
		motor[RM] = -dir*speed*sm;
		motor[R1] = -dir*speed*sm;}
		else if ((abs(SensorValue[in7])/10)<(abs(deg)-15))
	{
		motor[LM] = dir*speed*sm/2;
		motor[L1] = dir*speed*sm/2;
		motor[RM] = -dir*speed*sm/2;
		motor[R1] = -dir*speed*sm/2;}
		else
		{motor[LM] = dir*speed*sm/3;
		motor[L1] = dir*speed*sm/3;
		motor[RM] = -dir*speed*sm/3;
		motor[R1] = -dir*speed*sm/3;}
	}
	wait1Msec(time);
	while(abs(SensorValue[in7])/10>abs(deg))
	{	motor[LM] = -dir*speed*sm/2;
		motor[L1] = -dir*speed*sm/2;
		motor[RM] = dir*speed*sm/2;
		motor[R1] = dir*speed*sm/2;}
	wait1Msec(time);
	while(abs(SensorValue[in7])/10<abs(deg))
	{	motor[LM] = dir*speed*sm/3;
		motor[L1] = dir*speed*sm/3;
		motor[RM] = -dir*speed*sm/3;
		motor[R1] = -dir*speed*sm/3;}
//motor[LM] = -dir*10*sm;
//		motor[L1] = -dir*10*sm;
//		motor[RM] = dir*10*sm;
//		motor[R1] = dir*10*sm;
	//wait1Msec(100);
			motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] =0;
}



void S(int pm, int sm )// Primary Voltage Mult, Secondary Voltage Mult
{		motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] = 0;

		motor[leftArm1] = 0;
		motor[leftArm2] = 0;
		motor[rightArm1] = 0;
		motor[rightArm2] = 0;

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
			*/motor[leftArm1] = 127*pm;
			motor[leftArm2] = 127*pm;
			motor[rightArm1] =127*pm;
			motor[rightArm2] =127*pm;
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
		motor[leftArm1] = 15*pm;
		motor[leftArm2] = 15*pm;
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
		if(SensorValue[limit] ==0)
		{
		while(SensorValue[limit] ==0&&vexRT[Btn5D]==0&& time1(T1)<2000)
		{motor[leftArm1] =-70*pm;
			motor[leftArm2] = -70*pm;
			motor[rightArm1] =-70*pm;
			motor[rightArm2] =-70*pm;}
		}
		//claw down preset
		clearTimer(T3);
		while (abs(SensorValue[enc])<600&&time1(T3)<1000)
		{motor[ClawM]=-127*pm;}
motor[ClawM]=0;
}

void MGM(int speed, int time,int pm)
{
	clearTimer(T3);
	while(T3<time)
{motor[MG]=speed;}
motor[MG]=-10;
}

void CM(int count, int speed, int pm)
{
//int T3;
//	clearTimer(T3);
	if(SensorValue[enc]>count){
		while (SensorValue[enc]>count)
		{motor[ClawM]=-speed*pm;}}
	else if(SensorValue[enc]<count){
		while (SensorValue[enc]<count)
		{motor[ClawM]=speed*pm;}}
motor[ClawM]=-10*pm;
}

void C(int val)
{if (val==1){SensorValue[claw]=1;}
	else{SensorValue[claw]=0;}
}
//Forward 360 ticks speed 127 :: M(360,1,127, sm);
//Turn left 90 at 127					:: T(-90, 127, 200, sm);
//Stack a cone 								:: S(pm, sm);
//Claw motor up at 127				:: CM(300,127,pm);
//Claw close									:: C(1);
