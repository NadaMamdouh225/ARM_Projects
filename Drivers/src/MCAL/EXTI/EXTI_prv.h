/*
 * EXTI_prv.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

#define EXTI_BASE_ADDR            0x40013C00

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_RegMap_t;


#define EXTI              ((volatile EXTI_RegMap_t*)(EXTI_BASE_ADDR))




#endif /* MCAL_EXTI_EXTI_PRV_H_ */
