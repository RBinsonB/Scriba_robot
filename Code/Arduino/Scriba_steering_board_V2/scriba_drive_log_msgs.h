	//Define all log strings in prog memory to save SRAM
	
namespace ScribaDriveLogMsgs {
	//-------------------------
	// emergency function logs
	//-------------------------
	const char PROGMEM emMsg1[22]= "EMERGENCY STOP ACTIVE";
	const char PROGMEM emMsg2[27]= "EMERGENCY STOP DEACTIVATED";
	const char PROGMEM emMsg3[25]= "Emergency button pressed";
	const char PROGMEM emMsg4[52]= "Steering end position microswitch missing/defective";
	const char PROGMEM emMsg5[42]= "Please check microswitch wiring and state";
	const char PROGMEM emMsg6[48]= "PUSH AND RELEASE EMERGENCY STOP BUTTON TO RESET";
	const char PROGMEM emMsg7[38]= "Unspecified reason for emergency stop";
	//------------------
	// Calibration logs
	//------------------
	const char PROGMEM clbMsg1[27]= "Steer calibration starting";
	const char PROGMEM clbMsg2[40]= "Rotating to left end position switch...";
	const char PROGMEM clbMsg3[27]= "Left end position detected";
	const char PROGMEM clbMsg4[41]= "Rotating to right end position switch...";
	const char PROGMEM clbMsg5[28]= "Right end position detected";
	const char PROGMEM clbMsg6[36]= "Number of steps in steering range: ";
	const char PROGMEM clbMsg7[33]= "Going now to middle position... ";
	const char PROGMEM clbMsg8[21]= "Calibration complete";
}