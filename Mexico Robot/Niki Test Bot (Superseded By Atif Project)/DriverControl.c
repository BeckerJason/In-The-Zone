int ClawStep=4;
while (1)
{//VOLTAGE COMPENSATION-------------------------
	float PMult/*, SMult,Pin*/; //primary multiplier, secondary multiplier
	float MainBattery=nImmediateBatteryLevel; //Main Battery input
	float Batt=MainBattery/1000; //Division by 1000 to get true voltage value of battery
	PMult=PCheck(Batt); //Create Multiplier Based On Battery Voltage
	/*	writeDebugStreamLine("%1.2f",Batt);
	writeDebugStreamLine("%1.5f",PMult);
	writeDebugStreamLine("%1.5f",127*PMult);
	writeDebugStreamLine(" ");*/
	//---------------------------------------------------------------------------------
	//LCD display data
	//#include "LCD.c"
	//////////////////////
	if(vexRT[Ch3] > 10 || vexRT[Ch4] > 10 || vexRT[Ch3] < -10 || vexRT[Ch4] < -10) //JOYSTICK DEADBAND
	{
		motor[LM] = vexRT[Ch3]*PMult + vexRT[Ch4]*PMult;
		motor[L1] = vexRT[Ch3]*PMult + vexRT[Ch4]*PMult;
		motor[RM] = vexRT[Ch3]*PMult - vexRT[Ch4]*PMult;
		motor[R1] = vexRT[Ch3]*PMult - vexRT[Ch4]*PMult;
	}
	else
	{
		motor[LM] = 0;
		motor[L1] = 0;
		motor[RM] = 0;
		motor[R1] = 0;

	}

	if(vexRT[Ch2] > 15)
	{
		motor[leftArm1] = vexRT[Ch2]*PMult;
		motor[leftArm2] = vexRT[Ch2]*PMult;
		motor[rightArm1] = vexRT[Ch2]*PMult;
		motor[rightArm2] = vexRT[Ch2]*PMult;
	}
	else if(vexRT[Ch2]<-15)
	{
		motor[leftArm1] = vexRT[Ch2]*PMult;
		motor[leftArm2] = vexRT[Ch2]*PMult;
		motor[rightArm1] = vexRT[Ch2]*PMult;
		motor[rightArm2] = vexRT[Ch2]*PMult;
	}
	else
	{
		motor[leftArm1] = 0;
		motor[leftArm2] = 0;
		motor[rightArm1] = 0;
		motor[rightArm2] = 0;      	//...stop the arm.
	}
	if (vexRT[Btn8U]==1)
	{
		while (abs(SensorValue[enc])>15)
		{motor[ClawM]=127*PMult;}}
	else if(vexRT[Btn8R]==1)
	{
		while (abs(SensorValue[enc])>450)
		{motor[ClawM]=127*PMult;}
		while (abs(SensorValue[enc])<430)
		{motor[ClawM]=-127*PMult;}
	}
	else if (vexRT[Btn8D]==1)
	{while (SensorValue[limit]==0)
		{motor[ClawM]=-127*PMult;}}
	//else{}

	else if (vexRT[Btn5U]==1&&vexRT[Btn5D]==0){motor[ClawM]=127*PMult;}
	else if (vexRT[Btn5D]==1&&vexRT[Btn5U]==0){motor[ClawM]=-127*PMult;}
	else{motor[ClawM]=10;}

	if (vexRT[Btn7U]==1&&vexRT[Btn7D]==0){motor[MG]=100*PMult;}
	else if (vexRT[Btn7D]==1&&vexRT[Btn7U]==0){motor[MG]=-75*PMult;}
	else{motor[MG]=15*PMult;}
	//CLAW
	/*if (vexRT[Btn6U]==1){SensorValue[claw]=1;}
	else{SensorValue[claw]=0;}*/
	if (vexRT[Btn6U]==0 && ClawStep==3 || vexRT[Btn6U]==0 && ClawStep==4)	//when the button is released the claw remains open
	{SensorValue[claw]=0;
		ClawStep=4;}
	else if (vexRT[Btn6U]==0 && ClawStep==4 || vexRT[Btn6U]==0 && ClawStep==1) //when the button is released the claw stays closed
	{SensorValue[claw]=1;
		ClawStep=2;}

	else	if (vexRT[Btn6U]==1 && ClawStep==4 || vexRT[Btn6U]==1 && ClawStep==1)  //If the claw is open and you press or hold the button it will close
	{SensorValue[claw]=1;
		ClawStep=1;}

	else if (vexRT[Btn6U]==1 && ClawStep==2 || vexRT[Btn6U]==1 && ClawStep==3)	//when the claw is closed and you press or hold the button it will open
	{SensorValue[claw]=0;
		ClawStep=3;}

	else{}

	/*
	if (vexRT[Btn8U]==1){while (SensorValue[enc]<-50){motor[ClawM]=127*PMult;}}
	else if (vexRT[Btn8R]==1){while (SensorValue[enc]>-450){motor[ClawM]=-127*PMult;}}
	else if (vexRT[Btn8D]==0&&vexRT[Btn8U]==0){motor[ClawM]=20*PMult;}
	else{}*/

	//````````````````````````````````````````````````````
	//
	if(vexRT[Btn8L]==1)
	{clearTimer(T3);
		clearTimer(T2);
		while(time1[T3]<5000&&vexRT[Btn6D]==0)
		{
			//claw forward preset
			while (SensorValue[enc]>-460)
			{motor[ClawM]=-127*PMult;}
			while (SensorValue[enc]<-450)
			{motor[ClawM]=127*PMult;}
	motor[ClawM]=15*PMult;
			//while sonar sees cone {go up}
			while(SensorValue[sonar] <  13&&vexRT[Btn6D]==0|| SensorValue[sonar] >50 &&vexRT[Btn6D]==0 )
			{motor[leftArm1] = 127*PMult;
				motor[leftArm2] = 127*PMult;
				motor[rightArm1] =127*PMult;
				motor[rightArm2] =127*PMult;}
			/*	wait1Msec(20);
							while(SensorValue[sonar] <  13|| SensorValue[sonar] >50 &&vexRT[Btn6D]==0 )
			{motor[leftArm1] = 127*PMult;
				motor[leftArm2] = 127*PMult;
				motor[rightArm1] =127*PMult;
				motor[rightArm2] =127*PMult;}*/

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
			ClawStep=4;
			wait1Msec(100);
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
			break;
		}
	}
	wait1Msec(20);
}
