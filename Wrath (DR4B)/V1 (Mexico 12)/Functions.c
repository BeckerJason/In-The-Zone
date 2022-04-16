void MGM(int speed, int time)
{
	clearTimer(T3);
	while(time1(T3)<time)
	{motor[MG]=speed;}
	motor[MG]=-10;
}


void D(	int bL,int	bR,int	l,int cm,int mg,int c)
{
	motor[LM] = bL;
	motor[L1] = bL;
	motor[RM] = bR;
	motor[R1] = bR;
	if(abs(SensorValue[I2C_1])>abs(SensorValue[I2C_2])+5)
	{
		motor[leftArm1] = l*pr.mult*.8;
		motor[rightArm1] = l*pr.mult;
	}
	else if(abs(SensorValue[I2C_2])<abs(SensorValue[I2C_1])-5)
	{
		motor[leftArm1] = l*pr.mult;
		motor[rightArm1] = l*pr.mult*.8;
	}
	else
	{
		motor[leftArm1] = l*pr.mult;
		motor[rightArm1] = l*pr.mult;
	}
	//motor[leftArm1] = l;
	//motor[leftArm2] = l;
	//motor[rightArm1] = l;
	//motor[rightArm2] = l;

	motor[fb1]=cm;
	motor[fb2]=cm;
	motor[MG]=mg;

	if (c==1)  //If the claw is open and you press or hold the button it will close
	{motor[roller]=-127;}
	else	if (c==2)	//when the button is released the claw remains open
	{motor[roller]=-25;}
	else if (c==3) //when the button is released the claw stays closed
	{motor[roller]=127;}
	else if (c==4)	//when the claw is closed and you press or hold the button it will open
	{motor[roller]=0;}
	else{}
	wait1Msec(20);// REFRESH SPEED


}


//CONTROLS LIFT//
void L(int count,int l,int lim)
{if (lim==1)
	{while (SensorValue[limit]==0)
		{l=-l;
			motor[leftArm1] = l*pr.mult;
			motor[rightArm1] = l*pr.mult;
		}
	}
	else
	{
		while(abs(SensorValue[Rarm])<count)
		{
			if(abs(SensorValue[Rarm])>abs(SensorValue[Larm])+5)
			{
				motor[leftArm1] = l*pr.mult*.8;
				motor[rightArm1] = l*pr.mult;
			}
			else if(abs(SensorValue[Larm])<abs(SensorValue[Rarm])-5)
			{
				motor[leftArm1] = l*pr.mult;
				motor[rightArm1] = l*pr.mult*.8;
			}
			else
			{
				motor[leftArm1] = l*pr.mult;
				motor[rightArm1] = l*pr.mult;
		}}

	}
	motor[leftArm1] = 10*pr.mult;
	motor[rightArm1] = 10*pr.mult;
}


//POWER THE LIFT
void liftCont(int power)
{
	motor[leftArm1] = power;
	motor[rightArm1] = power;
}


void S()
{
	motor[roller]=-25;
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;

	motor[leftArm1] = 0;
	motor[rightArm1] = 0;

	motor[fb1]=0;
	motor[fb2]=0;

	motor[MG]=0;  //////////////////////////////////////////////was 15

	/*clearTimer(T3);
	while(time1[T3]<5000&&vexRT[Btn5D]==0)
	{*/
	motor[fb1]=15*pr.mult;motor[fb2]=15*pr.mult;
	//while sonar sees cone {go up}

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
	motor[leftArm1] = -80*pr.mult;	//Bring Lift down to stack cone
	motor[rightArm1] =-80*pr.mult;
	wait1Msec(250);
	motor[roller]=127; //Roll cone out
	wait1Msec(100);
	while(SensorValue[IR] ==0&&vexRT[Btn5D]==0)
	{
		motor[roller]=127; //Roll cone out
		motor[leftArm1] = 115*pr.mult;	//Bring Lift up while rolling cone out
		motor[rightArm1] =115*pr.mult;
	}
	motor[leftArm1] = 15*pr.mult;  //Keep lift up
	motor[rightArm1] =15*pr.mult;
	motor[fb1]=-127*pr.mult;/////Bring 4 bar down before bringing lift down
	motor[fb2]=-127*pr.mult;
	wait1Msec(250);
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

}


