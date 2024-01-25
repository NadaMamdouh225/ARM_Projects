/*
 * USART_prv.h
 *
 *  Created on: Dec 3, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_USART_USART_PRV_H_
#define MCAL_USART_USART_PRV_H_

#define USART1_BASE_ADDR          0x40011000U
#define USART2_BASE_ADDR          0x40004400U
#define USART6_BASE_ADDR          0x40011400U

typedef volatile struct {
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}USART_RegMap_t;


#define USART1      ((USART_RegMap_t*)(USART1_BASE_ADDR))
#define USART2      ((USART_RegMap_t*)(USART2_BASE_ADDR))
#define USART6      ((USART_RegMap_t*)(USART6_BASE_ADDR))

/* ------ MACROS by ST ------ */
#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            ((u32)((((u64)(_PCLK_))*25U)/(4U*((u64)(_BAUD_)))))
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U) + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            ((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

#define UART_DIV_SAMPLING8(_PCLK_, _BAUD_)             ((u32)((((u64)(_PCLK_))*25U)/(2U*((u64)(_BAUD_)))))
#define UART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (UART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         ((((UART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U) + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + ((UART DIVFRAQ & 0xF8) << 1) + (UART DIVFRAQ & 0x07U) */
#define UART_BRR_SAMPLING8(_PCLK_, _BAUD_)             ((UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) << 4U) + \
                                                        ((UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0xF8U) << 1U) + \
                                                        (UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0x07U))


/* ------------------------------------ REGISTERS ------------------------------------ */
/* --------  SR  -------- */
#define PE         0
#define FE         1
#define NF         2
#define ORE        3
#define IDLE       4
#define RXNE       5
#define TC         6
#define TXE        7
#define LBD        8
#define CTS        9

/* -------- CR1  -------- */
#define SBK        0
#define RWU        1
#define RE         2
#define TE         3
#define IDLEIE     4
#define RXNEIE     5
#define TCIE       6
#define TXEIE      7
#define PEIE       8
#define PS         9
#define PCE        10
#define WAKE       11
#define M          12
#define UE         13
#define OVER8      15

/* -------- CR2  -------- */
#define LBDL       5
#define LBDIE      6
#define LBCL       8
#define CPHA       9
#define CPOL       10
#define CLKEN      11
#define STOP_0     12
#define STOP_1     13
#define LINEN      14






#endif /* MCAL_USART_USART_PRV_H_ */
