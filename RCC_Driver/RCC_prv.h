/*
 * RCC_prv.h
 *
 *  Created on: Jul 1, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_RCC_RCC_PRV_H_
#define MCAL_RCC_RCC_PRV_H_

#define RCC_BASE_ADDR            0x40023800

typedef struct{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;

	u32 Reserved1;
	u32 Reserved2;

	u32 APB1RSTR;
	u32 APB2RSTR;

	u32 Reserved3;
	u32 Reserved4;

	u32 AHB1ENR;
	u32 AHB2ENR;

	u32 Reserved5;
	u32 Reserved6;

	u32 APB1ENR;
	u32 APB2ENR;

	u32 Reserved7;
	u32 Reserved8;

	u32 AHB1LPENR;
	u32 AHB2LPENR;

	u32 Reserved9;
	u32 Reserved10;

	u32 APB1LPENR;
	u32 APB2LPENR;

	u32 Reserved11;
	u32 Reserved12;

	u32 BDCR;
	u32 CSR;

	u32 Reserved13;
	u32 Reserved14;

	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 DCKCFGR;


}RCC_MemMap_t;

#define RCC    ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))

/* RCC_SYS_CLK --- OPTIONS --- */
#define RCC_HSI_ENABLE      0
#define RCC_HSE_ENABLE      1
#define RCC_PLL_ENABLE      2

/* RCC_HSE_BYPASS --- OPTIONS --- */
#define ENABLE_OSC          1
#define ENABLE_EXTRNAL_CLK  2
#define NONE                0

/* RCC_CLK_SEC_SYS --- OPTIONS --- */
#define ON    1
#define OFF   0

#define ENABLE    1
#define DISABLE   0


/*  -------------- REGISTERS --------------  */
/* CR */
#define HSION     0
#define HSEON     16
#define CSSON     19
#define HSEBYP    18
#define PLLON     24

/* CFGR */
#define SW0       0
#define SW1       1

/* AHB2ENR */
#define OTGFSEN   7


#endif /* MCAL_RCC_RCC_PRV_H_ */
