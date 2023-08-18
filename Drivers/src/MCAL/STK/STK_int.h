/*
 * STK_int.h
 *
 *  Created on: Jul 27, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_STK_STK_INT_H_
#define MCAL_STK_STK_INT_H_

void MSTK_vInit(void);

void MSTK_vStartTimer(u32 A_u32LoadValue);
void MSTK_vStopTimer(void);

void MSTK_vSetDelay(u32 A_u32Ticks);

void MSTK_vSetInterval_singls(u32 A_u32Ticks, void (*CallbackFunction)(void));
void MSTK_vSetInterval_Periodic(u32 A_u32Ticks, void (*CallbackFunction)(void));

u32 MSTK_u32GetElapsedTime(void);
u32 MSTK_u32GetRemainingTime(void);



#endif /* MCAL_STK_STK_INT_H_ */
