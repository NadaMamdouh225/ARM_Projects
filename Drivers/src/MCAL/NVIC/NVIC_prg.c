/*
 * NVIC_prg.c
 *
 *  Created on: Jul 17, 2023
 *      Author: Nada Mamdouh
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "NVIC_int.h"
#include "NVIC_prv.h"
#include "NVIC_cfg.h"


void MNVIC_vEnablePeripheral_INT(u8 A_u8PeripheralID)
{
	NVIC->ISER[A_u8PeripheralID/32] =  1 << (A_u8PeripheralID % 32);
}
void MNVIC_vDisablePeripheral_INT(u8 A_u8PeripheralID)
{
	NVIC->ICER[A_u8PeripheralID/32] =  1 << (A_u8PeripheralID % 32);
}

void MNVIC_vSetPending_INT(u8 A_u8PeripheralID)
{
	NVIC->ISPR[A_u8PeripheralID/32] = 1 << (A_u8PeripheralID % 32) ;
}
void MNVIC_vClearPending_INT(u8 A_u8PeripheralID)
{
	NVIC->ICPR[A_u8PeripheralID/32] = 1 << (A_u8PeripheralID % 32) ;
}
u8   MNVIC_u8GetActive_INT(u8 A_u8PeripheralID)
{
	u8 L_u8Get_INT;
	L_u8Get_INT = GET_BIT(NVIC->IABR[A_u8PeripheralID/32],(A_u8PeripheralID % 32));
	return L_u8Get_INT;
}

