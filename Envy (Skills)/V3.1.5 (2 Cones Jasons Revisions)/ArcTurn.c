void ArcTurn(float degree, float radius, char FBD, char LRD)
{clearTimer(T1);
	SensorValue[Rencoder]=0;
	SensorValue[Lencoder]=0;
	SensorValue[in1]=0;
	//90 degrees

	float speedL, speedR;
	float Larcdist, Rarcdist,LR,dir,Loffset, Roffset, Rmult, Lmult; //LeftRight, Forward Backward

	if (LRD=='L' ||LRD=='l'){LR=-1.0;}   			////LEFT -1
	else{LR=1.0;}//

	if (FBD=='F'||FBD=='f'){dir=1.0;}					////FORWARD 1
	else{dir=-1.0;}
	degree=degree*(PI/180.0);
	if(LR>0){Larcdist=degree*(radius+6.0); Rarcdist=degree*(radius-6.0); Lmult=(radius+6.0); Rmult=(radius-6.0); }///DEtermine if left side or right side is travelling shorter or longer dist
	else {Larcdist=degree*(radius-6.0); Rarcdist=degree*(radius+6.0);Lmult=(radius-6.0); Rmult=(radius+6.0);}
	Larcdist= (Larcdist*261.33)/(4.1*PI);///Change 261 (IME Turbo) for 360 for external Motor controllers
	Rarcdist= (Rarcdist*261.33)/(4.1*PI);///Change 261 (IME Turbo) for 360 for external Motor controllers
	//Lmult=(Larcdist/Rarcdist); Rmult=(Rarcdist/Larcdist);
	//if (Lmult>1){Lmult=Lmult/3; Rmult=Rmult*3;}
	//  else{Lmult=Lmult*3; Rmult=Rmult/3;}
	writeDebugStreamLine("%fL %fR",Lmult,Rmult);
	writeDebugStreamLine("%fL %fR",Larcdist,Rarcdist);
	while (time1[T1]<2000&&(abs(SensorValue[Lencoder])<Larcdist||abs(SensorValue[Rencoder])<Rarcdist))
	{
		//if (abs(SensorValue[Rencoder])<abs(SensorValue[Lencoder])){Loffset=dir*10; Roffset=0;}
		//else if (abs(SensorValue[Lencoder])<abs(SensorValue[Rencoder])){Loffset=0; Roffset=-dir*10;}
		//else{Loffset=0; Roffset=0;}

		//xL=(Larcdist-abs(SensorValue[Lencoder]));
		//xR=(Rarcdist-abs(SensorValue[Rencoder]));
		//speedL=(-35.0)*cos(16.0*abs(xL)/(abs(Larcdist)*3.14)+5.75)+30.0;//vel;
		//speedR=(-35.0)*cos(16.0*abs(xR)/(abs(Rarcdist)*3.14)+5.75)+30.0;//vel;
		speedL=5;
		speedR=5;
		speedL=dir*speedL*Lmult;
		speedR=dir*speedR*Rmult;

		if (LRD=='L' ||LRD=='l')
		{
			if(abs(SensorValue[Lencoder])<abs(SensorValue[Rencoder])*(Larcdist/Rarcdist))
			{Loffset=1; Roffset=0.75;}
			else if (abs(SensorValue[Lencoder])>abs(SensorValue[Rencoder])*(Larcdist/Rarcdist))
			{Loffset=0.75; Roffset=1;}
			else{Loffset=1; Roffset=1;}
		}   			////LEFT -1
		else
		{
			if(abs(SensorValue[Lencoder])>abs(SensorValue[Rencoder])*(Rarcdist/Larcdist))
			{Loffset=1; Roffset=0.75;}
			else if (abs(SensorValue[Lencoder])<abs(SensorValue[Rencoder])*(Rarcdist/Larcdist))
			{Loffset=0.75; Roffset=1;}
			else{Loffset=1; Roffset=1;}
		}//

		motor[rightDriveBack]=speedR*Roffset;
		motor[powerCD]=speedR*Roffset;
		motor[rightDriveFrontMID]=speedR*Roffset;
		motor[leftDriveBack]=speedL*Loffset;
		motor[powerAB]=speedL*Loffset;
		motor[leftDriveFrontMID]=speedL*Loffset;

	}
	motor[rightDriveBack]=0;
	motor[powerCD]=0;
	motor[rightDriveFrontMID]=0;
	motor[leftDriveBack]=0;
	motor[powerAB]=0;
	motor[leftDriveFrontMID]=0;
}
