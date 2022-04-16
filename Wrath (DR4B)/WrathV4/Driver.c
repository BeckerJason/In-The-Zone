	startTask(FourBar);
	stopTask(anglePIDControl);
	//startTask(autoStack);
	while(1)
	{
		#include "LCD.c"
		//Over Heat Cool down
		if(vexRT[Btn7D] == 1)
		{
			clearTimer(T1);
			while(time1[T1] < 10000)KILLALL();
		}
		//////////////////////

		//Drive Train
		if(vexRT[Ch3] > 15 || vexRT[Ch3] < -15 || vexRT[Ch4] > 15 || vexRT[Ch4] < -15)
		{
			motor[R1]  = (vexRT[Ch3] - vexRT[Ch4])*0.7;  // (y + x)/2
			motor[RM]  = (vexRT[Ch3] - vexRT[Ch4])*0.7;

			motor[L1]  = (vexRT[Ch3] + vexRT[Ch4])*0.7;  // (y + x)/2
			motor[LM]  = (vexRT[Ch3] + vexRT[Ch4])*0.7;
		}
		else
		{
			motor[R1]  = 0;  // (y + x)/2
			motor[RM]  = 0;

			motor[L1]  = 0;  // (y + x)/2
			motor[LM]  = 0;

		}

		//Mobile Goal//
		if(vexRT[Btn8R]==1)		motor[MG]=-127;
		else if(vexRT[Btn8D]==1)	motor[MG]=127;
		else								motor[MG]=0;
		////////////////////////////////

		//LIFT//////////////////////////
		if(vexRT[Ch2] > 15 || vexRT[Ch2] < -15)
		{
			if(SensorValue[LiftLimit] == 1 && vexRT[Ch2] < 15)
			{
				motor[LiftR] = -20;
				motor[LiftL] = -20;
			}
			else
			{
				motor[LiftR] = vexRT[Ch2];
				motor[LiftL] = vexRT[Ch2];
			}
		}
		else if(vexRT[Btn8R]==1 || vexRT[Btn8D]==1){
			motor[LiftR] = 35;
			motor[LiftL] = 35;
		}
		else
		{
			motor[LiftR] = 0;
			motor[LiftL] = 0;
		}
		////////////////////////////////////

		///////***Roller***////////////////

		//Intake
		if(vexRT[Btn5U] == 1)
		{
			motor[roller]=127;
		}
		else if (motor[roller] == 127)
		{
			motor[roller] = 30;
		}
		//OutTake
		if(vexRT[Btn5D] == 1)
		{
			motor[roller]=-127;
		}
		else if(motor[roller] == -127)
		{
			motor[roller] = 0;
		}
		//////////////////////////

		//fb Control// (1 = up, 0 = down, -1 = stand-by)
		if(vexRT[Btn6U]==1)	fbStatus = 1;
		else if(vexRT[Btn6D]==1)	fbStatus = 0;

		wait1Msec(25);
	}
