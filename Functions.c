void D(	int bL,int	bR,int	l,int cm,int mg,int c)
{
	motor[LM] = bL;
	motor[L1] = bL;
	motor[RM] = bR;
	motor[R1] = bR;
	if(abs(SensorValue[I2C_1])>abs(SensorValue[I2C_2])+5)
	{
		motor[leftArm1] = l*pr.mult*.8;
		motor[leftArm2] = l*pr.mult*.8;
		motor[rightArm1] = l*pr.mult;
		motor[rightArm2] = l*pr.mult;
	}
	else if(abs(SensorValue[I2C_2])<abs(SensorValue[I2C_1])-5)
	{
		motor[leftArm1] = l*pr.mult;
		motor[leftArm2] = l*pr.mult;
		motor[rightArm1] = l*pr.mult*.8;
		motor[rightArm2] = l*pr.mult*.8;
	}
	else
	{
		motor[leftArm1] = l*pr.mult;
		motor[leftArm2] = l*pr.mult;
		motor[rightArm1] = l*pr.mult;
		motor[rightArm2] = l*pr.mult;
	}
	//motor[leftArm1] = l;
	//motor[leftArm2] = l;
	//motor[rightArm1] = l;
	//motor[rightArm2] = l;

	motor[ClawM]=cm;

	motor[MG]=mg;

	SensorValue[claw]=c;
	wait1Msec(20);// REFRESH SPEED


}


