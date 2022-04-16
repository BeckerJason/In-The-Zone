//Forward 4 inches speed 127 		 	:: M(4,1,127);
//Backward 4 inches ramped speed	::Move(-4);
//Turn left 90 at 127							:: T(-90, 127, 20);
//Stack a cone 										:: S();
//Claw motor up at 127						:: CM(300,127);
//Roller in 											:: C(1);    (1 in, 2 stay, 3 out, 4 stop)
//Move Robot to 4 & 2.5			 			:: MoveToPosition(4.0,2.5,127,127,20,0);



//////////////////////////////////////////////////////////////////////////DRIVING/////////////////////////
void D(	int bL,int	bR,int	l,int cm,int mg,int c)
{
	motor[LM] = bL;
	motor[L1] = bL;
	motor[RM] = bR;
	motor[R1] = bR;
	if (mobi.val!=0||mobi.stack!=0)
	{}
	else if(abs(SensorValue[I2C_1])>abs(SensorValue[I2C_2])+5)
	{
		motor[leftArm1] = l*se.mult*.8;
		motor[rightArm1] = l*se.mult;
	}
	else if(abs(SensorValue[I2C_2])<abs(SensorValue[I2C_1])-5)
	{
		motor[leftArm1] = l*se.mult;
		motor[rightArm1] = l*se.mult*.8;
	}
	else
	{
		motor[leftArm1] = l*se.mult;
		motor[rightArm1] = l*se.mult;
	}
	//motor[leftArm1] = l;
	//motor[leftArm2] = l;
	//motor[rightArm1] = l;
	//motor[rightArm2] = l;
	if (mobi.val==0&&mobi.stack==0)
	{
		motor[fb1]=cm*pr.mult;
		motor[fb2]=cm*pr.mult;
	}
	else{}
	//motor[MG]=mg;
	if (mobi.val==0&&mobi.stack==0)
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
	else{}
	wait1Msec(20);// REFRESH SPEED
}
//////////////////////////////////////////////////////////////////////////DRIVING/////////////////////////



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ LIFT DISTANCE @@@@@@@@@@@@@@@@@@@@
void L(int count,int l,int lim)
{if (lim==1)
	{while (SensorValue[limit]==0)
		{l=-l;
			motor[leftArm1] = l*se.mult;
			motor[rightArm1] = l*se.mult;
		}
	}
	else
	{
		while(abs(SensorValue[Rarm])<count)
		{
			if(abs(SensorValue[Rarm])>abs(SensorValue[Larm])+5)
			{
				motor[leftArm1] = l*se.mult*.8;
				motor[rightArm1] = l*se.mult;
			}
			else if(abs(SensorValue[Larm])<abs(SensorValue[Rarm])-5)
			{
				motor[leftArm1] = l*se.mult;
				motor[rightArm1] = l*se.mult*.8;
			}
			else
			{
				motor[leftArm1] = l*se.mult;
				motor[rightArm1] = l*se.mult;
		}}
		while(abs(SensorValue[Rarm])>count)
		{
			if(abs(SensorValue[Rarm])<abs(SensorValue[Larm])+5)
			{
				motor[leftArm1] = l*se.mult*.8;
				motor[rightArm1] = l*se.mult;
			}
			else if(abs(SensorValue[Larm])>abs(SensorValue[Rarm])-5)
			{
				motor[leftArm1] = l*se.mult;
				motor[rightArm1] = l*se.mult*.8;
			}
			else
			{
				motor[leftArm1] = l*se.mult;
				motor[rightArm1] = l*se.mult;
		}}
	}
	motor[leftArm1] = 30*se.mult;
	motor[rightArm1] = 30*se.mult;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ LIFT DISTANCE @@@@@@@@@@@@@@@@@@@@

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ LIFT POWER $$$$$$$$$$$$$$$$$$$$$$$
void liftCont(int power)
{
	motor[leftArm1] = power*se.mult;
	motor[rightArm1] = power*se.mult;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ LIFT POWER $$$$$$$$$$$$$$$$$$$$$$$


//************************************************************************ STACK ****************************
//void S()
//{
//	motor[roller]=-25;
//	motor[LM] = 0;
//	motor[L1] = 0;
//	motor[RM] = 0;
//	motor[R1] = 0;

//	motor[leftArm1] = 0;
//	motor[rightArm1] = 0;

//	motor[fb1]=0;
//	motor[fb2]=0;

//	motor[MG]=0;
//	motor[fb1]=15*pr.mult;motor[fb2]=15*pr.mult;


//	while(SensorValue[IR] ==0&&vexRT[Btn5D]==0) ///while the robot sees a cone
//	{
//		motor[leftArm1] = 127*pr.mult;	///Bring lift up
//		motor[rightArm1] =127*pr.mult;
//	}

//	motor[leftArm1] = 15*pr.mult;  //Keep lift up
//	motor[rightArm1] =15*pr.mult;

//	while (SensorValue[Climit]==0&&vexRT[Btn5D]==0)
//	{
//		motor[fb1]=127*pr.mult;/////Bring 4 bar up
//		motor[fb2]=127*pr.mult;
//	}
//	motor[MG]=-5;
//	motor[fb1]=15*pr.mult;		//Keep 4 bar up
//	motor[fb2]=15*pr.mult;
//	motor[leftArm1] = -40*pr.mult;	//Bring Lift down to stack cone
//	motor[rightArm1] =-40*pr.mult;
//	wait1Msec(250);
//	motor[roller]=127; //Roll cone out
//	wait1Msec(100);
//	playSoundFile("boom3.wav");
//	while(SensorValue[IR] ==0&&vexRT[Btn5D]==0)
//	{
//		motor[roller]=127; //Roll cone out
//		motor[leftArm1] = 115*pr.mult;	//Bring Lift up while rolling cone out
//		motor[rightArm1] =115*pr.mult;
//	}
//	motor[leftArm1] = 15*pr.mult;  //Keep lift up
//	motor[rightArm1] =15*pr.mult;
//	motor[fb1]=-127*pr.mult;/////Bring 4 bar down before bringing lift down
//	motor[fb2]=-127*pr.mult;
//	wait1Msec(300);
//	motor[fb1]=-10*pr.mult;/////Bring 4 bar down before bringing lift down
//	motor[fb2]=-10*pr.mult;
//	while (SensorValue[limit]==0&&vexRT[Btn5D]==0)
//	{
//		motor[leftArm1] = -30*pr.mult;	//Bring Lift down to puck up next cone
//		motor[rightArm1] =-30*pr.mult;
//	}
//	motor[MG]=0;
//	motor[fb1]=0;
//	motor[fb2]=0;
//	motor[leftArm1] = 0;	//kill all
//	motor[rightArm1] =0;
//}
//************************************************************************ STACK ****************************

//------------------------------------------------------------------------ PRE-LOAD -------------------------
void PL(int cones)
{cones=cones+1;
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

		motor[fb1]=-45*pr.mult;motor[fb2]=-45*pr.mult;

		while(SensorValue[IR] ==0&&vexRT[Btn5D]==0) ///while the robot sees a cone
		{
			motor[leftArm1] = 127*se.mult;	///Bring lift up
			motor[rightArm1] =127*se.mult;
		}

		motor[leftArm1] = 15*se.mult;  //Keep lift up
		motor[rightArm1] =15*se.mult;

		while (SensorValue[Climit]==0&&vexRT[Btn5D]==0)
		{
			motor[fb1]=127*pr.mult;/////Bring 4 bar up
			motor[fb2]=127*pr.mult;
		}
		motor[MG]=-5*pr.mult;
		motor[fb1]=15*pr.mult;		//Keep 4 bar up
		motor[fb2]=15*pr.mult;
		motor[leftArm1] = -30*se.mult;	//Bring Lift down to stack cone
		motor[rightArm1] =-30*se.mult;

		if (count!=cones-1)
		{
			wait1Msec(250);
			motor[roller]=127; //Roll cone out
			wait1Msec(200);
			while(SensorValue[IR] ==0&&vexRT[Btn5D]==0)
			{
				motor[roller]=127; //Roll cone out
				motor[leftArm1] = 115*se.mult;	//Bring Lift up while rolling cone out
				motor[rightArm1] =115*se.mult;
			}
			motor[leftArm1] = 30*se.mult;  //Keep lift up
			motor[rightArm1] =30*se.mult;
			motor[fb1]=-127*pr.mult;/////Bring 4 bar down before bringing lift down
			motor[fb2]=-127*pr.mult;
			wait1Msec(300);
			motor[fb1]=0*pr.mult;/////Bring 4 bar down before bringing lift down
			motor[fb2]=0*pr.mult;
			while (SensorValue[limit]==0&&vexRT[Btn5D]==0)
			{
				motor[leftArm1] = -40*se.mult;	//Bring Lift down to pick up next cone          was -20
				motor[rightArm1] =-40*se.mult;
				motor[roller]=-127; //Roll cone in
			}
			motor[leftArm1] = 0;
			motor[rightArm1] =0;
			motor[roller]=-25; //Roll cone in
			wait1Msec(200);
		}
		motor[MG]=0;
		motor[leftArm1] = 0;	//kill all
		motor[rightArm1] =0;
	}

}
//------------------------------------------------------------------------ PRE-LOAD -------------------------

//######################################################################## MOVE WITH SPEED ##################
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
//######################################################################## MOVE WITH SPEED ##################

/////////////////////////////////////////////////////////////TURN///////////////////////////////////////////
void T(int deg,int speed, int time)
{int dir;
	if (deg>0){dir=1;}
	else if (deg<0){dir=-1;}
	else{}
	while((abs(SensorValue[in7])*0.94/10)<abs(deg))
	{	if ((abs(SensorValue[in7])*0.94/10)<(abs(deg)-30))
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
////////////////////////////////////////////////////////////////////TURN////////////////////////////////////

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& 4 BAR DISTANCE &&&&&&&&&&&&&&&&&&&&&&&&
void CM(int count, int speed, int lim)
{
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
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& 4 BAR DISTANCE &&&&&&&&&&&&&&&&&&&&&&&&





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
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& 4 BAR DISTANCE &&&&&&&&&&&&&&&&&&&&&&&&

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ TURN ANGLE ++++++++++++++++++++++++++++
void Turn(int adir, float Angle)
{while ((SensorValue[gyro]/ 9.4)<Angle)
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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ TURN ANGLE ++++++++++++++++++++++++++++

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% FOLLOW LINE %%%%%%%%%%%%%%%%%%%%%%%%%%%
//Fine tune the proportion value or change the function to either make point turns or include the middle line follower
/*void FollowLine(int Initial)
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
}*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% FOLLOW LINE %%%%%%%%%%%%%%%%%%%%%%%%%%%

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ MOVE ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
/*void Move(int Vel, float dist)
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
speed=(-200)*cos(18*abs(x)/(abs(dist)*3.14)+5.9)+190;
if (abs(SensorValue[Renc])>abs(SensorValue[Lenc])){Loffset=0; Roffset=-dir*5;}
else if (abs(SensorValue[Renc])<abs(SensorValue[Lenc])){Loffset=-dir*5; Roffset=0;}
else{Loffset=0; Roffset=0;}

motor[LM] = dir*speed*se.mult+Loffset;
motor[L1] = dir*speed*se.mult+Loffset;
motor[RM] = dir*speed*se.mult+Roffset;
motor[R1] = dir*speed*se.mult+Roffset;

}

motor[LM] = -dir*5;
motor[L1] = -dir*5;
motor[RM] = -dir*5;
motor[R1] = -dir*5;
wait1Msec(50);

motor[LM] = 0;
motor[L1] = 0;
motor[RM] = 0;
motor[R1] = 0;
}*/
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ MOVE ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 4 BAR POWER !!!!!!!!!!!!!!!!!!!!!!!!!!!
void FB(int Vel)
{motor[fb1]=Vel;
	motor[fb2]=Vel;
}

void Mover(float dist,int MobileGoal)
{SensorValue[Renc]=0;
	SensorValue[Lenc]=0;
	dist= (dist*396)/(4*3.14);///Change 261 (IME Turbo) for 360 for external Motor controllers

	float x;
	float dir,Loffset, Roffset,speed;


	clearTimer(T1);
	while( time1[T1]<3500 && (abs(SensorValue[Lenc])<(abs(dist))   )/*&&abs(SensorValue[gyro])!=(abs(dist)-50)*/)
	{
		x=dist-SensorValue[Lenc];
		if (x<0){dir=-1; x=-x;}
		else{dir=1;}
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
		wait1Msec(100);
	}
	else{}
	motor[R1]=0;
	motor[RM]=0;
	motor[LM]=0;
	motor[L1]=0;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 4 BAR POWER !!!!!!!!!!!!!!!!!!!!!!!!!!!

/*void Turning(float degree)
{clearTimer(T1);
SensorValue[Renc]=0;
SensorValue[Lenc]=0;
SensorValue[gyro]=0;
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
speed=(-35)*cos(16*abs(x)/(abs(degree)*3.14)+5.75)+30;//vel;
speed=dir*speed;

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
}*/

void Roll(string val)
{if (val == "in"){}
	else if(val=="out"){}
	else if (val=="hold"){}
	else if (val=="stoproll"){}
	else{}
}
