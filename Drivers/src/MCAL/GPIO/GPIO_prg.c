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
void MGPIO_vSetPortMode(u8 A_u8PortID,u16 A_u16Mode,u8 A_u8PortPortion)
{
	if(A_u8PortPortion == GPIO_LOW_PORTION)
	{
		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			GPIOA->MODER &= ~(0xFFFF);
			GPIOA->MODER |= A_u16Mode;
			break;
		case GPIO_PORTB:
			GPIOB->MODER &= ~(0xFFFF);
			GPIOB->MODER |= A_u16Mode;
			break;
		case GPIO_PORTC:
			GPIOC->MODER &= ~(0xFFFF);
			GPIOC->MODER |= A_u16Mode;
			break;
		}
	}else if(A_u8PortPortion == GPIO_HIGH_PORTION)
	{
		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			GPIOA->MODER &= ~(0xFFFF<<0x10);
			GPIOA->MODER |= (A_u16Mode<<0x10);
			break;
		case GPIO_PORTB:
			GPIOB->MODER &= ~(0xFFFF<<0x10);
			GPIOB->MODER |= (A_u16Mode<<0x10);
			break;
		case GPIO_PORTC:
			GPIOC->MODER &= ~(0xFFFF<<0x10);
			GPIOC->MODER |= (A_u16Mode<<0x10);
			break;
		}
	}

}
void MGPIO_vSetPortOutput_t(u8 A_u8PortID,u16 A_u16OutputType)
{
	switch(A_u8PortID)
	{
	case GPIO_PORTA:
		GPIOA->OTYPER &= ~(0xFFFF);
		GPIOA->OTYPER |= A_u16OutputType;
		break;
	case GPIO_PORTB:
		GPIOB->OTYPER &= ~(0xFFFF);
		GPIOB->OTYPER |= A_u16OutputType;
		break;
	case GPIO_PORTC:
		GPIOC->OTYPER &= ~(0xFFFF);
		GPIOC->OTYPER |= A_u16OutputType;
		break;
	}

}
void MGPIO_vSetPortOutputSpeed(u8 A_u8PortID,u16 A_u16OutputSpeed,u8 A_u8PortPortion)
{
	if(A_u8PortPortion == GPIO_LOW_PORTION)
		{
			switch(A_u8PortID)
			{
			case GPIO_PORTA:
				GPIOA->OSPEEDR &= ~(0xFFFF);
				GPIOA->OSPEEDR |= A_u16OutputSpeed;
				break;
			case GPIO_PORTB:
				GPIOB->OSPEEDR &= ~(0xFFFF);
				GPIOB->OSPEEDR |= A_u16OutputSpeed;
				break;
			case GPIO_PORTC:
				GPIOC->OSPEEDR &= ~(0xFFFF);
				GPIOC->OSPEEDR |= A_u16OutputSpeed;
				break;
			}
		}else if(A_u8PortPortion == GPIO_HIGH_PORTION)
		{
			switch(A_u8PortID)
			{
			case GPIO_PORTA:
				GPIOA->OSPEEDR &= ~(0xFFFF<<0x10);
				GPIOA->OSPEEDR |= (A_u16OutputSpeed<<0x10);
				break;
			case GPIO_PORTB:
				GPIOB->OSPEEDR &= ~(0xFFFF<<0x10);
				GPIOB->OSPEEDR |= (A_u16OutputSpeed<<0x10);
				break;
			case GPIO_PORTC:
				GPIOC->OSPEEDR &= ~(0xFFFF<<0x10);
				GPIOC->OSPEEDR |= (A_u16OutputSpeed<<0x10);
				break;
			}
		}

}
void MGPIO_vSetPortVal(u8 A_u8PortID,u8 A_u8PortVal,u8 A_u8PortPortion)
{
	if(A_u8PortPortion == GPIO_LOW_PORTION)
	{
		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			GPIOA->ODR &= ~(0xFF);
			GPIOA->ODR |= A_u8PortVal;
			break;
		case GPIO_PORTB:
			GPIOB->ODR &= ~(0xFF);
			GPIOB->ODR |= A_u8PortVal;
			break;
		case GPIO_PORTC:
			GPIOC->ODR &= ~(0xFF);
			GPIOC->ODR |= A_u8PortVal;
			break;
		}
	}else if(A_u8PortPortion == GPIO_HIGH_PORTION)
	{
		switch(A_u8PortID)
		{
		case GPIO_PORTA:
			GPIOA->ODR &= ~(0xFF<<8);
			GPIOA->ODR |= (A_u8PortVal<<8);
			break;
		case GPIO_PORTB:
			GPIOB->ODR &= ~(0xFF<<8);
			GPIOB->ODR |= (A_u8PortVal<<8);
			break;
		case GPIO_PORTC:
			GPIOC->ODR &= ~(0xFF<<8);
			GPIOC->ODR |= (A_u8PortVal<<8);
			break;
		}
	}
}
void MGPIO_vTogglePin(u8 A_u8PortID, u8 A_u8PinNo)
{
	switch(A_u8PortID)
	{
	case GPIO_PORTA:
		TOG_BIT(GPIOA->ODR,A_u8PinNo);
		break;
	case GPIO_PORTB:
		TOG_BIT(GPIOB->ODR,A_u8PinNo);
		break;
	case GPIO_PORTC:
		TOG_BIT(GPIOC->ODR,A_u8PinNo);
		break;
	}

}
void MGPIO_vPortA_Confg(void)
{
	for(u8 index= 0;index< PORT_A_PINS ; index ++)
	{
		MGPIO_vInit(&PortA_Config[index]);
	}
}
void MGPIO_vAltFunc(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8AltFunc)
{

}

void MGPIO_vInit(MGPIO_Config_t* A_xPinConfig)
{
	MGPIO_vSetPinMode(A_xPinConfig->Port,A_xPinConfig->Pin,A_xPinConfig->Mode);
	MGPIO_vSetPinOutput_t(A_xPinConfig->Port,A_xPinConfig->Pin,A_xPinConfig->OutputType);
	MGPIO_vSetPinOutputSpeed(A_xPinConfig->Port,A_xPinConfig->Pin,A_xPinConfig->OutputSpeed);
	MGPIO_vSetPinInputPull(A_xPinConfig->Port,A_xPinConfig->Pin, A_xPinConfig->InputPull);

}


