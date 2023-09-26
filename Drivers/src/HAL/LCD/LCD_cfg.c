/*
 * LCD_cfg.c
 *
 *  Created on: Sep 26, 2023
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_int.h"

#include "LCD_cfg.h"


/* Configuration table */
MGPIO_Config_t LCD_CTRL[CTRL_PINS] =
{
	{.Port = GPIO_PORTA,.Pin = LCD_RS_PIN,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_LOW_SPEED,.OutputType = GPIO_OT_PUSHPULL},
	{.Port = GPIO_PORTA,.Pin = LCD_RW_PIN,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_LOW_SPEED,.OutputType = GPIO_OT_PUSHPULL},
	{.Port = GPIO_PORTA,.Pin = LCD_EN_PIN,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_LOW_SPEED,.OutputType = GPIO_OT_PUSHPULL}
};

MGPIO_Config_t LCD_DATA[DATA_PINS] =
{
		{.Port = GPIO_PORTA,.Pin = GPIO_PIN0,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_LOW_SPEED,.OutputType = GPIO_OT_PUSHPULL},
		{.Port = GPIO_PORTA,.Pin = GPIO_PIN1,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_LOW_SPEED,.OutputType = GPIO_OT_PUSHPULL},
		{.Port = GPIO_PORTA,.Pin = GPIO_PIN2,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_LOW_SPEED,.OutputType = GPIO_OT_PUSHPULL},
		{.Port = GPIO_PORTA,.Pin = GPIO_PIN3,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_LOW_SPEED,.OutputType = GPIO_OT_PUSHPULL},
		{.Port = GPIO_PORTA,.Pin = GPIO_PIN4,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_LOW_SPEED,.OutputType = GPIO_OT_PUSHPULL},
		{.Port = GPIO_PORTA,.Pin = GPIO_PIN5,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_LOW_SPEED,.OutputType = GPIO_OT_PUSHPULL},
		{.Port = GPIO_PORTA,.Pin = GPIO_PIN6,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_LOW_SPEED,.OutputType = GPIO_OT_PUSHPULL},
		{.Port = GPIO_PORTA,.Pin = GPIO_PIN7,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_LOW_SPEED,.OutputType = GPIO_OT_PUSHPULL}
};
