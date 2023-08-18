/*
 * EXTI_int.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

typedef struct{
	u8 LineNo;
	u8 Trigger;
}EXTI_Config_t;

void MEXTI_vEnableINT_St(EXTI_Config_t* A_xConfig);

void MEXTI_vInit(void);
void MEXTI_vEnableINT(u8 A_u8LineNo,u8 A_u8Trigger_t);
void MEXTI_vDisableINT(u8 A_u8LineNo);

void MEXTI_vSoftwareTrigger(u8 A_u8LineNo);

void MEXTI_vSetTrigger(u8 A_u8LineNo, u8 A_u8Trigger_t);

void MEXTI_vSetCallback(u8 A_u8LineNo, void (*A_xFptr)(void));


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

/* ------- Trigger Type ------- */
#define EXTI_RISING_EDGE    0
#define EXTI_FALLING_EDGE   1
#define EXTI_ON_CHANGE      2





#endif /* MCAL_EXTI_EXTI_INT_H_ */