void DS()
{
	motor[LM] = 0;
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
	motor[ClawM]=15*pr.mult;
	//while sonar sees cone {go up}
	while(SensorValue[IR] ==0&&vexRT[Btn5D]==0)
	{
		if (SensorValue[enc]<-450&&vexRT[Btn5D]==0)
		{
			motor[ClawM]=127*pr.mult;
		}
		else{motor[ClawM]=15;}
		/*if (abs(SensorValue[I2C_1])<abs(SensorValue[I2C_1])+10)
		{motor[leftArm] = 127*pr.mult*.9;
		motor[rightArm] =127*pr.mult;}

		else if (abs(SensorValue[I2C_1])>abs(SensorValue[I2C_1])-10)
		{motor[leftArm] = 127*pr.mult;
		motor[rightArm] =127*pr.mult*.9;}

		else{motor[leftArm] = 127*pr.mult;
		motor[rightArm] =127*pr.mult;}
		*/motor[leftArm1] = 127*pr.mult;
		motor[leftArm2] = 127*pr.mult;
		motor[rightArm1] =127*pr.mult;
		motor[rightArm2] =127*pr.mult;
	}
	//claw forward preset
	//while (SensorValue[enc]>-460&&vexRT[Btn5D]==0)
	//{motor[ClawM]=-127*pr.mult;}
	while (SensorValue[enc]<-450&&vexRT[Btn5D]==0)
	{
		motor[ClawM]=127*pr.mult;
	}
	wait1Msec(125);
	//while(SensorValue[sonar] <  13|| SensorValue[sonar] >50 &&vexRT[Btn6D]==0 )
	//{motor[leftArm1] = 127*pr.mult;
	//motor[leftArm2] = 127*pr.mult;
	//motor[rightArm1] =127*pr.mult;
	//motor[rightArm2] =127*pr.mult;}*/

	//motor[leftArm1] = 0;
	//motor[leftArm2] = 0;
	//motor[rightArm1] = 0;
	//motor[rightArm2] = 0;
	//wait1Msec(100);
	//then scissor = 10 to stay up
	motor[leftArm1] = 15*pr.mult;
	motor[leftArm2] = 15*pr.mult;
	motor[rightArm1] =15*pr.mult;
	motor[rightArm2] =15*pr.mult;
	//then claw up
	//	while (SensorValue[enc]<-30&&vexRT[Btn5D]==0)//~~~~~~~~~~~~Add Limit here instead of encoder
	while (SensorValue (Climit)==0&&vexRT[Btn5D]==0)
	{motor[ClawM]=127*pr.mult;}
	motor[ClawM]=10*pr.mult;
	//SensorValue[enc]=0;
	//claw open
	wait1Msec(100);
	SensorValue[claw]=0;
	//ClawStep=4;
	wait1Msec(250);
	/*	while(SensorValue[sonar] >1 && SensorValue[sonar] <7 &&vexRT[Btn5D]==0 ) 		//make the arm go up over the cones

	{motor[leftArm1] = -127*pr.mult;
	motor[leftArm2] = -127*pr.mult;
	motor[rightArm1] =-127*pr.mult;
	motor[rightArm2] =-127*pr.mult;}
	*/
	//claw forward
	while (SensorValue[enc]>-430&&vexRT[Btn5D]==0)
	{motor[ClawM]=-127*pr.mult;}
	motor[ClawM]=10*pr.mult;
	wait1Msec(100);
	//while limit isnt pressed {arm down}
	clearTimer(T1);
	while(SensorValue[limit] ==0&&vexRT[Btn5D]==0&& time1(T1)<2000)
	{motor[leftArm1] =-70*pr.mult;
		motor[leftArm2] = -70*pr.mult;
		motor[rightArm1] =-70*pr.mult;
		motor[rightArm2] =-70*pr.mult;}
	//claw down preset
	clearTimer(T1);
	while (abs(SensorValue[enc])<580&&vexRT[Btn5D]==0&&time1(T1)<1000)
	{motor[ClawM]=-80*pr.mult;}
}
void M(int count,int dir,int speed) //encoder count, direction , speed, primary voltage mult
{SensorValue[Renc]=0;
	SensorValue[Lenc]=0;
	if (dir==1)
	{
		while (abs(SensorValue[Lenc])<count)
		{
			if(abs(SensorValue[Lenc])>abs(SensorValue[Renc])+5)
			{
				motor[LM] = speed*se.mult*.8;
				motor[L1] = speed*se.mult*.8;
				motor[RM] = speed*se.mult;
				motor[R1] = speed*se.mult;
			}
			else if(abs(SensorValue[Lenc])<abs(SensorValue[Renc])-5)
			{
				motor[LM] = speed*se.mult;
				motor[L1] = speed*se.mult;
				motor[RM] = speed*se.mult*.8;
				motor[R1] = speed*se.mult*.8;
			}
			else
			{
				motor[LM] = speed*se.mult;
				motor[L1] = speed*se.mult;
				motor[RM] = speed*se.mult;
				motor[R1] = speed*se.mult;
			}
		}
		motor[LM] = -speed*se.mult/4;
		motor[L1] = -speed*se.mult/4;
		motor[RM] = -speed*se.mult/4;
		motor[R1] = -speed*se.mult/4;
		wait1Msec(200);
	}

	else if (dir==-1)
	{
		while (abs(SensorValue[Lenc])<count)
		{
			if(abs(SensorValue[Lenc])>abs(SensorValue[Renc])-5)
			{
				motor[LM] = -speed*se.mult*.8;
				motor[L1] = -speed*se.mult*.8;
				motor[RM] = -speed*se.mult;
				motor[R1] = -speed*se.mult;
			}


			else if(abs(SensorValue[Lenc])<abs(SensorValue[Renc])+5)
			{
				motor[LM] = -speed*se.mult;
				motor[L1] = -speed*se.mult;
				motor[RM] = -speed*se.mult*.8;
				motor[R1] = -speed*se.mult*.8;
			}
			else
			{
				motor[LM] = -speed*se.mult;
				motor[L1] = -speed*se.mult;
				motor[RM] = -speed*se.mult;
				motor[R1] = -speed*se.mult;
			}

		}
		motor[LM] = speed*se.mult/4;
		motor[L1] = speed*se.mult/4;
		motor[RM] = speed*se.mult/4;
		motor[R1] = speed*se.mult/4;
		wait1Msec(100);
	}
	else{}
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
}


void T(int deg,int speed, int time)
{int dir;
	if (deg>0){dir=1;}
	else if (deg<0){dir=-1;}
	else{}
	while((abs(SensorValue[in7])/10)<abs(deg))
	{	if ((abs(SensorValue[in7])/10)<(abs(deg)-30))
		{
			motor[LM] = dir*speed*se.mult;
			motor[L1] = dir*speed*se.mult;
			motor[RM] = -dir*speed*se.mult;
			motor[R1] = -dir*speed*se.mult;}
		else if ((abs(SensorValue[in7])/10)<(abs(deg)-15))
		{
			motor[LM] = dir*speed*se.mult/2;
			motor[L1] = dir*speed*se.mult/2;
			motor[RM] = -dir*speed*se.mult/2;
			motor[R1] = -dir*speed*se.mult/2;}
		else
		{motor[LM] = dir*speed*se.mult/3;
			motor[L1] = dir*speed*se.mult/3;
			motor[RM] = -dir*speed*se.mult/3;
			motor[R1] = -dir*speed*se.mult/3;}
	}
	wait1Msec(time);
	while(abs(SensorValue[in7])/10>abs(deg))
	{	motor[LM] = -dir*speed*se.mult/2;
		motor[L1] = -dir*speed*se.mult/2;
		motor[RM] = dir*speed*se.mult/2;
		motor[R1] = dir*speed*se.mult/2;}
	wait1Msec(time);
	while(abs(SensorValue[in7])/10<abs(deg))
	{	motor[LM] = dir*speed*se.mult/3;
		motor[L1] = dir*speed*se.mult/3;
		motor[RM] = -dir*speed*se.mult/3;
		motor[R1] = -dir*speed*se.mult/3;}
	//motor[LM] = -dir*10*se.mult;
	//		motor[L1] = -dir*10*se.mult;
	//		motor[RM] = dir*10*se.mult;
	//		motor[R1] = dir*10*se.mult;
	//wait1Msec(100);
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] =0;
}


