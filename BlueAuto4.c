void BlueAuto4(void)
{
	//RESET////////////////
	motor[roller] = 50;
	while(FBControl(1));
	while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(0);


	//////////////////////
	/**/
	//**************PART 1; GO FOR MG AND PRE-LOADS***********************************************************************

	while(MoveDist(10, 65, 5000, 1))
	{
		//if(MGControl(1))
		//else	motor[MG] = -90;
	}
	motor[MG] = 0;

	while(MgControl(0))
	{
		//rightDrive(20);
		//leftDrive(20);
	}
	StopDrive();

	//while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	//SensorValue[LiEnc] = 0;
	//LiftPow(-30);


	//ALIGN WITH MID CONES
	//NO MOBILE GOAL ON
	pidTurn(47, 0.35, 0.08, 1.4, 3500);
	//pidTurn(45, 0.4, 0.1, 1.0, 3500);

	while(MoveDist(100,100, 5000, 1));
	while(MoveDist(5, 20, 2000, 1));
	while(MoveDist(-38,100, 5000, 1));


	//START BRINGING OUT MG BEFORE TURN TO FACE MG
	motor[MG] = -127;
	pidTurn(35, 0.4, 0.1, 1.0, 3500);
	while(MoveDist(15, 40, 5000, 1))
	{	if(MgControl(1)){}
		else
			motor[MG] = -90;
	}
	motor[MG] = 0;
	StopDrive();
	while(MgControl(0)){}


	///DROP THE CONE
	while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(-30);

	intake(0);
	wait1Msec(300);


	while(MoveDist(-25,100, 5000, 1)){}
	wait1Msec(250);
	pidTurn(110, 0.35, 0.05, 1.4, 3500);
	while(MoveDist(40,100, 5000, 1)){}
	pidTurn(40, 0.4, 0.1, 1.0, 3500);
	while(MoveDist(25, 40, 5000, 1)){}
	LiftPow(30);
	while(MgControl(1)){}
	//PULL OUT OF ZONE\\
	while(MoveDist(-5, 100, 5000, 1)){MGControl(0);}
	wait1Msec(250);
	motor[MG] = 0;
	while(FBControl(1));
	while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(0);

	//ALIGN PARALLEL TO LINE

	pidTurn(-90, 0.35, 0.05, 1.4, 3500);

	//GO TO TURN TOWARDS 2ND MG
	while(MoveDist(42, 100, 5000, 1));

	while(FBControl(1));
	while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(0);

	//ALIGN PARALLEL TO 2ND MG
	//REVERSED
	pidTurn(-85, 0.35, 0.08, 1.4, 3500);










	//RESET////////////////



	//////////////////////
	/**/
	//**************PART 1; GO FOR MG AND PRE-LOADS***********************************************************************

	//while(MoveDist(2, 65, 5000, 1))
	//{
	//	//if(MGControl(1))
	//	//else	motor[MG] = -90;
	//}
	//motor[MG] = 0;

	//while(MgControl(0))
	//{
	//	//rightDrive(20);
	//	//leftDrive(20);
	//}
	//StopDrive();

	//while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	//SensorValue[LiEnc] = 0;
	//LiftPow(-30);


	//ALIGN WITH MID CONES
	//NO MOBILE GOAL ON
	//pidTurn(-37, 0.35, 0.08, 1.4, 3500);
	//pidTurn(45, 0.4, 0.1, 1.0, 3500);

	while(MoveDist(100, 100, 5000, 1));
	while(MoveDist(5, 20, 2000, 1));
	while(MoveDist(-38,100, 5000, 1));


	//START BRINGING OUT MG BEFORE TURN TO FACE MG
	LiftPow(30);
	motor[MG] = -127;
	wait1Msec(250);
	pidTurn(-35, 0.4, 0.1, 1.0, 3500);
	while(MoveDist(15, 40, 5000, 1))
	{
		MgControl(1);
		//if(){}
		//else
		//	motor[MG] = -90;
	}
	motor[MG] = 0;
	StopDrive();
	while(MgControl(0)){}


	///DROP THE CONE
	while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(-30);

	intake(0);
	wait1Msec(300);


	while(MoveDist(-25,100, 5000, 1)){}
	wait1Msec(250);
	pidTurn(-110, 0.35, 0.05, 1.4, 3500);
	while(MoveDist(40,100, 5000, 1)){}
	pidTurn(-40, 0.4, 0.1, 1.0, 3500);
	while(MoveDist(25, 40, 5000, 1)){}
	LiftPow(30);
	while(MgControl(1)){}
	//PULL OUT OF ZONE\\
	while(MoveDist(-10, 100, 5000, 1)){MGControl(0);LiftPow(-60);}
	wait1Msec(250);
	while(1);


}
