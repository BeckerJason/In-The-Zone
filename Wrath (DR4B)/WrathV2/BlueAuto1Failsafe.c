////////////////////////////////////////FAILSAFE 1
void BLUE1FailSafe1(void)
{
	FailSafeEngaged = 0;
	displayLCDCenteredString(0, "FAILSAFE 1");
	displayLCDCenteredString(1, "ENGAGED");
	KillALL();
	//*******************//
	while(MoveDist(-5, 80,3000) == 1)delay(200);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	TurnDegree(-20,70,3000);delay(200);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	MoveTime(800,-60);
	//*******************//
	while(MoveDist(2, 80,3000) == 1)delay(200);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	TurnDegree(10,70,3000);delay(200);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	while(MoveDist(26, 35, 5000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 150; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(2, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	KillALL();
	while(1);
}
////////////////////////////////////////FAILSAFE 2
void BLUE1FailSafe2(void)
{
	FailSafeEngaged = 0;
	displayLCDCenteredString(0, "FAILSAFE 2");
	displayLCDCenteredString(1, "ENGAGED");
	KillALL();
	TurnDegree(-40,70,3000);delay(200);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	while(MoveDist(15, 35, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 150; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(2, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	IntakeOff();
	while(1);
}
////////////////////////////////////////FAILSAFE 3
void BLUE1FailSafe3(void)
{
	FailSafeEngaged = 0;
	displayLCDCenteredString(0, "FAILSAFE 3");
	displayLCDCenteredString(1, "ENGAGED");
	KillALL();
	if(BallCounter > 1)/////////////////////////////////////////////////////////////////////////////////IF MORE TWO BALLS INSIDE
	{
		//*******************//
		clearTimer(T3);
		while(LineStatusBack() == 0)
		{
			Move(-2,60);
			if(time1[T3] > 5000 && 5000 > 0){ FailSafeEngaged = 1; break;}
		}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		StopDrive(); delay(500);
		//*******************//
		TurnDegree(-90,100,3000);
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		StartLauncher(2200);
		//*******************//
		MoveTime(1400,-60);
		//*******************//
		while(MoveDist(6, 50, 3000) == 1);delay(500);
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		TurnDegree(22,100,3000);delay(500);
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		IntakeShoot(10000); // LAUNCH NEXT 4
		//*******************//
		StopLauncher();
		//*******************//
		TurnDegree(-10,70,3000);delay(200);
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		while(MoveDist(26, 35, 5000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		for(int i = 0; i < 150; i++){IntakeOnAuto(); delay(10);}
		//*******************//
		while(MoveDist(2, 30, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
		//*******************//
		while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
		//*******************//
		while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
		//*******************//
		while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
		//*******************//
		while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
		//*******************//
		while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		IntakeOff();
	}else/////////////////////////////////////////////////////////////////////////////////IF LESS TWO BALLS INSIDE
	{
		clearTimer(T3);
		while(LineStatusBack() == 0)
		{
			Move(-2,40);
			if(time1[T3] > 5000 && 5000 > 0){ FailSafeEngaged = 1; break;}
		}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		StopDrive(); delay(500);
		//*******************//
		TurnDegree(-80,100,3000);
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		while(MoveDist(26, 35, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		for(int i = 0; i < 150; i++){IntakeOnAuto(); delay(10);}
		//*******************//
		while(MoveDist(2, 30, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
		//*******************//
		while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
		//*******************//
		while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
		//*******************//
		while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
		//*******************//
		while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
		//*******************//
		while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
		if(FailSafeEngaged){KillALL(); while(1);}
		//*******************//
		IntakeOff();
	}
	while(1);
}
////////////////////////////////////////FAILSAFE 4
void BLUE1FailSafe4(void)
{
	FailSafeEngaged = 0;
	displayLCDCenteredString(0, "FAILSAFE 4");
	displayLCDCenteredString(1, "ENGAGED");
	KillALL();
	while(MoveDist(4, 30, 3000) == 1);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	TurnDegree(-90,100,3000);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
		clearTimer(T3);
		while(LineStatusFront() == 0)
		{
			Move(2,50);
			if(time1[T3] > 5000 && 5000 > 0){ FailSafeEngaged = 1; break;}
		}
		if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	StopDrive(); delay(500);
	//*******************//
	StartLauncher(2100);
	//*******************//
		clearTimer(T3);
		while(LineStatusFront() == 0)
		{
			Move(1,50);
			if(time1[T3] > 5000 && 5000 > 0){ FailSafeEngaged = 1; break;}
		}
		if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	StopDrive(); delay(1500);
	//*******************// MIGHT NEED TO CHANGE ANGLE
	IntakeShoot(10000); // LAUNCH NEXT 4
	//*******************//
	StopLauncher();
	while(1);
}
////////////////////////////////////////FAILSAFE 5
void BLUE1FailSafe5(void)
{
	FailSafeEngaged = 0;
	displayLCDCenteredString(0, "FAILSAFE 5");
	displayLCDCenteredString(1, "ENGAGED");
	KillALL();
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	IntakeOff();
	//*******************//
	TurnDegree(-90,100,3000);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	StartLauncher(2200);
	//*******************//
	MoveTime(1400,-60);
	//*******************//
	while(MoveDist(6, 50, 3000) == 1);delay(500);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	TurnDegree(22,100,3000);delay(500);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	IntakeShoot(10000); // LAUNCH NEXT 4
	//*******************//
	StopLauncher();
	//*******************//
	TurnDegree(-22,100,30000);delay(500);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	while(MoveDist(30, 50, 3000) == 1);delay(500);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	TurnDegree(-45,100,3000);delay(500);
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	while(MoveDist(26, 35, 5000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 150; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(2, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	for(int i = 0; i < 50; i++){IntakeOnAuto(); delay(10);}
	//*******************//
	while(MoveDist(4, 30, 3000) == 1){IntakeOnAuto();}
	if(FailSafeEngaged){KillALL(); while(1);}
	//*******************//
	IntakeOff();
	while(1);
}
////////////////////////////////////////FAILSAFE 6 //NOTHING TO DO, AUTO IS SCREWD HERE
void BLUE1FailSafe6(void)
{
	KillALL();
	displayLCDCenteredString(0, "FAILSAFE 6");
	displayLCDCenteredString(1, "ENGAGED");
	while(1);
}
////////////////////////////////////////FAILSAFE 7 //NOTHING TO DO, AUTO IS SCREWD HERE
void BLUE1FailSafe7(void)
{
	displayLCDCenteredString(0, "FAILSAFE 7");
	displayLCDCenteredString(1, "ENGAGED");
	while(1);
}
////////////////////////////////////////FAILSAFE 8 //NOTHING TO DO, AUTO IS SCREWD HERE
void BLUE1FailSafe8(void)
{
	KillALL();
	displayLCDCenteredString(0, "FAILSAFE 8");
	displayLCDCenteredString(1, "ENGAGED");
	while(1);
}
