int bL,	bR,	l, cp, cm, mg, c, as;
while(1){
	//#### DRIVE BASE ########################################################################
	if(vexRT[Ch3] > 15 || vexRT[Ch4] > 15 || vexRT[Ch3] < -15 || vexRT[Ch4] < -15) //JOYSTICK DEADBAND
	{
		bL = vexRT[Ch3]*pr.mult + vexRT[Ch4]*pr.mult;		//Base Left Side
		bR = vexRT[Ch3]*pr.mult- vexRT[Ch4]*pr.mult;		//Base Right Side
	}
	else
	{
		bL=0;						//Stop Base Left Side
		bR=0;						//Stop Base Right Side
	}
	//#########################################################################################








	//~~~~ LIFT VALUES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if(vexRT[Ch2] > 15 || vexRT[Ch2] < -15)
	{
		l = vexRT[Ch2]*se.mult; //Lift Motors
	}
	else
	{
		l =0;	//Stop Lift Motors
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~





	//++++ CLAW ARM PRESETS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	/*if (vexRT[Btn7U]==1)
	{
	cp=3;			//Claw Preset Up
	}
	else  if (vexRT[Btn7R==1)
	{
	cp=2;			//Claw Preset Horizontal
	}
	else  if (vexRT[Btn7D==1)
	{
	cp=1;			//Claw Preset Down*/
	cp=0; //TEMPORARY FOR CLAW PRESET
	if (vexRT[Btn6U]==1&&vexRT[Btn6D]==0)
	{
		cm=127*pr.mult;
	}
	else if (vexRT[Btn6D]==1&&vexRT[Btn6U]==0)
	{
		cm=-127*pr.mult;
	}
	else
	{
		cm=10*pr.mult;
	}
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++








	//@@@@ MOBILE GOAL @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	if (vexRT[Btn8D]==1&&vexRT[Btn8R]==0)
	{
		mg=127*pr.mult; //Mobile Goal Up
	}
	else if (vexRT[Btn8R]==1&&vexRT[Btn8D]==0)
	{
		mg=-127*pr.mult; //Mobile Goal Down
	}
	else
	{
		mg=15*pr.mult;		//Value To Keep Mobile Goal Back
	}
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@






	//#### CLAW############################################################
	if (vexRT[Btn5U]==1){c=1;} //Claw Close
	else{c=0;}//Claw Open
	//########################################################################
	//$$$ AUTO STACK $$$$$$$$$$$$$$$$$$$$
	if(vexRT[Btn8L]==1)
	{as=1;}
	else if (vexRT[Btn7L]==1)
	{as=2;}
	else {as=0;}

	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

	if (SensorValue[Climit]==1)
	{SensorValue[enc]=0;
		writeDebugStreamLine("SensorValue[enc]=0;");
	}
	if (record==1)
	{
		if (vexRT[Btn8RXmtr2]==1)
		{
			T(90,127,25);
			writeDebugStreamLine("T(90,127,25);");
		}
		else{}
		if (vexRT[Btn8LXmtr2]==1)
		{
			T(-90,127,25);
			writeDebugStreamLine("T(-90,127,25);");
		}
		else{}
	}

	if (as==1)
	{
		DS(); 				//Base Left Side, Base Right Side, Lift Motors, Claw Preset, Claw Motor, Mobile Goal, Claw
		if(record==1){writeDebugStreamLine("DS();");}
		else{}
	}
	else if(as==2)
	{
		PL(1);
		if(record==1){writeDebugStreamLine("PL();");}
	}
	else
	{
		D(	bL,	bR,	l,cm, mg, c); 				//Base Left Side, Base Right Side, Lift Motors, Claw Preset, Claw Motor, Mobile Goal, Claw
		if(record==1){writeDebugStreamLine("D(%d, %d, %d, %d, %d, %d);",	bL,	bR,	l, cm, mg, c);}
		else{}
	}
}
