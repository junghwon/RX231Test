/*
 * timer.h
 *
 *  Created on: 2022/01/20
 *      Author: kehnc
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "r_cg_macrodriver.h"
#include "r_smc_entry.h"


// --- public function
void timer_Set1msecFlag (void);
_Bool timer_Check1msecFlag (void);
void timer_Init (void);

#endif /* TIMER_H_ */
