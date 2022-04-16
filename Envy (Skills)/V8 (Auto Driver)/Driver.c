//if (vexRT[Btn6U]==1){SensorValue[kicker]=1;}
//else if(vexRT[Btn6D]==1){SensorValue[kicker]=0;}
//if(vexRT[Btn5U]==1){ddir=1; }
//else if (vexRT[Btn5D]==1){ddir=-1;}
//else{}
if (vexRT[Btn5U]==1)
{		stopTask(MidLeftAuto);
	stopTask(FarLeftAuto);
	stopTask(FarRightAuto);
	stopTask(MidRightAuto);
	AutoRun=0;
	Encoders=1;
}
else if(vexRT[Btn7U]==1)
{
	//stopTask(MidLeftAuto);
	//stopTask(FarLeftAuto);
	//stopTask(FarRightAuto);
	startTask(MidRightAuto);
	AutoRun=1;
	Encoders=1;
}
else if (vexRT[Btn7D]==1)
{	AutoRun=1;
	Encoders=1;
	//stopTask(FarLeftAuto);
	//stopTask(FarRightAuto);
	//stopTask(MidRightAuto);
	startTask(MidLeftAuto);
}
else if (vexRT[Btn7L]==1)
{	AutoRun=1;
	Encoders=1;
	//stopTask(FarRightAuto);
	//stopTask(MidRightAuto);
	//stopTask(MidLeftAuto);
	startTask(FarLeftAuto);
}
else if (vexRT[Btn7R]==1)
{	AutoRun=1;
	Encoders=1;
	//	stopTask(MidRightAuto);
	//	stopTask(MidLeftAuto);
	//stopTask(FarLeftAuto);
	startTask(FarRightAuto);
}
else{}




if(abs(vexRT[Ch3])>10  || abs(vexRT[Ch4])>10)
{
	Encoders=1;
	motor[rightDriveBack]=(ddir*vexRT[Ch3]-(vexRT[Ch4]*.53))*.8;
	motor[powerCD]=(ddir*vexRT[Ch3]-(vexRT[Ch4]*.53))*.8;
	motor[rightDriveFrontMID]=(ddir*vexRT[Ch3]-(vexRT[Ch4]*.53))*.8;
	motor[leftDriveBack]=(ddir*vexRT[Ch3]+(vexRT[Ch4]*.53))*.8;
	motor[powerAB]=(ddir*vexRT[Ch3]+(vexRT[Ch4]*.53))*.8;
	motor[leftDriveFrontMID]=(ddir*vexRT[Ch3]+(vexRT[Ch4]*.53))*.8;

}
else if ((abs(vexRT[Ch2])>10 && vexRT[Btn5U]==0) && AutoRun==0)
{
	if (Encoders==1)
	{
		SensorValue[Rencoder]=0;
		SensorValue[Lencoder]=0;
		Encoders=0;
	}
	else{}
	if(vexRT[Ch2]>0){dir=1;}
	else{dir=-1;}
	if (abs(SensorValue[Rencoder])<(abs(SensorValue[Lencoder]))){Loffset=-dir*10; Roffset=0;}
	else if (abs(SensorValue[Lencoder])<(abs(SensorValue[Rencoder]))){Loffset=0; Roffset=-dir*10;}
	else{Loffset=0; Roffset=0;}
	speed=vexRT[Ch2]*.85;
	motor[rightDriveBack]=speed+Roffset;
	motor[powerCD]=speed+Roffset;
	motor[rightDriveFrontMID]=speed+Roffset;
	motor[leftDriveBack]=speed+Loffset;
	motor[powerAB]=speed+Loffset;
	motor[leftDriveFrontMID]=speed+Loffset;

}
else if (AutoRun==0)
{
	SensorValue[Rencoder]=0;
	SensorValue[Lencoder]=0;
	motor[rightDriveBack]=0;
	motor[powerCD]=0;
	motor[rightDriveFrontMID]=0;
	motor[leftDriveBack]=0;
	motor[powerAB]=0;
	motor[leftDriveFrontMID]=0;

}
else{}



if(vexRT[Btn8U]==0&&vexRT[Btn8L]==1)
{
	if(SensorValue[MGlimitD]==0)
	{
		stopTask(MGUp);
		startTask(MGDown);
	}
}
else if(vexRT[Btn8U]==1&&vexRT[Btn8L]==0)
{

	stopTask(MGDown);
	startTask(MGUp);
}

if(vexRT[Btn8D]==1)
{SensorValue[piston]=0;}

if(vexRT[Btn8R]==1)
{
	if(SensorValue[MGlimitD]==1)
		startTask(PistonUp);
	else
		SensorValue[piston]=1;
}


////if(vexRT[Btn6U]==1)
////	startTask(throw);
//if(vexRT[Btn7L]==1)
//{SensorValue[Claw]=0;
//	motor[ConeGrab]=-90;
//	}

//else if(vexRT[Btn7R]==1)
//{SensorValue[Claw]=1;
//	motor[ConeGrab]=90;}
//else{motor[ConeGrab]=0;}
