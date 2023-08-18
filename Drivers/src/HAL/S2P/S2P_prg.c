/*
 * S2P_prg.c
 *
 *  Created on: Aug 6, 2023
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/STK/STK_int.h"

#include "S2P_cfg.h"
#include "S2P_prv.h"
#include "S2P_int.h"

void HS2P_vInit(void)
{
	MGPIO_vInit(&S2P_Shift_Pins);
	MGPIO_vInit(&S2P_Latch_Pins);
	MGPIO_vInit(&S2P_Data_Pins);
	MSTK_vInit();
}
void HS2P_vSendData(u32 A_u32Data)
{
	/* put data on data pin */

	/* shift data on data pin
	 * 1- send High
	 * 2- delay
	 * 3-send LOW
	 */

	/* send a latch signal for the output
	 * 1- send High
	 * 2- delay
	 * 3-send LOW
	 */

}


