/*
 * SYSCFG_prg.c
 *
 *  Created on: Jul 28, 2023
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SYSCFG_int.h"
#include "SYSCFG_cfg.h"
#include "SYSCFG_prv.h"

void MSYSCFG_vSetEXTIPort(u8 A_u8LineNo, u8 A_u8PortNo)
{
	u8 L_u8Index = A_u8LineNo / 4;
	u8 L_u8ShiftAmount = (A_u8LineNo % 4)*4;
	SYSCFG->EXTICR[L_u8Index] &= ~((0b1111) << (L_u8ShiftAmount));
	SYSCFG->EXTICR[L_u8Index] |= (A_u8PortNo) << (L_u8ShiftAmount);
}



