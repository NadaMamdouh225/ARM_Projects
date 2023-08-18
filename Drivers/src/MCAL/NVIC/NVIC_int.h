/*
 * NVIC_int.h
 *
 *  Created on: Jul 17, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_

void MNVIC_vEnablePeripheral_INT(u8 A_u8PeripheralID);
void MNVIC_vDisablePeripheral_INT(u8 A_u8PeripheralID);

void MNVIC_vSetPending_INT(u8 A_u8PeripheralID);
void MNVIC_vClearPending_INT(u8 A_u8PeripheralID);
u8   MNVIC_u8GetActive_INT(u8 A_u8PeripheralID);

void MNVIC_vSetPriority(u8 A_u8PeripheralID);
u8   MNVIC_u8GetPriority(u8 A_u8PeripheralID);

#define WWDG                   0
#define EXTI16_PVD             1
#define EXTI21_TAMP_STAMP      2
#define EXTI22_RTC_WKUP        3
#define FLASH                  4
#define RCC                    5
#define EXTI0                  6
#define EXTI1                  7
#define EXTI2                  8
#define EXTI3                  9
#define EXTI4                  10




#endif /* MCAL_NVIC_NVIC_INT_H_ */
