/*
 * ledOut.h
 *
 *  Created on: 2022/01/21
 *      Author: kehnc
 */

#ifndef LEDOUT_H_
#define LEDOUT_H_

#include "r_cg_macrodriver.h"
#include "r_smc_entry.h"


#define LED_PORT (PORTD.PODR.BIT.B6)
#define LED_FLASH_PERIOD (1000)

typedef enum {
	ledOutType_off,
	ledOutType_on,
	ledOutType_flash,
} ledOutType_t;

typedef enum {
	ledFlashMode_off,
	ledFlashMode_on,
} ledFlashMode_t;

typedef enum {
	ledOut_off,
	ledOut_on,
} ledOut_t;


// --- public function
void ledOut_SetLedOutType (ledOutType_t type);
void ledOut_CountLedFlashPeriod (void);
void ledOut_Manager (void);
void ledOut_Init (void);

#endif /* LEDOUT_H_ */