void PL()// Primary Voltage Mult, Secondary Voltage Mult
{	while (vexRT[Btn7R]==0)
	{
		motor[LM] = 0;
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
		motor[ClawM]=15*pr.mult;
		//while sonar sees cone {go up

		while (SensorValue[enc]>-315&&vexRT[Btn5D]==0&&vexRT[Btn7R]==0)
		{
			motor[ClawM]=-127*pr.mult;
		}
		motor[ClawM]=15;
		writeDebugStreamLine("1");
		/*if (abs(SensorValue[I2C_1])<abs(SensorValue[I2C_1])+10)
		{motor[leftArm] = 127*pr.mult*.9;
		motor[rightArm] =127*pr.mult;}

		else if (abs(SensorValue[I2C_1])>abs(SensorValue[I2C_1])-10)
		{motor[leftArm] = 127*pr.mult;
		motor[rightArm] =127*pr.mult*.9;}

		else{motor[leftArm] = 127*pr.mult;
		motor[rightArm] =127*pr.mult;}
		*/
		SensorValue[claw]=1;
		wait1Msec(300);
		while(SensorValue[IR] ==0&&vexRT[Btn5D]==0&&vexRT[Btn7R]==0)
		{
			motor[leftArm1] = 127*pr.mult;
			motor[leftArm2] = 127*pr.mult;
			motor[rightArm1] =127*pr.mult;
			motor[rightArm2] =127*pr.mult;
		}
		writeDebugStreamLine("2");
		//claw forward preset
		//while (SensorValue[enc]>-460&&vexRT[Btn5D]==0)
		//{motor[ClawM]=-127*pr.mult;}
		while (SensorValue[enc]<-450&&vexRT[Btn5D]==0&&vexRT[Btn7R]==0)
		{
			motor[ClawM]=127*pr.mult;
		}
		writeDebugStreamLine("3");
		wait1Msec(125);
		//while(SensorValue[sonar] <  13|| SensorValue[sonar] >50 &&vexRT[Btn6D]==0 )
		//{motor[leftArm1] = 127*pr.mult;
		//motor[leftArm2] = 127*pr.mult;
		//motor[rightArm1] =127*pr.mult;
		//motor[rightArm2] =127*pr.mult;}*/

		//motor[leftArm1] = 0;
		//motor[leftArm2] = 0;
		//motor[rightArm1] = 0;
		//motor[rightArm2] = 0;
		//wait1Msec(100);
		//then scissor = 10 to stay up
		motor[leftArm1] = 15*pr.mult;
		motor[leftArm2] = 15*pr.mult;
		motor[rightArm1] =15*pr.mult;
		motor[rightArm2] =15*pr.mult;
		//then claw up
		//	while (SensorValue[enc]<-30&&vexRT[Btn5D]==0)//~~~~~~~~~~~~Add Limit here instead of encoder
		while (SensorValue (Climit)==0&&vexRT[Btn5D]==0&&vexRT[Btn7R]==0)
		{motor[ClawM]=127*pr.mult;}
		motor[ClawM]=10*pr.mult;
		//SensorValue[enc]=0;
		//claw open
		wait1Msec(100);
		SensorValue[claw]=0;
		//ClawStep=4;
		wait1Msec(250);
		/*	while(SensorValue[sonar] >1 && SensorValue[sonar] <7 &&vexRT[Btn5D]==0 ) 		//make the arm go up over the cones

		{motor[leftArm1] = -127*pr.mult;
		motor[leftArm2] = -127*pr.mult;
		motor[rightArm1] =-127*pr.mult;
		motor[rightArm2] =-127*pr.mult;}
		*/
		//claw forward
		while (SensorValue[enc]>-300&&vexRT[Btn5D]==0&&vexRT[Btn7R]==0)
		{motor[ClawM]=-127*pr.mult;}
		motor[ClawM]=10*pr.mult;
		wait1Msec(100);
		//while limit isnt pressed {arm down}
		clearTimer(T1);
		if(SensorValue[limit] ==0)
		{
			while(SensorValue[limit] ==0&& time1(T1)<2000&&vexRT[Btn5D]==0&&vexRT[Btn7R]==0)
			{motor[leftArm1] =-70*pr.mult;
				motor[leftArm2] = -70*pr.mult;
				motor[rightArm1] =-70*pr.mult;
				motor[rightArm2] =-70*pr.mult;}
		}
		//claw down preset

	}
}


