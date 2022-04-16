int bL,	bR,	l, cp, cm, mg, c, as;

//#### DRIVE BASE ########################################################################
if(vexRT[Ch3] > 15 || vexRT[Ch4] > 15 || vexRT[Ch3] < -15 || vexRT[Ch4] < -15) //JOYSTICK DEADBAND
{
	bL = vexRT[Ch3]*pm + vexRT[Ch4]*pm;		//Base Left Side
	bR = vexRT[Ch3]*pm- vexRT[Ch4]*pm;		//Base Right Side
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
	l = vexRT[Ch2]*sm; //Lift Motors
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
	cm=127*pm;
}
else if (vexRT[Btn6D]==1&&vexRT[Btn6U]==0)
{
	cm=-127*pm;
}
else
{
	cm=10*pm;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//@@@@ MOBILE GOAL @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
if (vexRT[Btn8D]==1&&vexRT[Btn8R]==0)
{
	mg=127*pm; //Mobile Goal Up
}
else if (vexRT[Btn8R]==1&&vexRT[Btn8D]==0)
{
	mg=-127*pm; //Mobile Goal Down
}
else
{
	mg=15*pm;		//Value To Keep Mobile Goal Back
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//#### CLAW############################################################
if (vexRT[Btn5U]==1){c=1;} //Claw Close
else{c=0;}//Claw Open
//########################################################################
//$$$ AUTO STACK $$$$$$$$$$$$$$$$$$$$
if(vexRT[Btn8L]==1)
{as=1;}
else {as=0;}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

if (SensorValue[Climit]==1)
{SensorValue[enc]=0;}

//if (vexRT

if (as>0)
{D(	0,	0,	0, 0, -15, 0, as, pm,sm); 				//Base Left Side, Base Right Side, Lift Motors, Claw Preset, Claw Motor, Mobile Goal, Claw
	if(record==1){writeDebugStreamLine("D(%d, %d, %d, %d, %d, %d, %d, pm, sm);",	0,	0,	0,  0,0, 0, as);}
	else{}
}
else
{
	D(	bL,	bR,	l,cm, mg, c, as,pm,sm); 				//Base Left Side, Base Right Side, Lift Motors, Claw Preset, Claw Motor, Mobile Goal, Claw
	if(record==1){writeDebugStreamLine("D(%d, %d, %d, %d, %d, %d, %d, pm, sm);",	bL,	bR,	l, cm, mg, c, as);}
	else{}
}
