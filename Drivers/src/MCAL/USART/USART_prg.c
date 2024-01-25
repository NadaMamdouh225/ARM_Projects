/*
 * USART_prg.c
 *
 *  Created on: Dec 3, 2023
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "USART_int.h"
#include "USART_prv.h"
#include "USART_cfg.h"

static void (*G_Fptr_USART1)(void) = {NULL};
static void (*G_Fptr_USART2)(void) = {NULL};
static void (*G_Fptr_USART6)(void) = {NULL};

void MUSART_vInit(USART_Init_t*A_xInitStruct,CLK_Init_t *A_xCLK_TypeDef ,USART_RegMap_t* USARTx)
{
	switch(A_xInitStruct->OverSampling)
	{
	case OVERSAMPLE_16:
		USARTx->BRR = UART_BRR_SAMPLING16(PCLK, A_xInitStruct->BaudRate);
		break;
	case OVERSAMPLE_8:
		USARTx->BRR = UART_BRR_SAMPLING8(PCLK, A_xInitStruct->BaudRate);
		break;
	default:
		/* invalid */
		break;
	}
	USARTx->CR1 =(A_xInitStruct->OverSampling << OVER8) |
				 (A_xInitStruct->Parity_ENA << PCE)     |
				 (A_xInitStruct->ParitySelection << PS) |
				 (A_xInitStruct->DataWidth << M)        ;
	switch(A_xInitStruct->TransferDirection)
	{
	case TX_ONLY:
		SET_BIT(USARTx->CR1,TE);
		break;
	case RX_ONLY:
			SET_BIT(USARTx->CR1,RE);
			break;
	case TX_RX:
			SET_BIT(USARTx->CR1,TE);
			SET_BIT(USARTx->CR1,RE);
			break;
	}

	USARTx->CR2 = (A_xInitStruct->StopBits << STOP_0)       |
				  (A_xCLK_TypeDef->CLK_Polarity << CPOL)    |
				  (A_xCLK_TypeDef->CLK_Phase << CPHA)       |
				  (A_xCLK_TypeDef->CLK_Enable << CLKEN)     |
				  (A_xCLK_TypeDef->LastBitCLKPulse << LBCL) ;

	/* Clear status register */
	USARTx->SR = 0;
	MUSART_vEnable(USARTx);
}
void MUSART_vEnable(USART_RegMap_t* USARTx)
{
	SET_BIT(USARTx->CR1,UE);
}
void MUSART_vDisable(USART_RegMap_t* USARTx)
{
	CLR_BIT(USARTx->CR1,UE);
}
void MUSART_vTX_Byte(USART_RegMap_t *USARTx,u8 A_u8Byte)
{
	/* Check whether register empty or not */
	while(GET_BIT(USARTx->SR,TXE)== 0);

	/* Write data */
	USARTx->DR = A_u8Byte;

	/* Wait until data is transmitted */
	while(GET_BIT(USARTx->SR,TC) == 0);

	/* clear TC bit */
	CLR_BIT(USARTx->SR,TC);

}
void MUSART_vTX_String(USART_RegMap_t *USARTx,u8 *A_ptru8String)
{
	u8 L_u8Index = 0;
	while(A_ptru8String[L_u8Index] != '\0')
	{
		MUSART_vTX_Byte(USARTx,A_ptru8String[L_u8Index]);
		L_u8Index++;
	}
}
u8 MUSART_u8ReceiveByte_Sync_NonBlocking(USART_RegMap_t *USARTx)
{
	u8 L_u8ReceiveData = 0;
	u8 L_u8TimeOut = 0;
	/* Wait until receiving data */
	while((GET_BIT(USARTx->SR,RXNE) == 0) && (L_u8TimeOut < THRESHOLD_VAL))
	{
		L_u8TimeOut++;
	}
	if(L_u8TimeOut == THRESHOLD_VAL)
	{
		L_u8ReceiveData = 255;       // left while loop because it ran out of time and no data received
	}else
	{
		/*Read data*/
		L_u8ReceiveData = USARTx->DR;
	}
	return L_u8ReceiveData;
}
u8 MUSART_u8ReceiveByte_Async(USART_RegMap_t *USARTx)
{
	/* this uses interrupt, receiving data means flag was raised and you received data */
	return USARTx->DR;
}
u8 *MUSART_ptru8ReceiveStr_Sync_NonBlocking(USART_RegMap_t *USARTx)
{

}

void MUSART1_vSetCallBack(void (*Fptr)(void))
{
	G_Fptr_USART1 = Fptr;
}
void MUSART2_vSetCallBack(void (*Fptr)(void))
{
	G_Fptr_USART2 = Fptr;
}
void MUSART6_vSetCallBack(void (*Fptr)(void))
{
	G_Fptr_USART6 = Fptr;
}
void USART1_IRQHandler(void)
{
	USART1->SR = 0;
	G_Fptr_USART1();
}
void USART2_IRQHandler(void)
{
	USART2-> SR = 0;
	G_Fptr_USART2();
}
void USART6_IRQHandler(void)
{
	USART6-> SR = 0;
	G_Fptr_USART6();
}