void PL(int cones)
{
	for(int count=0;count<cones&&vexRT[Btn5D]==0;count++)
	{
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

		/*clearTimer(T3);
		while(time1[T3]<5000&&vexRT[Btn5D]==0)
		{*/
		motor[fb1]=15*pr.mult;motor[fb2]=15*pr.mult;
		//while sonar sees cone {go up}

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
		motor[leftArm1] = -80*pr.mult;	//Bring Lift down to stack cone
		motor[rightArm1] =-80*pr.mult;

		if (count!=cones-1)
		{
			wait1Msec(250);
			motor[roller]=127; //Roll cone out
			wait1Msec(100);
			while(SensorValue[IR] ==0&&vexRT[Btn5D]==0)
			{
				motor[roller]=127; //Roll cone out
				motor[leftArm1] = 115*pr.mult;	//Bring Lift up while rolling cone out
				motor[rightArm1] =115*pr.mult;
			}
			motor[leftArm1] = 15*pr.mult;  //Keep lift up
			motor[rightArm1] =15*pr.mult;
			motor[fb1]=-127*pr.mult;/////Bring 4 bar down before bringing lift down
			motor[fb2]=-127*pr.mult;
			wait1Msec(250);
			motor[fb1]=0*pr.mult;/////Bring 4 bar down before bringing lift down
			motor[fb2]=0*pr.mult;
			while (SensorValue[limit]==0&&vexRT[Btn5D]==0)
			{
				motor[leftArm1] = -30*pr.mult;	//Bring Lift down to puck up next cone
				motor[rightArm1] =-30*pr.mult;
				motor[roller]=-127; //Roll cone in
			}
		}
		motor[MG]=0;
		motor[fb1]=0;
		motor[fb2]=0;
		motor[leftArm1] = 0;	//kill all
		motor[rightArm1] =0;
	}

}

