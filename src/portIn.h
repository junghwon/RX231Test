/*
 * portIn.h
 *
 *  Created on: 2022/01/20
 *      Author: kehnc
 */

#ifndef PORTIN_H_
#define PORTIN_H_

#include "r_cg_macrodriver.h"
#include "r_smc_entry.h"


#define USER_SWITCH (PORTB.PIDR.BIT.B1)
#define INPUT_PERIOD (10)
#define SWITCH_DEBOUNCE (3)

typedef enum {
	portLevel_lo,
	portLevel_hi,
} portLevel_t;

typedef enum {
	keyCode_null,
	keyCode_userSw,
} keyCode_t;


// --- public function
void portIn_CountInputPeriod (void);
keyCode_t portIn_GetKeyCode (void);
void portIn_KeyDetect (void);
void portIn_KeyInit (
		portLevel_t active,
		uint8_t deb);

#endif /* PORTIN_H_ */
