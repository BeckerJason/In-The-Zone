void DebugCode(void)
{
	//RESET////////////////
	motor[roller] = 60;
	while(FBControl(1));
	while(SensorValue[LiftLimit] != 1) LiftPow(-127);
	SensorValue[LiEnc] = 0;
	LiftPow(0);
	//////////////////////

	pidTurn(30,0.35, 0.05, 1.4, 3500);
	while(MoveDist(-40, 100, 5000, 1);
	pidTurn(-20, 0.35, 0.05, 1.4, 3500);
	while(MoveDist(-60, 100, 5000, 1);
}
