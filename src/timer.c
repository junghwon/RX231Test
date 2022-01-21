/*
 * timer.c
 *
 *  Created on: 2022/01/20
 *      Author: kehnc
 */
#include "timer.h"

// --- static value
static _Bool timerFlag1msec = false;


// --- public function
void timer_Set1msecFlag (void)
{
	timerFlag1msec = true;
}

_Bool timer_Check1msecFlag (void)
{
	_Bool rsp = false;

	if (timerFlag1msec) {
		timerFlag1msec = false;
		rsp = true;
	}

	return (rsp);
}

void timer_Init (void)
{
	timerFlag1msec = false;
}