void S()// Primary Voltage Mult, Secondary Voltage Mult
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
	motor[ClawM]=15*pr.mult;
	//while sonar sees cone {go up}
	while(SensorValue[IR] ==0)
	{
		if (SensorValue[enc]<-450)
		{
			motor[ClawM]=127*pr.mult;
		}
		else{motor[ClawM]=15;}
		/*if (abs(SensorValue[I2C_1])<abs(SensorValue[I2C_1])+10)
		{motor[leftArm] = 127*pr.mult*.9;
		motor[rightArm] =127*pr.mult;}

		else if (abs(SensorValue[I2C_1])>abs(SensorValue[I2C_1])-10)
		{motor[leftArm] = 127*pr.mult;
		motor[rightArm] =127*pr.mult*.9;}

		else{motor[leftArm] = 127*pr.mult;
		motor[rightArm] =127*pr.mult;}
		*/motor[leftArm1] = 127*pr.mult;
		motor[leftArm2] = 127*pr.mult;
		motor[rightArm1] =127*pr.mult;
		motor[rightArm2] =127*pr.mult;
	}
	//claw forward preset
	//while (SensorValue[enc]>-460&&vexRT[Btn5D]==0)
	//{motor[ClawM]=-127*pr.mult;}
	while (SensorValue[enc]<-450)
	{
		motor[ClawM]=127*pr.mult;
	}
	wait1Msec(125);
	//while(SensorValue[sonar] <  13|| SensorValue[sonar] >50 &&vexRT[Btn6D]==0 )
	//{motor[leftArm1] = 127*pr.mult;
	//motor[leftArm2] = 127*pr.mult;
	//motor[rightArm1] =127*pr.mult;
	//motor[rightArm2] =127*pr.mult;}*/

	//motor[leftArm1] = 0;
	//motor[leftArm2] = 0;
	//motor[rightArm1] = 0;
	//motor[rightArm2] = 0;
	//wait1Msec(100);
	//then scissor = 10 to stay up
	motor[leftArm1] = 15*pr.mult;
	motor[leftArm2] = 15*pr.mult;
	motor[rightArm1] =15*pr.mult;
	motor[rightArm2] =15*pr.mult;
	//then claw up
	//	while (SensorValue[enc]<-30&&vexRT[Btn5D]==0)//~~~~~~~~~~~~Add Limit here instead of encoder
	while (SensorValue (Climit)==0)
	{motor[ClawM]=127*pr.mult;}
	motor[ClawM]=10*pr.mult;
	//SensorValue[enc]=0;
	//claw open
	wait1Msec(100);
	SensorValue[claw]=0;
	//ClawStep=4;
	wait1Msec(250);
	/*	while(SensorValue[sonar] >1 && SensorValue[sonar] <7 &&vexRT[Btn5D]==0 ) 		//make the arm go up over the cones

	{motor[leftArm1] = -127*pr.mult;
	motor[leftArm2] = -127*pr.mult;
	motor[rightArm1] =-127*pr.mult;
	motor[rightArm2] =-127*pr.mult;}
	*/
	//claw forward
	while (SensorValue[enc]>-430)
	{motor[ClawM]=-127*pr.mult;}
	motor[ClawM]=10*pr.mult;
	wait1Msec(100);
	//while limit isnt pressed {arm down}
	clearTimer(T1);
	if(SensorValue[limit] ==0)
	{
		while(SensorValue[limit] ==0&& time1(T1)<2000)
		{motor[leftArm1] =-70*pr.mult;
			motor[leftArm2] = -70*pr.mult;
			motor[rightArm1] =-70*pr.mult;
			motor[rightArm2] =-70*pr.mult;}
	}
	//claw down preset
	clearTimer(T3);
	while (abs(SensorValue[enc])<580&&time1(T3)<1000)
	{motor[ClawM]=-127*pr.mult;}
	motor[ClawM]=0;
}

