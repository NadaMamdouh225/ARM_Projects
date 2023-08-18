/*
 * SYSCFG_int.h
 *
 *  Created on: Jul 28, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_SYSCFG_SYSCFG_INT_H_
#define MCAL_SYSCFG_SYSCFG_INT_H_

void MSYSCFG_vSetEXTIPort(u8 A_u8LineNo, u8 A_u8PortNo);

/* ------- PORT NUMBER ------- */

#define SYSCFG_PORT_A         0
#define SYSCFG_PORT_B         1
#define SYSCFG_PORT_C         2

/* ------- Line Number ------- */
#define EXTI_LINE0      0
#define EXTI_LINE1      1
#define EXTI_LINE2      2
#define EXTI_LINE3      3
#define EXTI_LINE4      4
#define EXTI_LINE5      5
#define EXTI_LINE6      6
#define EXTI_LINE7      7
#define EXTI_LINE8      8
#define EXTI_LINE9      9
#define EXTI_LINE10     10
#define EXTI_LINE11     11
#define EXTI_LINE12     12
#define EXTI_LINE13     13
#define EXTI_LINE14     14
#define EXTI_LINE15     15


#endif /* MCAL_SYSCFG_SYSCFG_INT_H_ */