void M(int dist,int dir,int speed) //encoder count, direction , speed, primary voltage mult
{	clearTimer(T3);
	int fullRotation = (396); //12.56 inches in distance with 4 inch wheel  360 EME  396 IME HS
	float oneFoot = (.955*fullRotation); //oneFoot = 12 inches or 343.95
	float oneInch= oneFoot/12;
	float tile = 2 * oneFoot;
	int count=oneInch*dist;
	SensorValue[Renc]=0;
	SensorValue[Lenc]=0;
	if (dir==1)
	{
		while (abs(SensorValue[Lenc])<count&time1(T3)<4000)
		{
			if(abs(SensorValue[Lenc])>abs(SensorValue[Renc])+2)
			{
				motor[LM] = speed*se.mult*.8;
				motor[L1] = speed*se.mult*.8;
				motor[RM] = speed*se.mult;
				motor[R1] = speed*se.mult;
			}
			else if(abs(SensorValue[Lenc])<abs(SensorValue[Renc])-2)
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
		wait1Msec(50);
	}

	else if (dir==-1)
	{
		while (abs(SensorValue[Lenc])<count)
		{
			if(abs(SensorValue[Lenc])>abs(SensorValue[Renc])-2)
			{
				motor[LM] = -speed*se.mult*.8;
				motor[L1] = -speed*se.mult*.8;
				motor[RM] = -speed*se.mult;
				motor[R1] = -speed*se.mult;
			}


			else if(abs(SensorValue[Lenc])<abs(SensorValue[Renc])+2)
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
		wait1Msec(50);
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
	while((abs(SensorValue[in7])*0.973/10)<abs(deg))
	{	if ((abs(SensorValue[in7])*0.973/10)<(abs(deg)-30))
		{
			motor[LM] = dir*speed*se.mult;
			motor[L1] = dir*speed*se.mult;
			motor[RM] = -dir*speed*se.mult;
			motor[R1] = -dir*speed*se.mult;}
		else if ((abs(SensorValue[in7])*0.973/10)<(abs(deg)-15))
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
	while(abs(SensorValue[in7])*0.973/10>abs(deg))
	{	motor[LM] = -dir*speed*se.mult/2;
		motor[L1] = -dir*speed*se.mult/2;
		motor[RM] = dir*speed*se.mult/2;
		motor[R1] = dir*speed*se.mult/2;}
	wait1Msec(time);
	while(abs(SensorValue[in7])*0.973/10<abs(deg))
	{	motor[LM] = dir*speed*se.mult/3;
		motor[L1] = dir*speed*se.mult/3;
		motor[RM] = -dir*speed*se.mult/3;
		motor[R1] = -dir*speed*se.mult/3;}
	motor[LM] = -dir*10*se.mult;
	motor[L1] = -dir*10*se.mult;
	motor[RM] = dir*10*se.mult;
	motor[R1] = dir*10*se.mult;
	wait1Msec(100);
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] =0;
}


//void S()// Primary Voltage Mult, Secondary Voltage Mult
//{		motor[LM] = 0;
//	motor[L1] = 0;
//	motor[RM] = 0;
//	motor[R1] = 0;

//	motor[leftArm1] = 0;
//	motor[rightArm1] = 0;

//	motor[fb1]=0;
//	motor[fb2]=0;

//	motor[MG]=15;

//	motor[fb1]=15*pr.mult;
//	motor[fb2]=15*pr.mult;
//	//while sonar sees cone {go up}
//	while(SensorValue[IR] ==0)
//	{
//		if (SensorValue[enc]<-450)
//		{
//			motor[fb1]=127*pr.mult;
//			motor[fb2]=127*pr.mult;
//		}
//		else{motor[fb1]=15;motor[fb2]=15;}
//		/*if (abs(SensorValue[I2C_1])<abs(SensorValue[I2C_1])+10)
//		{motor[leftArm] = 127*pr.mult*.9;
//		motor[rightArm] =127*pr.mult;}

//		else if (abs(SensorValue[I2C_1])>abs(SensorValue[I2C_1])-10)
//		{motor[leftArm] = 127*pr.mult;
//		motor[rightArm] =127*pr.mult*.9;}

//		else{motor[leftArm] = 127*pr.mult;
//		motor[rightArm] =127*pr.mult;}
//		*/motor[leftArm1] = 127*pr.mult;
//		motor[rightArm1] =127*pr.mult;
//	}
//	//claw forward preset
//	//while (SensorValue[enc]>-460&&vexRT[Btn5D]==0)
//	//{motor[fb1]=-127*pr.mult;}
//	while (SensorValue[enc]<-450)
//	{
//		motor[fb1]=127*pr.mult;
//		motor[fb2]=127*pr.mult;
//	}
//	wait1Msec(125);
//	motor[leftArm1] = 15*pr.mult;
//	motor[rightArm1] =15*pr.mult;

//	while (SensorValue (Climit)==0)
//	{motor[fb1]=127*pr.mult;motor[fb2]=127*pr.mult;}
//	motor[fb1]=10*pr.mult;motor[fb2]=10*pr.mult;
//	//SensorValue[enc]=0;
//	//claw openz
//	wait1Msec(100);
//	SensorValue[claw]=0;
//	//ClawStep=4;
//	wait1Msec(250);
//	/*	while(SensorValue[sonar] >1 && SensorValue[sonar] <7 &&vexRT[Btn5D]==0 ) 		//make the arm go up over the cones
//	{motor[leftArm1] = -127*pr.mult;
//	motor[leftArm2] = -127*pr.mult;
//	motor[rightArm1] =-127*pr.mult;
//	motor[rightArm2] =-127*pr.mult;}
//	*/
//	//claw forward
//	while (SensorValue[enc]>-430)
//	{motor[fb1]=-127*pr.mult;motor[fb2]=-127*pr.mult;}
//	motor[fb1]=10*pr.mult;motor[fb2]=10*pr.mult;
//	wait1Msec(100);
//	//while limit isnt pressed {arm down}
//	clearTimer(T1);
//	if(SensorValue[limit] ==0)
//	{
//		while(SensorValue[limit] ==0&& time1(T1)<2000)
//		{motor[leftArm1] =-70*pr.mult;
//			motor[rightArm1] =-70*pr.mult;}
//	}
//	//claw down preset
//	clearTimer(T3);
//	while (abs(SensorValue[enc])<580&&time1(T3)<1000)
//	{motor[fb1]=-127*pr.mult;motor[fb2]=-127*pr.mult;}
//	motor[fb1]=0;motor[fb2]=0;
//}


//4 BAR CONTROL//
void CM(int count, int speed, int lim)
{
	//int T3;
	//	clearTimer(T3);
	if (lim==1)
	{while (SensorValue[Climit]==0)
		{motor[fb1]=speed*pr.mult;motor[fb2]=speed*pr.mult;}
	}
	else
	{
		if(SensorValue[enc]>count){
			while (SensorValue[enc]>count)
			{motor[fb1]=speed*pr.mult;motor[fb2]=speed*pr.mult;}}
		else if(SensorValue[enc]<count){
			while (SensorValue[enc]<count)
			{motor[fb1]=-speed*pr.mult;motor[fb2]=-speed*pr.mult;}}
	}
	motor[fb1]=10*pr.mult;	motor[fb2]=10*pr.mult;
}

//CLAW CONTROL//
void C(int c)
{
	if (c==1)  //If the claw is open and you press or hold the button it will close
	{motor[roller]=-127;}
	else	if (c==2)	//when the button is released the claw remains open
	{motor[roller]=-25;}
	else if (c==3) //when the button is released the claw stays closed
	{motor[roller]=127;}
	else if (c==4)	//when the claw is closed and you press or hold the button it will open
	{motor[roller]=0;}
	else{}
}

void Turn(int adir, float Angle)
{while ((SensorValue[gyro]/ 10)<Angle)
	{writeDebugStreamLine("%f     %f", Angle, SensorValue[gyro]/10);
		motor[LM] = adir*100*se.mult;
		motor[L1] = adir*100*se.mult;
		motor[RM] = -adir*100*se.mult;
		motor[R1] = -adir*100*se.mult;
	}
	motor[LM] = -adir*10*se.mult;
	motor[L1] = -adir*10*se.mult;
	motor[RM] = adir*10*se.mult;
	motor[R1] = adir*10*se.mult;
	wait1Msec(100);
	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] =0;
}



//Fine tune the proportion value or change the function to either make point turns or include the middle line follower
void FollowLine(int Initial)
{
	int left = 0, right = 0;
	float LineMath = 0.02*(SensorValue[LineL]-SensorValue[LineR]);
	int Speed = abs(LineMath);
	if (LineMath < 0){left = -1; right =  1; 	}//TURN LEFT
	else if (LineMath > 0){left = 1; right = -1;	}//TURN RIGHT
	else{left =  1; right =  1;  }//MOVE STRAIGHT
	motor[LM]     = Initial+(Speed*left);
	motor[L1]      = Initial+(Speed*left);
	motor[RM]    = Initial+(Speed*right);
	motor[R1]     = Initial+(Speed*right);
}


//Forward 360 ticks speed 127 :: M(360,1,127, se.mult);
//Turn left 90 at 127					:: T(-90, 127, 200, se.mult);
//Stack a cone 								:: S(pr.mult, se.mult);
//Claw motor up at 127				:: CM(300,127,pr.mult);
//Claw close									:: C(1);
//Move Robot to 4 & 2.5			 	:: MoveToPosition(4.0,2.5,127,127,20,0);
void Move(int Vel, float dist)
{clearTimer(T3);

	int fullRotation = (360); //12.56 inches in distance with 4 inch wheel
	float oneFoot = (.9*fullRotation); //oneFoot = 12 inches or 343.95
	float oneInch= oneFoot/12;
	float tile = 2 * oneFoot;
	int count=oneInch*dist;
	int dir;
	SensorValue[Renc]=0;
	SensorValue[Lenc]=0;
	if(Vel<0){dir=-1;}
	else {dir=1;}
	int Roffset, Loffset;
	int x, speed;
	wait1Msec(20);
	while (abs(SensorValue[Lenc])<count&time1(T3)<4000)
	{x=dir*count-SensorValue[Lenc];
		//speed=abs((80*x)/50);	//-100*cos(x/(count/5))/2+100/2;
		speed=-(105/2)*cos((16*x)/(count*PI))+57.5;
		if (abs(SensorValue[Renc])>abs(SensorValue[Lenc])){Loffset=0; Roffset=-dir*5;}
		else if (abs(SensorValue[Renc])<abs(SensorValue[Lenc])){Loffset=-dir*5; Roffset=0;}
		else{Loffset=0; Roffset=0;}

		motor[LM] = dir*speed*se.mult+Loffset;
		motor[L1] = dir*speed*se.mult+Loffset;
		motor[RM] = dir*speed*se.mult+Roffset;
		motor[R1] = dir*speed*se.mult+Roffset;

	}
	//wait1Msec(5);
	//dir=-dir
	//	while (abs(SensorValue[Lenc])>count&time1(T3)<4000)
	//{x=dir*count-SensorValue[Lenc];
	//	//speed=abs((80*x)/50);	//-100*cos(x/(count/5))/2+100/2;
	//	speed=-35*cos((20*x)/(count*PI))+75;
	//	if (abs(SensorValue[Renc])>abs(SensorValue[Lenc])){Loffset=0; Roffset=-dir*5;}
	//	else if (abs(SensorValue[Renc])<abs(SensorValue[Lenc])){Loffset=-dir*5; Roffset=0;}
	//	else{Loffset=0; Roffset=0;}

	//	motor[LM] = dir*speed*se.mult+Loffset;
	//	motor[L1] = dir*speed*se.mult+Loffset;
	//	motor[RM] = dir*speed*se.mult+Roffset;
	//	motor[R1] = dir*speed*se.mult+Roffset;

	//}
	motor[LM] = -dir*5;
	motor[L1] = -dir*5;
	motor[RM] = -dir*5;
	motor[R1] = -dir*5;
	wait1Msec(50);

	motor[LM] = 0;
	motor[L1] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
}


void FB(int Vel)
{motor[fb1]=Vel;
	motor[fb2]=Vel;
}

void Mover(float dist,int MobileGoal)
{SensorValue[Renc]=0;
	SensorValue[Lenc]=0;
	dist= (dist*396)/(4*3.14);///Change 261 (IME Turbo) for 360 for external Motor controllers

	float x;
	//int q=0;
	float dir,Loffset, Roffset,speed;

	//if (dist<0){dir=-1;}
	//else{dir=1;}//

	//while(q<2)
	//{
	//wait1Msec(100);
	clearTimer(T1);
	while( time1[T1]<2000 && (abs(SensorValue[Lenc])<(abs(dist))   )/*&&abs(SensorValue[gyro])!=(abs(dist)-50)*/)
	{
		x=dist-SensorValue[Lenc];
		if (x<0){dir=-1; x=-x;}
		else{dir=1;}
		//
		//if (x<0){dir=1:}
		//else{dir=-1;}

		//if ((pow(x,2))%127>0){speed=-dir*127;}//-127cos(pow((x/57),2)+(127/2)
		//	else{speed=-dir*pow(x,2);}
		speed=(-45)*cos((16*abs(x))/(abs(dist)*3.14)+5.6)+35;//vel;
		speed=dir*speed;

		if (abs(SensorValue[Renc])<(abs(SensorValue[Lenc]))){Loffset=-speed/5; Roffset=0;}
		else if (abs(SensorValue[Lenc])<(abs(SensorValue[Renc]))){Loffset=0; Roffset=-speed/5;}
		else{Loffset=0; Roffset=0;}

		writeDebugStreamLine("%f, %f", speed,x);
		motor[R1]=speed+Roffset;
		motor[RM]=speed+Roffset;
		motor[L1]=speed+Loffset;
		motor[LM]=speed+Loffset;
		wait1Msec(2);
	}
	if (MobileGoal==0)
	{motor[R1]=dir*50/2;
		motor[RM]=dir*50/2;
		motor[LM]=dir*50/2;
		motor[L1]=dir*50/2;
		//q++;
		wait1Msec(100);
	}
	else{}
	motor[R1]=0;
	motor[RM]=0;
	motor[LM]=0;
	motor[L1]=0;
}


void Turning(float degree)
{clearTimer(T1);
	SensorValue[Renc]=0;
	SensorValue[Lenc]=0;
	SensorValue[gyro]=0;
	//90 degrees

	int x;
	int dir,Loffset, Roffset,speed;

	if (degree<0){dir=-1;}
	else{dir=1;}//
	degree=degree*9.66;//Correction factor for this specific gyro

	while(abs(SensorValue[gyro])>(abs(degree)+10)||abs(SensorValue[gyro])<(abs(degree)-10) && time1[T1]<2500)
	{
		if (abs(SensorValue[Renc])<abs(SensorValue[Lenc])){Loffset=dir*10; Roffset=0;}
		else if (abs(SensorValue[Lenc])<abs(SensorValue[Renc])){Loffset=0; Roffset=-dir*10;}
		else{Loffset=0; Roffset=0;}

		x=(degree-SensorValue[gyro])/10;
		/*if ((pow(x,2)+20)%127>0){speed=dir*127;}
		else{speed=dir*pow(x,2)+20;}
		*/
		speed=(-35)*cos(16*abs(x)/(abs(degree)*3.14)+5.75)+30;//vel;
		speed=dir*speed;

		//writeDebugStreamLine("%d, %d", x, speed);


		//	writeDebugStreamLine("%d", speed);
		//writeDebugStreamLine("%d", SensorValue[gyro]);
		motor[R1]=speed+Roffset;
		motor[RM]=speed+Roffset;
		motor[L1]=-speed+Loffset;
		motor[LM]=-speed+Loffset;

	}
	motor[R1]=-dir*50/2;
	motor[RM]=-dir*50/2;
	motor[LM]=dir*50/2;
	motor[L1]=dir*50/2;
	wait1Msec(100);

	motor[R1]=0;
	motor[RM]=0;
	motor[LM]=0;
	motor[L1]=0;
}
