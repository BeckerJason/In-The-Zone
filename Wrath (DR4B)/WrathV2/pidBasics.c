#define PID_MOTOR_SCALE     1
#define PID_MOTOR_MAX       127
#define PID_MOTOR_MIN     (-127)
#define PID_INTEGRAL_LIMIT  50

bool nextMove = false;
float pidDriveR;
float pidDriveL;
//FUNCTION USED BY THE PID FUNCTIONS
void motorPower(float power)
{
	motor[LM] = power;
	motor[L1] = power;
	motor[L2] = power;
	motor[RM] = -power;
	motor[R1] = -power;
	motor[R2] = -power;
}
void motorPowerR(float power)
{
	motor[RM] = power;
	motor[R1] = power;
	motor[R2] = power;
}
void motorPowerL(float power)
{
	motor[LM] = power;
	motor[L1] = power;
	motor[L2] = power;
}
////////////////////////////////
//moveandturn = 0 -> center turn, moveandturn = 1 -> move forward and turn, moveandturn = -1 -> move backwards and turn
void pidTurn(float degrees, int moveandturn)
{
	int direction;

	float  pid_Kp = 0.25;
	float  pid_Ki = 0.01;//0.015
	float  pid_Kd = 0.0;

	//SensorValue[Gyro]=0;
	//wait1Msec(100);
	float  pidError = 0;
	float  pidLastError = 0;
	float  pidIntegral = 0;
	float  pidDerivative = 0;

	while(1)
	{
		//writeDebugStreamLine("%d", SensorValue[Gyro]);
		//Calculate Error//(Convert Dintance in inches to encoder ticks)15.65
		pidError = abs(degrees*9.57) - abs(SensorValue[Gyro]);//7.4

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
		if(degrees>0)	direction = 1;
		if(degrees<0) direction = -1;
		if(moveandturn==0)
			motorPowerR(-direction * pidDriveR * PID_MOTOR_SCALE);
		motorPowerL(direction * pidDriveR * PID_MOTOR_SCALE);
		//MOVE FORWARD WHILE TURNING
		if(moveandturn!=0)
		{
			if(degrees > 0)
			{
				motorPowerR(moveandturn*pidDriveR * PID_MOTOR_SCALE / 25);
				motorPowerL(moveandturn*pidDriveR * PID_MOTOR_SCALE);
			}
			if(degrees < 0)
			{
				motorPowerR(moveandturn*pidDriveR * PID_MOTOR_SCALE);
				motorPowerL(moveandturn*pidDriveR * PID_MOTOR_SCALE / 25);
			}
		}
		///////////////////////////////////////
		if((-2 < pidError) && (pidError > 2) && nextMove==false){nextMove = true;	clearTimer(T1);}
		if(time1[T1]>2000 && nextMove==true){nextMove=false;break;}
		//REFRESH RATE 60Hz
		wait1Msec(20);
	}
	StopDrive();
}

void pidMove(float distance)
{
	//SET SENSORS TO 0
	//SensorValue[Gyro]=0;
	SensorValue[LeftEnc]=0;
	wait1Msec(100);
	///////////////////
	//DEFINE VARIABLES//
	float  pid_Kp = 0.3;
	float  pid_Ki = 0.0;
	float  pid_Kd = 0;

	float  pidError = 0;
	float  pidLastError = 0;
	float  pidIntegral = 0;
	float  pidDerivative = 0;
	//////////////////////////////
	while(1)
	{
		//Calculate Error//(Convert Dintance in inches to encoder ticks)
		pidError = abs(distance*360/16.5) - abs(SensorValue[LeftEnc]);

		// integral - if Ki is not 0
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
		if( pidDriveR > PID_MOTOR_MAX )	pidDriveL = PID_MOTOR_MAX;
		if( pidDriveR < PID_MOTOR_MIN )	pidDriveL = PID_MOTOR_MIN;
		///////////////////////////////////////
		//SEND POWER TO MOTORS/////////////////
		if(distance>0){
			motorPowerR(pidDriveR * PID_MOTOR_SCALE);// + SensorValue[Gyro]);
			motorPowerL(pidDriveR * PID_MOTOR_SCALE);// - SensorValue[Gyro]);
		}
		if(distance<0)
		{
			motorPowerR(-pidDriveR * PID_MOTOR_SCALE);// - SensorValue[Gyro]);
			motorPowerL(-pidDriveR * PID_MOTOR_SCALE);// + SensorValue[Gyro]);
		}
		///////////////////////////////////////
		//STRAIGHT LINE CORRECTION

		//KILL IT AFTER A SERTAIN TIME ON THE AREA OF THE TARGET
		if((-2 < pidError) && (pidError > 2) && nextMove==false){nextMove = true;	clearTimer(T1);}
		if(time1[T1]>2000 && nextMove==true){nextMove=false;break;}
		///////////////////////////////////////////////////////
		//REFRESH RATE/////////////////////////////////
		wait1Msec(20);
	}
}
