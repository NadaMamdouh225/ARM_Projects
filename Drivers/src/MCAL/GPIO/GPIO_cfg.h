/*
 * GPIO_cfg.h
 *
 *  Created on: Jul 5, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_GPIO_GPIO_CFG_H_
#define MCAL_GPIO_GPIO_CFG_H_


#define PORT_A_PINS             8
#define PORT_B_PINS             8
#define PORT_C_PINS             3

extern MGPIO_Config_t PortA_Config[PORT_A_PINS];
extern MGPIO_Config_t PortB_Config[PORT_B_PINS];
extern MGPIO_Config_t PortC_Config[PORT_C_PINS];


#endif /* MCAL_GPIO_GPIO_CFG_H_ */
