/*
 * TIMER_prv.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Nada Mamdouh
 */
#ifndef TIMER_TIMER_PRV_H_
#define TIMER_TIMER_PRV_H_


#define TIM2_BASE_ADDR          0x40000000
#define TIM3_BASE_ADDR          0x40000400
#define TIM4_BASE_ADDR          0x40000800
#define TIM5_BASE_ADDR          0x40000C00

typedef struct{
	u32 CR1;
	u32 CR2;
	u32 SMCR;
	u32 DIER;
	u32 SR;
	u32 EGR;
	u32 CCMR1;
	u32 CCMR2;
	u32 CCER;
	u32 CNT;
	u32 PSC;
	u32 ARR;
	u32 RESERVED1;
	u32 CCR1;
	u32 CCR2;
	u32 CCR3;
	u32 CCR4;
	u32 RESERVED2;
	u32 DCR;
	u32 DMAR;
	u32 OR;             // TIM2_OR and TIM5_OR

}TIM2_5_RegMap_t;


#define TIM2     ((volatile TIM2_5_RegMap_t*)(TIM2_BASE_ADDR))
#define TIM3     ((volatile TIM2_5_RegMap_t*)(TIM3_BASE_ADDR))
#define TIM4     ((volatile TIM2_5_RegMap_t*)(TIM4_BASE_ADDR))
#define TIM5     ((volatile TIM2_5_RegMap_t*)(TIM5_BASE_ADDR))

#define  CLEAR_COUNTER         0x00000000

/*  -------------- REGISTERS --------------  */
/* TIMx_CCMR1  input capture mode */
#define CC1S0      0
#define CC1S1      1
#define IC1PSC0    2
#define IC1PSC1    3
#define IC1F0      4
#define IC1F1      5
#define IC1F2      6
#define IC1F3      7

#define CC2S0      8
#define CC2S1      9
#define IC2PSC0    10
#define IC2PSC1    11
#define IC2F0      12
#define IC2F1      13
#define IC2F2      14
#define IC2F3      15

/* TIMx_CCER */
#define CC1E       0
#define CC1P       1
#define CC1NP      3
#define CC2E       4
#define CC2P       5
#define CC2NP      7

/* TIMx_CR1 */
#define CEN        0

/* TIMx_CR2 */
#define TI1S       7

/* TIMx_SR */
#define UIF        0
#define CC1IF      1
#define CC2IF      2
#define CC3IF      3
#define CC4IF      4

/* TIMx_SMCR */
#define SMS0       0
#define SMS1       1
#define SMS2       2
#define SMCR_RES   3
#define TS0        4
#define TS1        5
#define TS2        6





#endif /* TIMER_TIMER_PRV_H_ */
