/***********************************************************************
*
*  FILE        : RX231_test.c
*  DATE        : 2022-01-20
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "r_smc_entry.h"
#include "timer.h"
#include "portIn.h"
#include "mode.h"
#include "ledOut.h"

void main(void);

static void init (void)
{
	R_Config_CMT0_Start ();
	timer_Init ();
	portIn_KeyInit (portLevel_lo, SWITCH_DEBOUNCE);
	mode_Init ();
	ledOut_Init ();
}

void main(void)
{
	init ();

	while (1) {
		/*--- タイマー処理 ---*/
		// 1msec
		if (timer_Check1msecFlag()) {
			portIn_CountInputPeriod ();
			ledOut_CountLedFlashPeriod ();
		}

		/*--- キー入力処理 ---*/
		portIn_KeyDetect ();

		/*--- モード処理 ---*/
		mode_Manager ();

		/*--- 出力処理 ---*/
		ledOut_Manager ();
	}
}
