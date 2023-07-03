/*
 * RCC_prg.c
 *
 *  Created on: Jul 1, 2023
 *      Author: Nada Mamdouh
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "RCC_int.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"

void MRCC_vInit(void)
{
	/*1- CSS (ON/OFF) */
#if RCC_CLK_SEC_SYS == ON
	SET_BIT(RCC->CR,CSSON);
#elif RCC_CLK_SEC_SYS == OFF
	CLR_BIT(RCC->CR,CSSON);
#endif

	/*2- HSE_BYP */
#if RCC_HSE_BYPASS == ENABLE_OSC
	CLR_BIT(RCC->CR,HSEBYP);
#elif RCC_HSE_BYPASS == ENABLE_EXTRNAL_CLK
	SET_BIT(RCC->CR,HSEBYP);
#elif RCC_HSE_BYPASS == NONE

#endif

	/*3- Select clock switch (HSE | HSI | PLL)*/
#if RCC_SYS_CLK == RCC_HSI_ENABLE
	CLR_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);
#elif RCC_SYS_CLK == RCC_HSE_ENABLE
	SET_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);
#elif RCC_SYS_CLK == RCC_PLL_ENABLE
	CLR_BIT(RCC->CFGR,SW0);
	SET_BIT(RCC->CFGR,SW1);
#endif
	/*4- Bus prescalers */
	/*5- PLL configuration */
	/*6- Enable selected clock (HSE | HSI | PLL)*/
#if RCC_HSE_ENABLE == ENABLE
	SET_BIT(RCC->CR,HSEON);
#elif RCC_HSI_ENABLE == ENABLE
	SET_BIT(RCC->CR,HSION);
#elif RCC_PLL_ENABLE == ENABLE
	SET_BIT(RCC->CR,PLLON);
#endif


}
void MRCC_vEnableClk(u32 A_u32BusID,u32 A_u32PeripheralID)
{

		switch (A_u32PeripheralID)
		{
		case RCC_AHB1:

			break;
		}


}
void MRCC_vDisableClk(u32 A_u32BusID,u32 A_u32PeripheralID)
{

}

