/*
 * GPIO_prg.c
 *
 *  Created on: Jul 5, 2023
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GPIO_int.h"
#include "GPIO_prv.h"
#include "GPIO_cfg.h"

void MGPIO_vSetPinMode(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8Mode)
{
	switch(A_u8PortID)
	{
	case GPIO_PORTA:
		GPIOA->MODER &= ~(0b11<<A_u8PinNo*2);
		GPIOA->MODER |=(A_u8Mode<<(A_u8PinNo*2));
		break;
	case GPIO_PORTB:
		GPIOB->MODER &= ~(0b11<<A_u8PinNo*2);
		GPIOB->MODER |=(A_u8Mode<<(A_u8PinNo*2));
		break;
	case GPIO_PORTC:
		GPIOC->MODER &= ~(0b11<<A_u8PinNo*2);
		GPIOC->MODER |=(A_u8Mode<<(A_u8PinNo*2));
		break;
	}
}
void MGPIO_vSetPinOutput_t(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8OutputType)
{
	if(A_u8OutputType == GPIO_OT_OPEN_DRAIN)
	{
		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->OTYPER,A_u8PinNo);
			break;
		}
	}else if(A_u8OutputType == GPIO_OT_PUSHPULL)
	{

		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->OTYPER,A_u8PinNo);
			break;
		}
	}
}
void MGPIO_vSetPinOutputSpeed(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8OutputSpeed)
{
	switch(A_u8PortID)
	{
	case GPIO_PORTA:
		GPIOA->OSPEEDR &= ~(0b11<<A_u8PinNo*2);
		GPIOA->OSPEEDR |=(A_u8OutputSpeed<<(A_u8PinNo*2));
		break;
	case GPIO_PORTB:
		GPIOB->OSPEEDR &= ~(0b11<<A_u8PinNo*2);
		GPIOB->OSPEEDR |=(A_u8OutputSpeed<<(A_u8PinNo*2));
		break;
	case GPIO_PORTC:
		GPIOC->OSPEEDR &= ~(0b11<<A_u8PinNo*2);
		GPIOC->OSPEEDR |=(A_u8OutputSpeed<<(A_u8PinNo*2));
		break;
	}
}
void MGPIO_vSetPinInputPull(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8InputPull)
{
	switch(A_u8PortID)
			{
			case GPIO_PORTA:
				GPIOA->PUPDR &= ~(0b11<<A_u8PinNo*2);
				GPIOA->PUPDR |=(A_u8InputPull<<(A_u8PinNo*2));
				break;
			case GPIO_PORTB:
				GPIOB->PUPDR &= ~(0b11<<A_u8PinNo*2);
				GPIOB->PUPDR |=(A_u8InputPull<<(A_u8PinNo*2));
				break;
			case GPIO_PORTC:
				GPIOC->PUPDR &= ~(0b11<<A_u8PinNo*2);
				GPIOC->PUPDR |=(A_u8InputPull<<(A_u8PinNo*2));
				break;
			}
}
u8   MGPIO_u8GetPinData(u8 A_u8PortID, u8 A_u8PinNo)
{
	u8 L_u8PinVal;
	switch(A_u8PortID)
	{
	case GPIO_PORTA:
		L_u8PinVal = GET_BIT(GPIOA->IDR,A_u8PinNo);
		break;
	case GPIO_PORTB:
		L_u8PinVal = GET_BIT(GPIOB->IDR,A_u8PinNo);
		break;
	case GPIO_PORTC:
		L_u8PinVal = GET_BIT(GPIOC->IDR,A_u8PinNo);
		break;
	}

	return L_u8PinVal;
}
void MGPIO_vSetPinVal(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8PinVal)
{
	if(A_u8PinVal == GPIO_HIGH)
	{
		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA->ODR,A_u8PinNo);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->ODR,A_u8PinNo);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->ODR,A_u8PinNo);
			break;
		}
	}else if(A_u8PinVal == GPIO_LOW)
	{
		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA->ODR,A_u8PinNo);
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->ODR,A_u8PinNo);
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->ODR,A_u8PinNo);
			break;
		}
	}

}
void MGPIO_vSetPinVal_Fast(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8PinVal)
{
	if(A_u8PinVal == GPIO_HIGH)
		{
			switch(A_u8PortID)
			{
			case GPIO_PORTA:
				GPIOA->BSRR = A_u8PinNo;
				break;
			case GPIO_PORTB:
				GPIOB->BSRR = A_u8PinNo;
				break;
			case GPIO_PORTC:
				GPIOC->BSRR = A_u8PinNo;
				break;
			}
		}
}
void MGPIO_vAltFunc(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8AltFunc)
{

}



