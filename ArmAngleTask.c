#define MaxMotorPow 127
#define MinMotorPow -20

bool AngleControlActive = false;			//Control ArmAngleTask//
int AngleSet = 0;											//Angle of Arm in degrees//

//PP Algorithm (Proportion Proportion)
task ArmAngleTask()
{
int EncoderValue = 0;

//PP Algorithm Values
float ConstProportion = 5;			//Degrees To Encoder Ticks
float FirstProp = 127/(ConstProportion*AngleSet);
float SecProp = 4;
int ArmMotorPower;
int Error = 0;

	while(1)
	{
		if(AngleControlActive)
		{
			EncoderValue = abs(SensorValue[ArmEnc]);
			Error = (AngleSet*ConstProportion) - EncoderValue;
			FirstProp = FirstProp*SecProp;
			//BUILD POWER VALUE///////////////////////////////////
			ArmMotorPower = Error*FirstProp;
			//////////////////////////////////////////////////////
			//Power Limiter///////////////////////////////////////
			if(ArmMotorPower>MaxMotorPow)	ArmMotorPower=MaxMotorPow;
			if(ArmMotorPower<MinMotorPow) ArmMotorPower=MinMotorPow;
			//////////////////////////////////////////////////////
			//SET POWER OF ARM MOTORS/////////////////////////////
			MoveArm(ArmMotorPower);
			//////////////////////////////////////////////////////
		}
		wait1Msec(20);
	}


}
