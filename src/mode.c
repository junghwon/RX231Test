/*
 * mode.c
 *
 *  Created on: 2022/01/20
 *      Author: kehnc
 */
#include "mode.h"
#include "portIn.h"
#include "ledOut.h"

// --- static value
static controlMode_t mode = controlMode_off;


// --- public function
void mode_Init (void)
{
	mode = controlMode_off;
}

void mode_Manager (void)
{
	switch (mode) {
	default:
	case controlMode_off:
		ledOut_SetLedOutType (ledOutType_off);
		if (keyCode_userSw == portIn_GetKeyCode ()) {
			mode = controlMode_on;
		}
		break;
	case controlMode_on:
		ledOut_SetLedOutType (ledOutType_on);
		if (keyCode_userSw == portIn_GetKeyCode ()) {
			mode = mcontrolMode_flash;
		}
		break;
	case mcontrolMode_flash:
		ledOut_SetLedOutType (ledOutType_flash);
		if (keyCode_userSw == portIn_GetKeyCode ()) {
			mode = controlMode_off;
		}
		break;
	}
}

