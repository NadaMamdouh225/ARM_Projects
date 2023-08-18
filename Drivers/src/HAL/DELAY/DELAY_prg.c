/*
 * DELAY_prg.c
 *
 *  Created on: Aug 1, 2023
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/STK/STK_int.h"

#include "DELAY_int.h"

void HDELAY_vBusyWait_ms(u32 A_u32Time_ms)
{
	MSTK_vSetDelay(A_u32Time_ms * 4000);       // 1ms = 4000 tick
}



