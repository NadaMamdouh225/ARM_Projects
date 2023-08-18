/*
 * EXTI_prg.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Nada Mamdouh
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_int.h"
#include "EXTI_cfg.h"
#include "EXTI_prv.h"

static void (*EXTI_LINE_CallBack[16])(void);

void MEXTI_vInit(void)
{
	// Clear all flags
	EXTI->PR = 0xFFFFFFFF;
}
void MEXTI_vEnableINT(u8 A_u8LineNo,u8 A_u8Trigger_t)
{
	if(A_u8LineNo<16)
	{
		SET_BIT(EXTI->IMR,A_u8LineNo);
		switch(A_u8Trigger_t)
		{
		case EXTI_RISING_EDGE:
			SET_BIT(EXTI->RTSR,A_u8LineNo);
			CLR_BIT(EXTI->FTSR,A_u8LineNo);
			break;
		case EXTI_FALLING_EDGE:
			SET_BIT(EXTI->FTSR,A_u8LineNo);
			CLR_BIT(EXTI->RTSR,A_u8LineNo);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(EXTI->RTSR,A_u8LineNo);
			SET_BIT(EXTI->FTSR,A_u8LineNo);
			break;
		}
	}
}

void MEXTI_vDisableINT(u8 A_u8LineNo)
{
	if(A_u8LineNo<16)
		{
			CLR_BIT(EXTI->IMR,A_u8LineNo);
		}
}

void MEXTI_vSoftwareTrigger(u8 A_u8LineNo)
{
	if(A_u8LineNo<16)
	{
		SET_BIT(EXTI->SWIER,A_u8LineNo);
	}
}

void MEXTI_vSetTrigger(u8 A_u8LineNo, u8 A_u8Trigger_t)
{
	if(A_u8LineNo<16)
	{
		switch(A_u8Trigger_t)
		{
		case EXTI_RISING_EDGE:
			SET_BIT(EXTI->RTSR,A_u8LineNo);
			CLR_BIT(EXTI->FTSR,A_u8LineNo);
			break;
		case EXTI_FALLING_EDGE:
			SET_BIT(EXTI->FTSR,A_u8LineNo);
			CLR_BIT(EXTI->RTSR,A_u8LineNo);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(EXTI->RTSR,A_u8LineNo);
			SET_BIT(EXTI->FTSR,A_u8LineNo);
			break;
		default:
			/* Out of range */
			break;
		}
	}
}

void MEXTI_vSetCallback(u8 A_u8LineNo, void (*A_xFptr)(void))
{
	if(A_u8LineNo < 16)
	{
	EXTI_LINE_CallBack[A_u8LineNo] = A_xFptr;
	}
}

void EXTI0_IRQHandler(void)
{
	if(EXTI_LINE_CallBack[EXTI_LINE0]!= NULL)          // check whether an address exists or not
	{
		/* Call the callback function*/
		EXTI_LINE_CallBack[EXTI_LINE0]();

		/* Clear pending flag */
		CLR_BIT(EXTI->PR,EXTI_LINE0);
	}
}


