float PCheck(float PVoltage)
{//PVoltage=mainBattery;//(1.2*nImmediateBatteryLevel/1000.0);
//writeDebugStreamLine("%1.2f",PVoltage);
float PMult=1;//((998.22/(PVoltage))/127);						//Multiplier for motors on Primary Battery
return PMult;
}

float SCheck(float SVoltage)
{//PVoltage=mainBattery;//(1.2*nImmediateBatteryLevel/1000.0);
writeDebugStreamLine("%1.2f",SVoltage);
float SMult=1;//((998.22/(SVoltage))/127);						//Multiplier for motors on Secondary Battery
return SMult;
}
