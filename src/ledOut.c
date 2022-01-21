/*
 * ledOut.c
 *
 *  Created on: 2022/01/21
 *      Author: kehnc
 */
#include "ledOut.h"


// --- static value
static ledOutType_t outType = ledOutType_off;
static _Bool ledFlashPeriodFlag = false;


// --- private function
static void off (void)
{
	LED_PORT = ledOut_off;
}

static void on (void)
{
	LED_PORT = ledOut_on;
}

static void flash (void)
{
	static ledFlashMode_t flashMode = ledFlashMode_off;

	switch (flashMode) {
	default:
	case ledFlashMode_off:
		LED_PORT = ledOut_off;
		if (ledFlashPeriodFlag) {
			ledFlashPeriodFlag = false;
			flashMode = ledFlashMode_on;
		}
		break;
	case ledFlashMode_on:
		LED_PORT = ledOut_on;
		if (ledFlashPeriodFlag) {
			ledFlashPeriodFlag = false;
			flashMode = ledFlashMode_off;
		}
		break;
	}
}


// --- public function
void ledOut_SetLedOutType (ledOutType_t type)
{
	outType = type;
}

void ledOut_CountLedFlashPeriod (void)
{
	static uint16_t periodCount = 0;

	if (periodCount < LED_FLASH_PERIOD) {
		periodCount++;
	} else {
		periodCount = 0;
		ledFlashPeriodFlag = true;
	}
}

void ledOut_Manager (void)
{
	switch (outType) {
	default:
	case ledOutType_off:
		off ();
		break;
	case ledOutType_on:
		on ();
		break;
	case ledOutType_flash:
		flash ();
		break;
	}
}

void ledOut_Init (void)
{
	outType = ledOutType_off;
	ledFlashPeriodFlag = false;
}
