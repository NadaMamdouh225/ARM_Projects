/*
 * RCC_int.h
 *
 *  Created on: Jul 1, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_

void MRCC_vInit(void);
void MRCC_vEnableClk(u32 A_u32BusID,u32 A_u32PeripheralID);
void MRCC_vDisableClk(u32 A_u32BusID,u32 A_u32PeripheralID);

/*  -------------- BUS ID --------------  */
#define RCC_AHB1      0
#define RCC_AHB2      1
#define RCC_APB1      2
#define RCC_APB2      3

/*  -------------- PERIPHERAL ID --------------  */
#define GPIO      0
#define DMA       1
#define USB       2


#endif /* MCAL_RCC_RCC_INT_H_ */
