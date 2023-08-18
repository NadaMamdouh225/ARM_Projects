/*
 * STK_prg.c
 *
 *  Created on: Jul 27, 2023
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "STK_int.h"
#include "STK_cfg.h"
#include "STK_prv.h"


static void (*Global_Fptr)(void) = {NULL};
static u8 G_u8SingleFlag;

void MSTK_vInit(void)
{
	/* Stop Systick */
	CLR_BIT(STK->CTRL, CTRL_ENABLE);

	/* Interrupt enable or disable */
#if STK_INTERRUPT_EN == INT_ENABLE
	SET_BIT(STK->CTRL, TICKINT);
#elif STK_INTERRUPT_EN == INT_DISABLE
	CLR_BIT(STK->CTRL, TICKINT);
#endif

	/* Clock source selection */
#if STK_CLK_SOURCE == STK_AHB
	SET_BIT(STK->CTRL,CLKSOURCE);
#elif STK_CLK_SOURCE == STK_AHB_DIV_8
	CLR_BIT(STK->CTRL,CLKSOURCE);
#endif
}

void MSTK_vStartTimer(u32 A_u32LoadValue)
{
	SET_BIT(STK->CTRL, CTRL_ENABLE);
}
void MSTK_vStopTimer(void)
{
	CLR_BIT(STK->CTRL, CTRL_ENABLE);
}

/*description: set timer for a number of ticks using busy wait
 *
 * */
void MSTK_vSetDelay(u32 A_u32Ticks)
{
	/* Reset timer value */
	STK->VAL = 0;

	if((A_u32Ticks >= 0x00000001 )&& (A_u32Ticks < 0x00FFFFFF) )
	{
		/* Load timer with value */
		STK->LOAD = A_u32Ticks;

		/* Start timer  */
		MSTK_vStartTimer(A_u32Ticks);

		/* Wait for the timer flag */
		while(GET_BIT(STK->CTRL,COUNTFLAG) != 1){}

		/* Stop timer */
		MSTK_vStopTimer();

	}
}
/*description: set timer for a number of ticks using interrupt for one time
 *
 * */
void MSTK_vSetInterval_singls(u32 A_u32Ticks, void (*CallbackFunction)(void))
{
	G_u8SingleFlag = 1;
	/* Set callback function */
	Global_Fptr = CallbackFunction;

	/* Reset timer value */
		STK->VAL = 0;

		if((A_u32Ticks >= 0x00000001 )&& (A_u32Ticks < 0x00FFFFFF) )
		{
			/* Load timer with value */
			STK->LOAD = A_u32Ticks;

			/* Start timer  */
			MSTK_vStartTimer(A_u32Ticks);

		}

}
/*description: set timer for a number of ticks using interrupt for number of times until timer is stopped
 *
 * */
void MSTK_vSetInterval_Periodic(u32 A_u32Ticks, void (*CallbackFunction)(void))
{
	G_u8SingleFlag = 0;
	/* Set callback function */
		Global_Fptr = CallbackFunction;

	/* Reset timer value */
			STK->VAL = 0;

			if((A_u32Ticks >= 0x00000001 )&& (A_u32Ticks < 0x00FFFFFF) )
			{
				/* Load timer with value */
				STK->LOAD = A_u32Ticks;

				/* Start timer  */
				MSTK_vStartTimer(A_u32Ticks);

			}
}
u32 MSTK_u32GetElapsedTime(void)
{
	return (STK->LOAD) - (STK->VAL);
}
u32 MSTK_u32GetRemainingTime(void)
{
	return (STK->VAL);
}

void SysTick_Handler (void)
{
	if(Global_Fptr != NULL)
	{
		Global_Fptr();
	}
	if(G_u8SingleFlag)
	{
		G_u8SingleFlag = 0;
		/* Stop timer */
		MSTK_vStopTimer();
	}
}
