/*
 * S2P_cfg.c
 *
 *  Created on: Aug 6, 2023
 *      Author: Nada Mamdouh
 */
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_int.h"

MGPIO_Config_t S2P_Shift_Pins = {
		.Port        =  GPIO_PORTA,
		.Pin         =  GPIO_PIN0,
		.Mode        =  GPIO_MODE_OUTPUT,
		.OutputType  =  GPIO_OT_PUSHPULL,
		.OutputSpeed =  GPIO_LOW_SPEED
};
MGPIO_Config_t S2P_Latch_Pins = {
		.Port        =  GPIO_PORTA,
		.Pin         =  GPIO_PIN1,
		.Mode        =  GPIO_MODE_OUTPUT,
		.OutputType  =  GPIO_OT_PUSHPULL,
		.OutputSpeed =  GPIO_LOW_SPEED
};
MGPIO_Config_t S2P_Data_Pins = {
		.Port        =  GPIO_PORTA,
		.Pin         =  GPIO_PIN2,
		.Mode        =  GPIO_MODE_OUTPUT,
		.OutputType  =  GPIO_OT_PUSHPULL,
		.OutputSpeed =  GPIO_LOW_SPEED
};



