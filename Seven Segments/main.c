
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"

#define ARM_DELAY(t)      do{unsigned long int i=(t*1000);while(i--){asm("nop");}}while(0)

int main(void)
{
	MRCC_vInit();
	MRCC_vEnableClk(RCC_AHB1,RCC_GPIOA_EN);
	MGPIO_vSetPortMode(GPIO_PORTA,GPIO_PORT_MODE_OUTPUT,GPIO_LOW_PORTION);
	MGPIO_vSetPortOutput_t(GPIO_PORTA,GPIO_PORT_OT_PUSHPULL);
	MGPIO_vSetPortOutputSpeed(GPIO_PORTA,GPIO_PORT_LOW_SPEED,GPIO_LOW_PORTION);

	u8 SevenSegArr[10]=
	{
			/* Common Cathode */
			0b00111111,            /* value 0*/
			0b00000110,            /* value 1*/
			0b01011011,            /* value 2*/
			0b01001111,            /* value 3*/
			0b01100110,            /* value 4*/
			0b01101101,            /* value 5*/
			0b01111101,            /* value 6*/
			0b00000111,            /* value 7*/
			0b01111111,            /* value 8*/
			0b01101111             /* value 9*/

	};


	while(1)
	{
		for(u8 i=0;i<10;i++){
			MGPIO_vSetPortVal(GPIO_PORTA,SevenSegArr[i],GPIO_LOW_PORTION);
			ARM_DELAY(2000);
		}

	}
}
