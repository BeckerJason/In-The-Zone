float PMult/*, SMult,Pin*/; //primary multiplier, secondary multiplier
float MainBattery=nImmediateBatteryLevel; //Main Battery input
float Batt=MainBattery/1000; //Division by 1000 to get true voltage value of battery
PMult=PCheck(Batt); //Create Multiplier Based On Battery Voltage

int bL,	bR,	l, cp, cm, mg, c;

//#### DRIVE BASE ########################################################################
if(vexRT[Ch3] > 10 || vexRT[Ch4] > 10 || vexRT[Ch3] < -10 || vexRT[Ch4] < -10) //JOYSTICK DEADBAND
{
	bL = vexRT[Ch3]*PMult + vexRT[Ch4]*PMult;		//Base Left Side
	bR = vexRT[Ch3]*PMult - vexRT[Ch4]*PMult;		//Base Right Side
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
	l = vexRT[Ch2]*PMult; //Lift Motors
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
	cm=127*PMult;
}
else if (vexRT[Btn6D]==1&&vexRT[Btn6U]==0)
{
	cm=-127*PMult;
}
else
{
	cm=10;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//@@@@ MOBILE GOAL @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
if (vexRT[Btn8D]==1&&vexRT[Btn8U]==0)
{
	mg=100*PMult; //Mobile Goal Up
}
else if (vexRT[Btn8U]==1&&vexRT[Btn8D]==0)
{
	mg=-127*PMult; //Mobile Goal Down
}
else
{
	mg=15*PMult;		//Value To Keep Mobile Goal Back
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//#### CLAW############################################################
if (vexRT[Btn5U]==1){c=1;} //Claw Close
else{c=0;}//Claw Open
//########################################################################
Do(	bL,	bR,	l, cp, cm, mg, c); 				//Base Left Side, Base Right Side, Lift Motors, Claw Preset, Claw Motor, Mobile Goal, Claw
