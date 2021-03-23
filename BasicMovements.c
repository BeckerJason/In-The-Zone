///////////////////////////////////////STOP DRIVE TRAIN
void StopDrive(void)
{
	motor[LM] = 0;
	motor[L1] = 0;
	motor[L2] = 0;
	motor[RM] = 0;
	motor[R1] = 0;
	motor[R2] = 0;
}
void Break(int time, int speed)
{
	motor[LM] = -speed;
	motor[L1] = -speed;
	motor[L2] = -speed;
	motor[RM] = -speed;
	motor[R1] = -speed;
	motor[R2] = -speed;
	wait1Msec(time);
	StopDrive();
}
///////////////////////////////////////MOVE ROBOT BASED ON SPEED EXAMPLE // direction: -1 = left   1 = right 2 = Forward -2 = Backwards// while(condition){ Move(2,127) };//THIS MOVES FORWARD UNTIL CONDITION IS MET
void Move(int direction, int speed)
{
	int left = 0, right = 0;
	if (direction == 1){left = 1; right = -1;}
	else if (direction == -1){left = -1; right =  1; }
	else if (direction == 2) {left =  1; right =  1; }
	else if (direction == -2){left = -1; right = -1; }
	else if (direction == 3){left = 1; right = 0; }
	else if (direction == -3){left = 0; right = 1; }
	else if (direction == 4){left = -1; right = 0; }
	else if (direction == -4){left = 0; right = -1; }
	motor[LM] = speed*left;
	motor[L1] = speed*left;
	motor[L2] = speed*left;
	motor[RM] = speed*right;
	motor[R1] = speed*right;
	motor[R2] = speed*right;
}

///////////////////////////////////////TURN BASED ON GYRO DEGREES EXAMPLE // TurnDegree(-90, 127);//THIS TURNS LEFT 90 DEGREES AT 127 POWER
void TurnDegree(int degrees, int speed)//, int Timeout)
{
	int left = 0, right = 0;
	SensorValue[Gyro] = 0;
	wait1Msec(50);
	if (degrees < 0){left = -1; right = 1;}
	else if (degrees > 0){left = 1; right = -1; }
	float ticks = abs(degrees*7.7);
	clearTimer(T3);

	while(abs(SensorValue[Gyro]) < ticks)
	{
		////////////////////////////////////FAILASFE TIMEOUT
		//	if(time1[T3] > TimeOut && TimeOut > 0){ FailSafeEngaged = 1; break;}
		////////////////////////////////////////////////////
		motor[LM] = speed*left;
		motor[L1] = speed*left;
		motor[L2] = speed*left;
		motor[RM] = speed*right;
		motor[R1] = speed*right;
		motor[R2] = speed*right;
	}
	motor[LM] = (speed*left*-1)/4;
	motor[L1] = (speed*left*-1)/4;
	motor[L2] = (speed*left*-1)/4;
	motor[RM] = (speed*left*-1)/4;
	motor[R1] = (speed*right*-1)/4;
	motor[R2] = (speed*right*-1)/4;
	wait1Msec(150);
	StopDrive();
}
void MoveTime(int time, int speed)
{
	motor[LM] = speed;
	motor[L1] = speed;
	motor[L2] = speed;
	motor[RM] = speed;
	motor[R1] = speed;
	motor[R2] = speed;
	wait1Msec(time);
	motor[LM] 	= (speed*-1)/4;
	motor[L1] 	= (speed*-1)/4;
	motor[L2] 	= (speed*-1)/4;
	motor[RM] 	= (speed*-1)/4;
	motor[R1] = (speed*-1)/4;
	motor[R2] = (speed*-1)/4;
	wait1Msec(250);
	StopDrive();
}
///////////////////////////////////////MOVE FORWARD/BACKWARDS BASED ON ENCODER READING// while(MoveFwdDist(-10, 127) == 1){DO SOMETHING LIKE INTAKE ON}//THIS MOVES BACKWARDS FOR 10 INCHES AT POWER 127
int MoveDist(int inches, int speed, int TimeOut)
{
	int status, direction = 0;
	//RESET ENCODER/////
	if (MoveCounter == 0 )
	{
		SensorValue[LeftEnc] = 0;
		wait1Msec(50);
		MoveCounter = 1;
		clearTimer(T3);
	}
	//TIME OUT FAILSAFE
	if(time1[T3]>TimeOut){MoveCounter=0;StopDrive();return 0;}
	////////////////

	if (inches < 0){direction = -1;}
	else if (inches > 0){direction = 1;}
	int ticks = abs(inches*360/17); ///NEEDS TO BE ADJUSTED BASED ON ENCONDER RATIO
	if(abs(SensorValue[LeftEnc]) < ticks) //ENCODER TO USE FOR DISTANCE
	{
		motor[LM] 	= speed*direction;
		motor[L1] 	= speed*direction;
		motor[L2] 	= speed*direction;
		motor[RM] 	= speed*direction;
		motor[R1] 	= speed*direction;
		motor[R2] = speed*direction;
		status = 1;
	}
	else
	{
		motor[LM] = (speed*direction*-1)/8;
		motor[L1] = (speed*direction*-1)/8;
		motor[L2] = (speed*direction*-1)/8;
		motor[RM] = (speed*direction*-1)/8;
		motor[R1] = (speed*direction*-1)/8;
		motor[R2] = (speed*direction*-1)/8;
		delay(150);
		StopDrive();
		status = 0;
		MoveCounter = 0;
	}
	return status;
}
//int MoveSonar(int inches, int speed, int TimeOut)
//{
//	int status, direction = 0;
//	if (MoveCounter == 0 )
//	{
//		MoveCounter = 1;
//		clearTimer(T3);
//	}
//	//TIME OUT FAILSAFE
//	if(time1[T3]>TimeOut){MoveCounter=0;StopDrive();return 0;}
//	////////////////

