while ( alliance == 0 ) // BEGING BLUE ALLIANCE CODE
{
	while ( autonomousN == 0 ) // BEGIN AUTONOMOUS 1 CODE
	{
		//BlueAuto1 ( ) ;
		AllianceColor=1;	//1 for Blue
		NearOrFar=0;
		FullAuto();
	}
	while ( autonomousN == 1 ) // BEGIN AUTONOMOUS 2 CODE
	{
		//BlueAuto2 ( ) ;
		AllianceColor=1;	//1 for Blue
		NearOrFar=1;
		FullAuto();
	}
	while ( autonomousN == 2 ) // BEGIN AUTONOMOUS 3 CODE
	{
		//BlueAuto3 ( ) ;
		AllianceColor=1;	//1 for Blue
		NearOrFar=2;
		FullAuto();
	}
	while ( autonomousN == 3 ) // BEGIN AUTONOMOUS 4 CODE
	{
		//BlueAuto4 ( ) ;
										AllianceColor=1;	//1 for Blue
				NearOrFar=3;
		FullAuto();
	}
	while ( autonomousN == 4 ) // BEGIN AUTONOMOUS 5 CODE
	{
		//BlueAuto5 ( );
	}
	// END BLUE ALLIANCE CODE
}
while ( alliance == 1 ) //  BEGIN RED ALLIANCE CODE
{
	while ( autonomousN == 0 ) // BEGIN AUTONOMOUS 1 CODE
	{
		//	RedAuto1 ( ) ;
		AllianceColor=-1;//-1 for Red
		NearOrFar=0;//Near
		FullAuto();
	}
	while ( autonomousN == 1 ) // BEGIN AUTONOMOUS 2 CODE
	{
		//RedAuto2 ( ) ;
		AllianceColor=-1;//-1 for Red
		NearOrFar=1;//Far
		FullAuto();
	}
	while ( autonomousN == 2 ) // BEGIN AUTONOMOUS 3 CODE
	{
		//RedAuto3 ( ) ;
		AllianceColor=-1;	//1 for Blue
		NearOrFar=2;
		FullAuto();
	}
	while ( autonomousN == 3 ) // BEGIN AUTONOMOUS 4 CODE
	{
		//RedAuto4 ( ) ;
	}
	while ( autonomousN == 4 ) // BEGIN AUTONOMOUS 5 CODE
	{
		//RedAuto5 ( ) ;
	}
	// END RED ALLIANCE CODE
}
while ( alliance == 2 ) // BEGIN SELF CHECK CODE
{
	//	SelfCheckCode ( ) ;
	// END SELF CHECK CODE
}
while ( alliance == 3 ) // BEGIN SELF CHECK CODE
{
	//DebugCode ( ) ;
	// END DebugCode
}
