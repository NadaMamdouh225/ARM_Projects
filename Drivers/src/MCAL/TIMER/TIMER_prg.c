/*
 * TIMER_prg.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Nada Mamdouh
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_int.h"
#include "TIMER_cfg.h"
#include "TIMER_prv.h"


static u32 G_u32SaveRisingSample;
static u32 G_u32SavePulseWidth;

/**************************************************/
/*Function name: MTIMER_vCfg_TIM2_IC              */
/*Description: configuring TIM2 input capture     */
/**************************************************/

void MTIMER_vCfg_TIM2_InputCapture(void)
{

	/* Configure channel 1 as input (TI1 is the external input source used) */
	SET_BIT(TIM2->CCMR1,CC1S0);
	CLR_BIT(TIM2->CCMR1,CC1S1);

	/* Input Filter for external CLK mode1 TI1 */
	SET_BIT(TIM2->CCMR1,IC1F0);
	SET_BIT(TIM2->CCMR1,IC1F1);
	CLR_BIT(TIM2->CCMR1,IC1F2);
	CLR_BIT(TIM2->CCMR1,IC1F3);

	/* Select Polarity: rising edge for channel 1 */
	CLR_BIT(TIM2->CCER,CC1P);
	CLR_BIT(TIM2->CCER,CC1NP);

	/* Select prescaler */
	// Disable prescaler, capture is done each time an edge is detected on the capture input
	CLR_BIT(TIM2->CCMR1,IC1PSC0);
	CLR_BIT(TIM2->CCMR1,IC1PSC1);

	/* Enable counter */
	SET_BIT(TIM2->CR1,CEN);

	/* Enable capture from the counter into the capture register */
	SET_BIT(TIM2->CCER,CC1E);


}
/************************************************************/
/*Function name: MTIMER_vCfg_TIM2_PulseIn                   */
/*Description:Configuring a pulse capture (PWM input mode)  */
/************************************************************/
void MTIMER_vCfg_TIM2_PulseIn(void)
{
	/* Configure channel 1 as input (TI1 is the external input source used) */
	SET_BIT(TIM2->CCMR1,CC1S0);
	CLR_BIT(TIM2->CCMR1,CC1S1);

	/* Select Polarity: rising edge for channel 1 */
	CLR_BIT(TIM2->CCER,CC1P);
	CLR_BIT(TIM2->CCER,CC1NP);

	/* Configure channel 2 as input (TI1 is the external input source used) */
	CLR_BIT(TIM2->CCMR1,CC2S0);
	SET_BIT(TIM2->CCMR1,CC2S1);

	/* Select Polarity: falling edge for channel 2 */
	SET_BIT(TIM2->CCER,CC2P);
	CLR_BIT(TIM2->CCER,CC2NP);

	/* Select the valid trigger input */
	SET_BIT(TIM2->SMCR,TS0);
	CLR_BIT(TIM2->SMCR,TS1);
	SET_BIT(TIM2->SMCR,TS2);

	/* Configure the slave mode controller in reset mode (Rising edge of the selected trigger input reinitializes the counter)*/
	CLR_BIT(TIM2->SMCR,SMS0);
	CLR_BIT(TIM2->SMCR,SMS1);
	SET_BIT(TIM2->SMCR,SMS2);

	/* Enable capture from the counter into the capture register */
	SET_BIT(TIM2->CCER,CC1E);
	SET_BIT(TIM2->CCER,CC2E);

}

/**************************************************/
/*Function name: MTIMER_u32_TIM2_IC               */
/*Description: Get captured signal                */
/**************************************************/
void  MTIMER_vTIM2_IC(void)
{
	/* Wait until rising edge flag is raised */
	while(GET_BIT(TIM2->SR,CC1IF) == 0);

	/* Save channel1's counter value and clear flag */
	G_u32SaveRisingSample = TIM2->CCR1;

	/* Reset Counter */
	TIM2->CNT = CLEAR_COUNTER;

}
/************************************************************/
/*Function name: MTIMER_f32TIM2_PulseIn                     */
/*Description: Capture a pulse (PWM input mode)             */
/************************************************************/
f32 MTIMER_f32TIM2_PulseIn(void)
{
	f32 L_f32PulseTime = 0;
	f32 L_f32PulseFreq;
	u16 L_u16PSCvalue;

	/* Wait until falling edge flag is raised */
	while(GET_BIT(TIM2->SR,CC2IF) == 0);

	/* Save channel1's duty cycle value and clear flag */
	G_u32SavePulseWidth = TIM2->CCR2;

	/* Convert counts to time */
	L_u16PSCvalue = (TIM2->PSC) + 1 ;
	L_f32PulseFreq = (f32)TimerClkFreq /((f32) L_u16PSCvalue *(f32) G_u32SavePulseWidth );
	L_f32PulseTime = 1 / L_f32PulseFreq;

	return L_f32PulseTime;

}
/* Next step: using interrupt */
/*
void TIM2_IRQHandler(void)
{
	// Read value when receiving interrupt to save it and clear flag

}*/