//	if(SensorValue[sonar] > inches) //DECREASE THE GAP BETWEEM ROBOT AND OBJECT
//	{
//		direction = 1;
//		motor[LM] = speed*direction;
//		motor[L1] = speed*direction;
//		motor[L2] = speed*direction;
//		motor[RM] = speed*direction;
//		motor[R1] = speed*direction;
//		motor[R2] = speed*direction;
//		status = 1;
//	}
//	else if(SensorValue[sonar] < inches)//INCREASE THE GAP BETWEEN ROBOT AND OBJECT
//	{
//		direction = -1;
//		motor[LM] = speed*direction;
//		motor[L1] = speed*direction;
//		motor[L2]	= speed*direction;
//		motor[RM]	= speed*direction;
//		motor[R1]	= speed*direction;
//		motor[R2] = speed*direction;
//		status = 1;
//	}
//	else if(SensorValue[sonar] < 0)			//IF SONAR DOES'NT DETECT ANYTHING
//	{
//		status = 0;
//	}
//	else
//	{
//		motor[LM] = (speed*direction*-1)/8;
//		motor[L1] = (speed*direction*-1)/8;
//		motor[L2] = (speed*direction*-1)/8;
//		motor[RM] = (speed*direction*-1)/8;
//		motor[R1] = (speed*direction*-1)/8;
//		motor[R2] = (speed*direction*-1)/8;
//		delay(150);
//		StopDrive();
//		status = 0;
//		MoveCounter = 0;
//	}
//	wait1Msec(20);
//	return status;
//}

void MoveArm(int speed)
{
	motor[leftArmM] = speed;
	motor[leftArmY] = speed;
	motor[rightArmM] = speed;
	motor[rightArmY] = speed;
}

