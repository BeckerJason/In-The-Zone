float globalDegrees;
float globalDistance;
bool gmoveandturn;
bool TaskRunning = false;

task PIDturnTask()
{
	TaskRunning = true;

	//SensorValue[Gyro]=0;

	int direction;
	float  pid_Kp = 0.25;
	float  pid_Ki = 0.005;
	float  pid_Kd = 1.40;

	SensorValue[Gyro]=0;
	//wait1Msec(100);
	float  pidError = 0;
	float  pidLastError = 0;
	float  pidIntegral = 0;
	float  pidDerivative = 0;

	while(1)
	{
		//Calculate Error//(Convert Dintance in inches to encoder ticks)
		pidError = abs(globalDegrees*10.2) - abs(SensorValue[Gyro]);

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
		if(gmoveandturn==false)
		motorPowerR(-direction * pidDriveR * PID_MOTOR_SCALE);
		motorPowerL(direction * pidDriveR * PID_MOTOR_SCALE);
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

		if((-10 < pidError) && (pidError > 10) && nextMove==false){nextMove = true;	clearTimer(T1);}
		if(time1[T1]>2000 && nextMove==true){nextMove=false;break;}

		//REFRESH RATE 60Hz
		wait1Msec(20);
	}
	StopDrive();
	TaskRunning = false;
}

task PIDmoveTask()
{
	TaskRunning = true;
	//SET SENSORS TO 0
	//SensorValue[Gyro]=0;
	//wait1Msec(100);
	SensorValue[LeftEnc]=0;
	///////////////////
	//DEFINE VARIABLES//
	float  pid_Kp = 0.25;
	float  pid_Ki = 0.017;
	float  pid_Kd = 0.5;

	float  pidError = 0;
	float  pidLastError = 0;
	float  pidIntegral = 0;
	float  pidDerivative = 0;
//////////////////////////////
	while(1)
	{
		//Calculate Error//(Convert Dintance in inches to encoder ticks)
		pidError = abs(globalDistance*360/12.7) - abs(SensorValue[LeftEnc]);

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
		if(globalDistance>0){
			motorPowerR(pidDriveR * PID_MOTOR_SCALE + SensorValue[Gyro]/6);
			motorPowerL(pidDriveR * PID_MOTOR_SCALE - SensorValue[Gyro]/6);
		}
		if(globalDistance<0)
		{
			motorPowerR(-pidDriveR * PID_MOTOR_SCALE - SensorValue[Gyro]/6);
			motorPowerL(-pidDriveR * PID_MOTOR_SCALE + SensorValue[Gyro]/6);
		}
		///////////////////////////////////////
		//STRAIGHT LINE CORRECTION

		//KILL IT AFTER A SERTAIN TIME ON THE AREA OF THE TARGET
		if((-10 < pidError) && (pidError > 10) && nextMove==false){nextMove = true;	clearTimer(T1);}
		if(time1[T1]>2000 && nextMove==true){nextMove=false;break;}
		///////////////////////////////////////////////////////
		//REFRESH RATE/////////////////////////////////
		wait1Msec(20);
	}
	StopDrive();
	TaskRunning = false;
}
