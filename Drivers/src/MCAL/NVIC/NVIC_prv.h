/*
 * NVIC_prv.h
 *
 *  Created on: Jul 17, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_NVIC_NVIC_PRV_H_
#define MCAL_NVIC_NVIC_PRV_H_

#define NVIC_BASE_ADDR                  0xE000E100
#define SCB_BASE_ADDR

/*---- NVIC ----*/
typedef struct
{
	 u32 ISER[32];
	 u32 ICER[32];
	 u32 ISPR[32];
	 u32 ICPR[32];
	 u32 IABR[32];
	 u32 RESERVED[32];
	 u8  IPR[128];                      // 128 cause we don't use the rest of interrupts

}NVIC_RegMap_t;

/*---- SCB ----*/
typedef struct
{
	u32 CPUID;
	u32 ICSR;
	u32 VTOR;
	u32 AIRCR;
	u32 SCR;
	u32 CCR;
	u32 SHPR1;
	u32 SHPR2;
	u32 SHPR3;
	u32 SHCSR;
	u32 CFSR;
	u32 HFSR;
	u32 MMAR;
	u32 BFAR;
	u32 AFSR;


}SCB_RegMap_t;

#define NVIC         ((volatile NVIC_RegMap_t*)(NVIC_BASE_ADDR))
#define SCB          ((volatile SCB_RegMap_t*)(SCB_BASE_ADDR))




#endif /* MCAL_NVIC_NVIC_PRV_H_ */
