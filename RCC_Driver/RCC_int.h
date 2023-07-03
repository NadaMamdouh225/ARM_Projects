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
// AHB1 bus
#define RCC_GPIOA_EN      0
#define RCC_GPIOB_EN      1
#define RCC_GPIOC_EN      2
#define RCC_GPIOD_EN      3
#define RCC_GPIOE_EN      4
#define RCC_GPIOH_EN      7
#define RCC_CRC_EN        12
#define RCC_DMA1_EN       21
#define RCC_DMA2_EN       22
// AHB2 bus
#define RCC_USB_EN        7
// APB1 bus
#define RCC_TIM2_EN       0
#define RCC_TIM3_EN       1
#define RCC_TIM4_EN       2
#define RCC_TIM5_EN       3
#define RCC_WWDG_EN       11
#define RCC_SPI2_EN       14
#define RCC_SPI3_EN       15
#define RCC_USART2_EN     17
#define RCC_I2C1_EN       21
#define RCC_I2C2_EN       22
#define RCC_I2C3_EN       23
#define RCC_PWR_EN        28
// APB2 bus
#define RCC_TIM1_EN       0
#define RCC_USART1_EN     4
#define RCC_USART6_EN     5
#define RCC_ADC1_EN       8
#define RCC_SDIO_EN       11
#define RCC_SPI1_EN       12
#define RCC_SPI4_EN       13
#define RCC_SYSCFG_EN     14
#define RCC_TIM9_EN       16
#define RCC_TIM10_EN      17
#define RCC_TIM11_EN      18












#endif /* MCAL_RCC_RCC_INT_H_ */