int ArmAngle(float angle, int speed, int TimeOut)
{
	int status, direction;
	//RESET ENCODER/////
	if (MoveCounter == 0 )
	{
		SensorValue[ArmEnc] = 0;
		wait1Msec(50);
		MoveCounter = 1;
		clearTimer(T3);
	}
	////////////////////

	//TIME OUT FAILSAFE
	if(time1[T3]>TimeOut){FailSafeEngaged=1;MoveCounter=0;StopDrive();return 0;}
	////////////////


	float ticks = abs(angle)*5;//2*(7/5);
	if(angle<0){direction=-1;}
	if(angle>0){direction=1;}
	if(abs(SensorValue[ArmEnc])<ticks)
	{
		motor[leftArmM]=speed*direction;
		motor[leftArmY]=speed*direction;
		motor[rightArmM]=speed*direction;
		motor[rightArmY]=speed*direction;
		status=1;
	}
	else
	{
		motor[leftArmM]=speed/8;
		motor[leftArmY]=speed/8;
		motor[rightArmM]=speed/8;
		motor[rightArmY]=speed/8;
		status=0;
		MoveCounter=0;
	}
	return status;
}

	void StopArm()
	{
		motor[leftArmY] = 0;
		motor[leftArmM] = 0;
		motor[rightArmY] = 0;
		motor[rightArmM] = 0;
	}
	//////////////////////////////////////////////////// RETURNS TRUE IF LEFT LINE TRACKER SEES THE LINE
	//int LineStatusLeft (void)
	//{
	//	if (SensorValue[leftLine] < 700)
	//		return 1;
	//	else
	//		return 0;
	//}
	////////////////////////////////////////////////////// RETURNS TRUE IF RIGHT LINE TRACKER SEES THE LINE
	//int LineStatusRight (void)
	//{
	//	if (SensorValue[rightLine] < 700)
	//		return 1;
	//	else
	//		return 0;
	//}

	//int LineStatusMiddle (void)
	//{
	//	if (SensorValue[midLine] < 1000)
	//		return 1;
	//	else
	//		return 0;
	//}

	//int punchFollowLine(int initial, float proportion, int TimeOut)		//FOLLOW ZERO ZONE LINE USING TWO ENCODERS//
	//{	///ADJUST THE POWER OF BOTH SIDES OF DRIVETRAIN///
	//	int left, right;
	//	float lineError=0;
	//	//RESET TIMER AND PUNCH COUNTER
	//	if(MoveCounter==0)
	//	{
	//		clearTimer(T3);
	//		MoveCounter=1;
	//		pistonCount=0;
	//	}
	//	lineError = proportion*(SensorValue[rightLine]-SensorValue[leftLine]);

	//	int speed = abs(lineError);
	//	if(lineError<0){left=1;right=-1;}
	//	if(lineError>0){left=-1;right=1;}

	//	motor[LM]	= initial+(speed*left);
	//	motor[L1] = initial+(speed*left);
	//	motor[L2] = initial+(speed*left);
	//	motor[RM] = initial+(speed*right);
	//	motor[R1] = initial+(speed*right);
	//	motor[R2] = initial+(speed*right);
	//	///PUNCHER
	//	if(SensorValue[punchIR]<700){pistonActive = 1;}
	//	if(pistonActive==1 && pistonCount<12)
	//	{
	//		if(firstRun==false){clearTimer(T1);	firstRun=true;pistonCount++;}
	//		if(time1[T1]<275){SensorValue[puncher]=1;}
	//		else{SensorValue[puncher]=0;	pistonActive=0;}
	//	}
	//	else{firstRun=false;SensorValue[puncher]=0;}
	//	//////////////////////////////
	//	//FAIL SAFE//
	//	if(time1[T3]>TimeOut){MoveCounter=0;StopDrive();return 0;}
	//	else{return 1;MoveCounter=1;}
	//	////////////////////////////////////
	//	wait1Msec(20);
	//}

	void clawStatus(int value)
	{
		SensorValue[clawL]=value;
		SensorValue[clawR]=value;
	}

	void KillALL(void)
	{
		StopArm();
		StopDrive();
	}
