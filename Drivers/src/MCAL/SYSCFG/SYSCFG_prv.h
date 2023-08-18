/*
 * SYSCFG_prv.h
 *
 *  Created on: Jul 28, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_SYSCFG_SYSCFG_PRV_H_
#define MCAL_SYSCFG_SYSCFG_PRV_H_


#define SYSCFG_BASE_ADDR           0x40013800

typedef struct{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 CMPCR;
}SYSCFG_RegMap_t;


#define SYSCFG                  ((volatile SYSCFG_RegMap_t*)(SYSCFG_BASE_ADDR))

#endif /* MCAL_SYSCFG_SYSCFG_PRV_H_ */
