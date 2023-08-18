/*
 * GPIO_cfg.c
 *
 *  Created on: Aug 5, 2023
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_TYPES.h"

#include "GPIO_int.h"
#include "GPIO_cfg.h"

MGPIO_Config_t PortA_Config[PORT_A_PINS] = {
		{.Port=GPIO_PORTA,.Pin=GPIO_PIN0,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTA,.Pin=GPIO_PIN1,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTA,.Pin=GPIO_PIN2,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTA,.Pin=GPIO_PIN3,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTA,.Pin=GPIO_PIN4,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTA,.Pin=GPIO_PIN5,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTA,.Pin=GPIO_PIN6,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTA,.Pin=GPIO_PIN7,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
};

MGPIO_Config_t PortB_Config[PORT_B_PINS] = {
		{.Port=GPIO_PORTB,.Pin=GPIO_PIN0,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTB,.Pin=GPIO_PIN1,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTB,.Pin=GPIO_PIN5,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTB,.Pin=GPIO_PIN6,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTB,.Pin=GPIO_PIN7,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTB,.Pin=GPIO_PIN8,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTB,.Pin=GPIO_PIN9,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTB,.Pin=GPIO_PIN10,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
};

MGPIO_Config_t PortC_Config[PORT_C_PINS] = {
		{.Port=GPIO_PORTC,.Pin=GPIO_PIN13,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTC,.Pin=GPIO_PIN14,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
		{.Port=GPIO_PORTC,.Pin=GPIO_PIN15,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED,.InputPull = GPIO_NO_PULL},
};
