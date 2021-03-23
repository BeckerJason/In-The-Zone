//!!!!!!!!!! CHECK VOLTAGES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	pr.mult=PCheck(nImmediateBatteryLevel/1000.0);
	se.mult=SCheck(SensorValue[BackUpBattery]/280.0);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//!!!!!!!!!! SET INITIAL X AND Y !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	initial.xval=1; //Initial X and Y set units of # of Tiles
	initial.yval=3;
	initial.angle=-450.0;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	clearDebugStream();
	resetMotorEncoder(rightArm1);
	resetMotorEncoder(leftArm1);
	SensorValue[I2C_2]=0;
	SensorValue[gyro]=0;
	///ALWAYS GYRO*0.973

	//##########   RECORD  ####################################################
	if (SensorValue[Jumper]==1)
	{record=1;}
	else{	int record=0;}
	//########################################################################


	//*****************RESET GYRO***************************
	//Completely clear out any previous sensor readings by setting the port to "sensorNone"
	SensorType[gyro] = sensorNone;
	wait1Msec(1000);
	//Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
	SensorType[gyro] = sensorGyro;
	wait1Msec(2000);
	//*****************************************************************
