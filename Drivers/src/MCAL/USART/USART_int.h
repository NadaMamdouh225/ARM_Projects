/*
 * USART_int.h
 *
 *  Created on: Dec 3, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_USART_USART_INT_H_
#define MCAL_USART_USART_INT_H_

#include "USART_prv.h"

typedef struct
{
	u32 BaudRate;
	u8 DataWidth;
	u8 StopBits;
	u8 Parity_ENA;
	u8 ParitySelection;
	u8 TransferDirection;     // Tx only, Rx only or Tx,Rx
	u8 HW_FlowControl;
	u8 OverSampling;
}USART_Init_t;

typedef struct
{
	u32 CLK_Enable;
	u32 CLK_Polarity;
	u32 CLK_Phase;
	u32 LastBitCLKPulse;
}CLK_Init_t;



void MUSART_vInit(USART_Init_t*A_xInitStruct,CLK_Init_t *A_xCLK_TypeDef ,USART_RegMap_t* USARTx);
void MUSART_vEnable(USART_RegMap_t* USARTx);
void MUSART_vDisable(USART_RegMap_t* USARTx);
void MUSART_vTX_Byte(USART_RegMap_t *USARTx,u8 A_u8Byte);
void MUSART_vTX_String(USART_RegMap_t *USARTx,u8 *A_u8String);
/************************************************************/
/*Function name: MUSART_vReceiveByte_Sync_NonBlocking       */
/*Return: this returns 255 in case it ran out of time       */
/* and no data received                                     */
/************************************************************/
u8   MUSART_u8ReceiveByte_Sync_NonBlocking(USART_RegMap_t *USARTx);
u8  *MUSART_ptru8ReceiveStr_Sync_NonBlocking(USART_RegMap_t *USARTx);
u8 MUSART_u8ReceiveByte_Async(USART_RegMap_t *USARTx);
void MUSART1_vSetCallBack(void (*Fptr)(void));
void MUSART2_vSetCallBack(void (*Fptr)(void));
void MUSART6_vSetCallBack(void (*Fptr)(void));

/*--------- USART Prephral ---------*/
/* USART1
*  USART2
*  USART6
*/

/* ------ OVER SAMPLE ------ */
#define OVERSAMPLE_16       0
#define OVERSAMPLE_8        1

/* ---- Transfer direction options ---- */
#define TX_ONLY  0
#define	RX_ONLY  1
#define	TX_RX    2

/* ----- Parity selection -----*/
#define EVEN_PARITY    0
#define ODD_PARITY     1

/* ----- Word length ----- */
#define DATA_8BIT   0
#define DATA_9BIT   1

/* ----- Stop bits ----- */
#define STOP_BIT_1      0
#define STOP_BIT_0_5    1
#define STOP_BIT_2      2
#define STOP_BIT_1_5    3

#define ENABLE         1
#define DISABLE        0


#endif /* MCAL_USART_USART_INT_H_ */
