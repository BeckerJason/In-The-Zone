#define PID_MOTOR_SCALE     1
#define PID_MOTOR_MAX       127
#define PID_MOTOR_MIN     (-127)
#define PID_INTEGRAL_LIMIT  50

void KIllALL()
{
	motor[R1] = 0;
	motor[RM] = 0;
	motor[L1] = 0;
	motor[LM] = 0;

	motor[LiftL] = 0;
	motor[LiftR] = 0;

	motor[fb1] = 0;
	motor[fb2] = 0;

	motor[roller] = 0;
}

void StopDrive()
{
	motor[R1] = 0;
	motor[RM] = 0;
	motor[L1] = 0;
	motor[LM] = 0;
}

void rightDrive (int power)
{
	motor[RM]	= power*bs1;
	motor[R1]	= power*bs2;
}
void leftDrive (int power)
{
	motor[LM] 	= power*bs1;
	motor[L1] 	= power*bs2;
}

void move (int power)
{
	motor[R1] = power*bs2;
	motor[RM] = power*bs1;
	motor[L1] = power*bs2;
	motor[LM] = power*bs1;
}
void LiftPow (int power)
{
	motor[LiftR] = power*bs1;
	motor[LiftL] = power*bs1;
}

//ud = 1; Four Bar up  || else; Four Bar Down
int FBControl (int ud)
{
	if(MoveCounter==0)
	{
		clearTimer(T2);
		MoveCounter = 1;
	}

	//Up//
	if(ud)
	{
		if(SensorValue[FourBarLimit] != 1 && time1[T2] < 1500)
		{
			motor[fb1]=-127;
			motor[fb2]=-127;
			return 1;
		}
		else
		{
			MoveCounter = 0;
			SensorValue[FBEnc] = 0;
			motor[fb1]=-25;
			motor[fb2]=-25;
			fbStatus = -1;
			return 0;
		}
	}
	//Down//
	else
	{
		if(SensorValue[FBEnc] < 190 && time1[T2] < 1500)
		{
			motor[fb1]=127;
			motor[fb2]=127;
			return 1;
		}
		else
		{
			MoveCounter = 0;
			motor[fb1]=0;
			motor[fb2]=0;
			wait1Msec(150);
			motor[fb1]=15;
			motor[fb2]=15;
			fbStatus = -1;
			return 0;
		}
	}
	wait1Msec(20);
}

//dir = 1 ; Intake in, send 1 -- dir = -1 ; Intake out//
int intake(int dir)
{
	if(dir == 1)
	{
		//////////////
		if (MoveCounter == 0)
		{
			SensorValue[rol] = 0;
			motor[roller] = 127;
			wait1Msec(150);
			encVal = abs(SensorValue[rol]);
			MoveCounter = 1;
		}
		else
		{
			motor[roller] = 127;
			SensorValue[rol] = 0;
			wait1Msec(100);
			encVal = abs(SensorValue[rol]);
		}
		///////////////

		if(encVal < 30)
		{
			motor[roller] = 30;
			MoveCounter = 0;
			state = 0;
		}
		else
		{
			state = 1;
		}
	}
	else
	{
		motor[roller] = -127;
		wait1Msec(250);
		motor[roller] = 0;
		state = 0;
	}
	return state;
}

//dir = 1; take out mg, else take in
int MGControl(int dir)
{
	int status = 0;
	if(dir)
	{
		if(SensorValue[MPot] < 1800)
		{
			motor[MG] = -127;
			status = 1;
		}
		else{
			motor[MG] = 0;
			status = 0;
		}
	}
	else
	{
		if(SensorValue[MPot] > 0)
		{
			motor[MG] = 127;
			status = 1;
		}
		else
		{motor[MG] = 0;
			status = 0;
		}
	}
	return status;
	wait1Msec(20);
}

