/*
 * mode.h
 *
 *  Created on: 2022/01/20
 *      Author: kehnc
 */

#ifndef MODE_H_
#define MODE_H_

#include "r_cg_macrodriver.h"
#include "r_smc_entry.h"


typedef enum {
	controlMode_off,
	controlMode_on,
	mcontrolMode_flash,
} controlMode_t;


// --- public function
void mode_Init (void);
void mode_Manager (void);

#endif /* MODE_H_ */
