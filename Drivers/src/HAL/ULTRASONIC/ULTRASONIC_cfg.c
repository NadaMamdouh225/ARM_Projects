/*
 * ULTRASONIC_cfg.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_int.h"

#include "ULTRASONIC_cfg.h"

/* Configuration table */

MGPIO_Config_t TrigPins[TRIG_PINS_NO]={
		{.Port=GPIO_PORTA,.Pin=GPIO_PIN0,.Mode=GPIO_MODE_OUTPUT,.OutputType=GPIO_OT_PUSHPULL,.OutputSpeed=GPIO_LOW_SPEED}
};

MGPIO_Config_t EchoPins[ECHO_PINS_NO]={
		{.Port=GPIO_PORTA,.Pin=GPIO_PIN1,.Mode=GPIO_MODE_INPUT,.InputPull = GPIO_PULL_UP}
};