int MoveDist(float inches, int speed, int TimeOut, int brea)
{
	int status, direction = 0;
	int error;
	//RESET ENCODER/////
	if (MoveCounter == 0 )
	{
		SensorValue[LEnc] = 0;
		SensorValue[REnc] = 0;
		MoveCounter = 1;
		clearTimer(T3);
	}
	//TIME OUT FAILSAFE
	if(time1[T3]>TimeOut){MoveCounter=0;StopDrive();return 0;}
	////////////////
	//ERROR CALC
	error = abs(SensorValue[LEnc])-abs(SensorValue[REnc]);
	////////////////////////////////////////
	if (inches < 0){direction = -1;}
	else if (inches > 0){direction = 1;}
	float ticks = abs(inches*392/2/3.18/4.1); ///NEEDS TO BE ADJUSTED BASED ON ENCONDER RATIO
	if(abs(SensorValue[LEnc]) < ticks) //ENCODER TO USE FOR DISTANCE
	{
		rightDrive((speed+error)*direction);
		leftDrive((speed-error)*direction);
		//motor[L1] = speed*direction+error;
		//motor[LM] = speed*direction+error;
		//motor[R1] = (speed*direction-error);
		//motor[RM] = (speed*direction-error);
		status = 1;
	}
	else
	{
		if(brea)
		{
		rightDrive((speed*direction*-1)/8);
		leftDrive((speed*direction*-1)/8);
		delay(150);
		}
		//motor[R1] = (speed*direction*-1)/8;
		//motor[RM] = (speed*direction*-1)/8;
		//motor[L1] = (speed*direction*-1)/8;
		//motor[LM] = (speed*direction*-1)/8;
		StopDrive();
		status = 0;
		MoveCounter = 0;
	}
	return status;
	wait1Msec(20);
}

void pidTurn(int globalDegrees, float pid_Kp, float pid_Ki, float pid_Kd, int timeout)
{
	//float  pid_Kp = 0.35;
	//float  pid_Ki = 0;//0.05;
	//float  pid_Kd = 0;//1.40;
	int direction = 0;
	SensorValue[gyro]=0;
	float  pidError = 0;
	float  pidLastError = 0;
	float  pidIntegral = 0;
	float  pidDerivative = 0;

	float pidDriveR = 0;

	clearTimer(T3);
	while(time1[T3] < timeout)
	{
		//Calculate Error//(Convert Dintance in inches to encoder ticks)
		pidError = abs(globalDegrees*10.32) - abs(SensorValue[gyro]);

		// integral - if Ki is not 0(can put threshold)
		if( pid_Ki != 0 )
		{
			// If we are inside controlable window then integrate the error
			if( abs(pidError) < PID_INTEGRAL_LIMIT )	pidIntegral = pidIntegral + pidError;
			else	pidIntegral = 0;
		}
		else	pidIntegral = 0;
		///////////////////////////////////////
		//CALCULATE DERIVATIVE/////////////////
		pidDerivative = pidError - pidLastError;
		pidLastError  = pidError;
		//////////////////////////////////////
		//CALCULATE DRIVE/////////////////////
		pidDriveR = (pid_Kp * pidError) + (pid_Ki * pidIntegral) + (pid_Kd * pidDerivative);
		///////////////////////////////////////
		//LIMIT DRIVE//////////////////////////
		if( pidDriveR > PID_MOTOR_MAX )	pidDriveR = PID_MOTOR_MAX;
		if( pidDriveR < PID_MOTOR_MIN )	pidDriveR = PID_MOTOR_MIN;
		///////////////////////////////////////
		//SEND POWER TO MOTORS/////////////////
		if(globalDegrees>0)	direction = 1;
		if(globalDegrees<0) direction = -1;
		//if(gmoveandturn==false)
		motor[R1] = (direction * pidDriveR * PID_MOTOR_SCALE)*bs2;
		motor[RM] = (direction * pidDriveR * PID_MOTOR_SCALE)*bs1;
		motor[L1] = (-direction * pidDriveR * PID_MOTOR_SCALE)*bs2;
		motor[LM] = (-direction * pidDriveR * PID_MOTOR_SCALE)*bs1;
		/*
		//MOVE FORWARD WHILE TURNING
		if(gmoveandturn==true)
		{
		if(globalDegrees > 0)
		{
		motorPowerR(pidDriveR * PID_MOTOR_SCALE / 20);
		motorPowerL(pidDriveR * PID_MOTOR_SCALE);
		}
		if(globalDegrees < 0)
		{
		motorPowerR(pidDriveR * PID_MOTOR_SCALE);
		motorPowerL(pidDriveR * PID_MOTOR_SCALE / 20);
		}
		}
		///////////////////////////////////////
		*/
		if((abs(pidError) < 10) && (abs(avgSpeed) < 10)){
			StopDrive();
			break;
		}
		if(time1[T1]<60){avgError += pidError;}
		else{avgSpeed = avgError/3;avgError=0;clearTimer(T1);}

		//REFRESH RATE 60Hz
		wait1Msec(20);
	}
	StopDrive();
}
