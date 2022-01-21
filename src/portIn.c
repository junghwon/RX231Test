/*
 * portIn.c
 *
 *  Created on: 2022/01/20
 *      Author: kehnc
 */
#include "portIn.h"


// --- static value
static _Bool inputPeriodFlag = false;
static portLevel_t activeLevel = portLevel_lo;
static portLevel_t debounceLevel = portLevel_hi;
static portLevel_t prevLevel = portLevel_hi;
static uint8_t debounce = 0;
static keyCode_t keyCode = keyCode_null;


// --- public function
void portIn_CountInputPeriod (void)
{
	static uint8_t inputPeriodCount = 0;

	if (inputPeriodCount < INPUT_PERIOD) {
		inputPeriodCount++;
	} else {
		inputPeriodCount = 0;
		inputPeriodFlag = true;
	}
}

keyCode_t portIn_GetKeyCode (void)
{
	return (keyCode);
}

void portIn_KeyDetect (void)
{
	portLevel_t portLevel = USER_SWITCH;
	static uint8_t debounceCount = 0;

	if (inputPeriodFlag) {
		inputPeriodFlag = false;
		if (debounceLevel == portLevel) {
			if (debounceCount < debounce) {
				debounceCount++;
			} else {
				debounceCount = 0;
				if (prevLevel != portLevel) {
					prevLevel = portLevel;
					if (portLevel == activeLevel) {
						keyCode = keyCode_userSw;
					}
				}
			}
		} else {
			debounceLevel = portLevel;
			debounceCount = 0;
			keyCode = keyCode_null;
		}
	}
}

void portIn_KeyInit (
		portLevel_t active,
		uint8_t deb)
{
	activeLevel = active;
	debounceLevel ^= active;
	prevLevel ^= active;
	debounce = deb;
	keyCode = keyCode_null;
}
