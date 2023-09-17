/*
 * ULTRASONIC_prg.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/TIMER/TIMER_int.h"
#include "../DELAY/DELAY_int.h"

#include "ULTRASONIC_int.h"
#include "ULTRASONIC_cfg.h"
#include "ULTRASONIC_prv.h"


void HULTRASONIC_vInit(void)
{
	/* set GPIO pin configuration */
	for(u8 L_u8index = 0;L_u8index<TRIG_PINS_NO;L_u8index++)
	{
		MGPIO_vInit(&TrigPins[L_u8index]);
	}
	for(u8 L_u8index = 0;L_u8index<ECHO_PINS_NO;L_u8index++)
	{
		MGPIO_vInit(&EchoPins[L_u8index]);
	}
	MTIMER_vCfg_TIM2_PulseIn();

}

f32 HULTRASONIC_vGetDistance(void)
{
	f32 L_f32Time = 0;
	f32 L_f32GetDistance;
	                   /* ------ Set TRIG to HIGH for 10us ------ */

	/* Set pin low for 5us */
	for(u8 L_u8index = 0;L_u8index<TRIG_PINS_NO;L_u8index++)
	{
		MGPIO_vSetPinVal(TrigPins[L_u8index].Port,TrigPins[L_u8index].Pin,GPIO_LOW);
	}
	HDELAY_vBusyWait_us(5);

	/* Set pin high for 10us */
	for(u8 L_u8index = 0;L_u8index<TRIG_PINS_NO;L_u8index++)
	{
		MGPIO_vSetPinVal(TrigPins[L_u8index].Port,TrigPins[L_u8index].Pin,GPIO_HIGH);
	}
	HDELAY_vBusyWait_us(10);
	/* Set pin low */
	for(u8 L_u8index = 0;L_u8index<TRIG_PINS_NO;L_u8index++)
	{
		MGPIO_vSetPinVal(TrigPins[L_u8index].Port,TrigPins[L_u8index].Pin,GPIO_LOW);
	}

	                /* ------ Capture Signal and Get Distance ------ */

	L_f32Time = MTIMER_f32TIM2_PulseIn();
	L_f32GetDistance = L_f32Time / INVERSE_SOUND_SPEED ;

	return L_f32GetDistance;

}
