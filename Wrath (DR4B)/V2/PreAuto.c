//GYRO SET-UP////////////////
SensorType[in7] = sensorNone;
wait1Msec(1000);
SensorType[in7] = sensorGyro;
wait1Msec(2000);
/////////////////////////////
if(DEBUG)
{
	alliance = 3;
}else
{
	int count = 0;
	int step = 1;
	bLCDBacklight = true;
	while(step == 1 && vexRT[Ch1]>-30 && vexRT[Ch1]<30 && vexRT[Ch2]>-30 && vexRT[Ch2]<30 && vexRT[Ch3]>-30 && vexRT[Ch3]<30 && vexRT[Ch4]>-30 && vexRT[Ch4]<30)
	{
		///////////////////////
		clearLCDLine(0);
		clearLCDLine(1);
		///////////////////////
		if (alliance == 4)
		{
			if (nLCDButtons == 1)
			{
				if (count == 0)
				{
					//DO Nothing
				}
				else
				{
					count--;
				}
			}
			else if (nLCDButtons == 2)
			{
				alliance = count;
			}
			else if (nLCDButtons == 4)
			{
				if (count == 2)
				{
					//DO NOTHING
				}
				else
				{
					count++;
				}
			}

			/////////////////////////
			if (count == 0)
			{
				displayLCDCenteredString(0, "Alliance: BLUE");
				displayLCDCenteredString(1, "<D> <ENTER> <U>");
			}
			else if (count == 1)
			{
				displayLCDCenteredString(0, "Alliance: RED");
				displayLCDCenteredString(1, "<D> <ENTER> <U>");
			}
			else if (count == 2)
			{
				displayLCDCenteredString(0, "SELFCHECK MODE");
				displayLCDCenteredString(1, "<D> <ENTER> <U>");
			}
		}
		else
		{
			if (alliance == 0)
			{
				displayLCDCenteredString(0, "BLUE ALLIANCE");
				displayLCDCenteredString(1, "SELECTED!!!");
				step = 2;
			}
			if (alliance == 1)
			{
				displayLCDCenteredString(0, "RED ALLIANCE");
				displayLCDCenteredString(1, "SELECTED!!!");
				step = 2;
			}
			if (alliance == 2)
			{
				displayLCDCenteredString(0, "SELFCHECK MODE");
				displayLCDCenteredString(1, "SELECTED!!!");
				step = 3;
			}
			wait1Msec(1000);
			count = 0;
		}
		wait1Msec(250);
		////////////////////////////////////////////////////////////////
	}
	while (step == 2)
	{
		///////////////////////
		clearLCDLine(0);
		clearLCDLine(1);
		///////////////////////
		if (alliance == 2)
		{
			step = 3;
		}
		if (autonomousN == 5)
		{
			if (nLCDButtons == 1)
			{
				if (count == 0)
				{
					//DO Nothing
				}
				else
				{
					count--;
				}
			}
			else if (nLCDButtons == 2)
			{
				autonomousN = count;
			}
			else if (nLCDButtons == 4)
			{
				if (count == 4)
				{
					//DO NOTHING
				}
				else
				{
					count++;
				}
			}

			/////////////////////////
			if (count == 0)
			{
				displayLCDCenteredString(0, "Autonomous: Near");
				displayLCDCenteredString(1, "<D> <ENTER> <U>");
			}
			else if (count == 1)
			{
				displayLCDCenteredString(0, "Autonomous: Far");
				displayLCDCenteredString(1, "<D> <ENTER> <U>");
			}
			else if (count == 2)
			{
				displayLCDCenteredString(0, "Autonomous: F2r");
				displayLCDCenteredString(1, "<D> <ENTER> <U>");
			}
			else if (count == 3)
			{
				displayLCDCenteredString(0, "Autonomous: 4");
				displayLCDCenteredString(1, "<D> <ENTER> <U>");
			}
			else if (count == 4)
			{
				displayLCDCenteredString(0, "Autonomous: 5");
				displayLCDCenteredString(1, "<D> <ENTER> <U>");
			}
		}
		else
		{
			displayLCDCenteredString(0, "AUTO ");
			displayLCDNumber(0, 12, autonomousN+1, 1);
			displayLCDCenteredString(1, "SELECTED!!!");
			wait1Msec(1000);
			step = 3;
		}
		wait1Msec(250);

	}
}//END DEBUG ELSE
