/*
 * TIMER_int.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Nada Mamdouh
 */

#ifndef TIMER_TIMER_INT_H_
#define TIMER_TIMER_INT_H_

void MTIMER_vInit(void);

/**************************************************/
/*Function name: MTIMER_vCfg_TIM2_IC              */
/*Description: configuring TIM2 input capture     */
/**************************************************/
void MTIMER_vCfg_TIM2_IC(void);

/**************************************************/
/*Function name: MTIMER_vTIM2_IC               */
/*Description: Get captured signal                */
/**************************************************/
void  MTIMER_vTIM2_IC(void);

/************************************************************/
/*Function name: MTIMER_vCfg_TIM2_PulseIn                   */
/*Description:Configuring a pulse capture (PWM input mode)  */
/************************************************************/
void MTIMER_vCfg_TIM2_PulseIn(void);
/************************************************************/
/*Function name: MTIMER_f32TIM2_PulseIn                     */
/*Description: Capture a pulse (PWM input mode)             */
/************************************************************/
f32 MTIMER_f32TIM2_PulseIn(void);

void MTIMER_vGeneratePWM(/* */);


#endif /* TIMER_TIMER_INT_H_ */