void MGM(int speed, int time)
{
	clearTimer(T3);
	while(time1(T3)<time)
	{motor[MG]=speed;}
	motor[MG]=-10;
}

void CM(int count, int speed)
{
	//int T3;
	//	clearTimer(T3);
	if(SensorValue[enc]>count){
		while (SensorValue[enc]>count)
		{motor[ClawM]=-speed*pr.mult;}}
	else if(SensorValue[enc]<count){
		while (SensorValue[enc]<count)
		{motor[ClawM]=speed*pr.mult;}}
	motor[ClawM]=-10*pr.mult;
}

void C(int val)
{if (val==1){SensorValue[claw]=1;}
	else{SensorValue[claw]=0;}
}


//Positional Awareness Code
void MoveToPosition(float Xf, float Yf, int speed,int MoveSpeed, int time, int adir_overide)
{
	int fullRotation = (360); //12.56 inches in distance with 4 inch wheel
	float oneFoot = (.955*fullRotation); //oneFoot = 12 inches or 343.95
	float tile = 2 * oneFoot;
	float Angle;

	float HypDist = sqrt(pow((Xf - initial.xval), 2) + pow((Yf - initial.yval), 2));
	if (Xf - initial.xval > 0 && Yf - initial.yval > 0) { Angle = acos((Xf - initial.xval) / HypDist); }
	else if (Xf - initial.xval < 0 && Yf - initial.yval > 0) { Angle = 180 - acos((Xf - initial.xval) / HypDist); }
	else if (Xf - initial.xval < 0 && Yf - initial.yval < 0) { Angle = 180 + acos((Xf - initial.xval) / HypDist); }
	else if (Xf - initial.xval > 0 && Yf - initial.yval < 0) { Angle = 360 - acos((Xf - initial.xval) / HypDist); }
	else if (Xf - initial.xval > 0 && Yf - initial.yval == 0) { Angle = 0; }
	else if (Xf - initial.xval < 0 && Yf - initial.yval == 0) { Angle = 180; }
	else if (Xf - initial.xval == 0 && Yf - initial.yval > 0) { Angle = 90; }
	else if (Xf - initial.xval == 0 && Yf - initial.yval < 0) { Angle = 270; }
	else {}
	float GS;
if((SensorValue[in7] / 10)%360>0)
{GS= -360 + (SensorValue[in7] / 10)%360;}
else{GS=(SensorValue[in7] / 10)%360;}
	//Solve For The Angle
	/*if (Angle - SensorValue[gyro] > 0) {adir = 1;}
	else if (Angle - SensorValue[gyro] < 0) { adir = -1; }
	else {}*/
	float deg;
//if ((SensorValue[in7]/10)%360>0)
//{
	deg=-Angle;//-(SensorValue[in7]/10)%360;}
//else{ deg =  -Angle//+(SensorValue[in7]/10)%360;}
	//Turn
	int adir;
	if (GS+Angle >-180) { adir = -1; }
	else{ adir = 1; }
initial.angle=(abs(SensorValue[in7])/ 10)%360;


	if (adir_overide>0){adir=adir*-1;}	//Overider that allows robot to reive backwards (to be tested)
	else {}
	writeDebugStreamLine("X%f   Y%f   H%f   A%f   D%f   GA%f   G%f",(Xf - initial.xval),(Yf - initial.yval), HypDist, Angle, deg,((abs(SensorValue[in7]) / 10)%360),(SensorValue[in7] / 10)%360);
	while ((abs(SensorValue[in7]) / 10)%360 -initial.angle< abs(deg)
	{
		if ((abs(SensorValue[in7])/ 10)%360 -initial.angle< (abs(deg) - 30))
		{
			motor[LM] = adir*speed*se.mult;
			motor[L1] = adir*speed*se.mult;
			motor[RM] = -adir*speed*se.mult;
			motor[R1] = -adir*speed*se.mult;
		}
		else if ((abs(SensorValue[in7]) / 10)%360 -initial.angle-180< (abs(deg) - 15))
		{
			motor[LM] = adir*speed*se.mult / 2;
			motor[L1] = adir*speed*se.mult / 2;
			motor[RM] = -adir*speed*se.mult / 2;
			motor[R1] = -adir*speed*se.mult / 2;
		}
		else
		{
			motor[LM] = adir*speed*se.mult / 3;
			motor[L1] = adir*speed*se.mult / 3;
			motor[RM] = -adir*speed*se.mult / 3;
			motor[R1] = -adir*speed*se.mult / 3;
		}
	}
	wait1Msec(time);
	while ((abs(SensorValue[in7]) / 10)%360-initial.angle > abs(deg))
	{
		motor[LM] = -adir*speed*se.mult / 2;
		motor[L1] = -adir*speed*se.mult / 2;
		motor[RM] = adir*speed*se.mult / 2;
		motor[R1] = adir*speed*se.mult / 2;
	}
	wait1Msec(time);
	while ((abs(SensorValue[in7]) / 10)%360-initial.angle < abs(deg))
	{
		motor[LM] = adir*speed*se.mult / 3;
		motor[L1] = adir*speed*se.mult / 3;
		motor[RM] = -adir*speed*se.mult / 3;
		motor[R1] = -adir*speed*se.mult / 3;
	}
	//motor[LM] = -adir*10*se.mult;
	//		motor[L1] = -adir*10*se.mult;
	//		motor[RM] = adir*10*se.mult;
	//		motor[R1] = adir*10*se.mult;
	//wait1Msec(100);
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;


	//MOVE
	speed = MoveSpeed;
	int dir;
	int count = tile*HypDist;			//Determines the encoder count of the travel distance
	if (adir_overide > 0) { dir = -1; }	//sets direction of robot movement based on overide
	else { dir = 1; }
	SensorValue[Renc] = 0;
	SensorValue[Lenc] = 0;
	if (dir == 1)
	{
		while (abs(SensorValue[Lenc])<count)
		{
			if (abs(SensorValue[Lenc])>abs(SensorValue[Renc]) + 5)
			{
				motor[LM] = speed*se.mult*.8;
				motor[L1] = speed*se.mult*.8;
				motor[RM] = speed*se.mult;
				motor[R1] = speed*se.mult;
			}
			else if (abs(SensorValue[Lenc])<abs(SensorValue[Renc]) - 5)
			{
				motor[LM] = speed*se.mult;
				motor[L1] = speed*se.mult;
				motor[RM] = speed*se.mult*.8;
				motor[R1] = speed*se.mult*.8;
			}
			else
			{
				motor[LM] = speed*se.mult;
				motor[L1] = speed*se.mult;
				motor[RM] = speed*se.mult;
				motor[R1] = speed*se.mult;
			}
		}
		motor[LM] = -speed*se.mult / 4;
		motor[L1] = -speed*se.mult / 4;
		motor[RM] = -speed*se.mult / 4;
		motor[R1] = -speed*se.mult / 4;
		wait1Msec(200);
	}

	else if (dir == -1)
	{
		while (abs(SensorValue[Lenc])<count)
		{
			if (abs(SensorValue[Lenc])>abs(SensorValue[Renc]) - 5)
			{
				motor[LM] = -speed*se.mult*.8;
				motor[L1] = -speed*se.mult*.8;
				motor[RM] = -speed*se.mult;
				motor[R1] = -speed*se.mult;
			}


			else if (abs(SensorValue[Lenc])<abs(SensorValue[Renc]) + 5)
			{
				motor[LM] = -speed*se.mult;
				motor[L1] = -speed*se.mult;
				motor[RM] = -speed*se.mult*.8;
				motor[R1] = -speed*se.mult*.8;
			}
			else
			{
				motor[LM] = -speed*se.mult;
				motor[L1] = -speed*se.mult;
				motor[RM] = -speed*se.mult;
				motor[R1] = -speed*se.mult;
			}

		}
		motor[LM] = speed*se.mult / 4;
		motor[L1] = speed*se.mult / 4;
		motor[RM] = speed*se.mult / 4;
		motor[R1] = speed*se.mult / 4;
		wait1Msec(100);
	}
	else {}
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;


	initial.xval = Xf;//set new X and Y values
	initial.yval = Yf;

}



//Forward 360 ticks speed 127 :: M(360,1,127, se.mult);
//Turn left 90 at 127					:: T(-90, 127, 200, se.mult);
//Stack a cone 								:: S(pr.mult, se.mult);
//Claw motor up at 127				:: CM(300,127,pr.mult);
//Claw close									:: C(1);
//Move Robot to 4 & 2.5			 	:: MoveToPosition(4.0,2.5,127,127,20,0);
