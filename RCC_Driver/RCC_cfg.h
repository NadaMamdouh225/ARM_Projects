/*
 * RCC_cfg.h
 *
 *  Created on: Jul 1, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_RCC_RCC_CFG_H_
#define MCAL_RCC_RCC_CFG_H_


#define RCC_HSE_ENABLE          ENABLE
#define RCC_HSI_ENABLE          DISABLE
#define RCC_PLL_ENABLE          DISABLE


#define RCC_SYS_CLK             RCC_HSE_ENABLE
/* RCC_SYS_CLK
 * --- OPTIONS ---
 * 1- RCC_HSI_ENABLE
 * 2- RCC_HSE_ENABLE
 * 3- RCC_PLL_ENABLE
 * */

#define RCC_HSE_BYPASS         ENABLE_OSC
/* RCC_HSE_BYPASS
 * --- OPTIONS ---
 * 1- ENABLE_OSC
 * 2- ENABLE_EXTRNAL_CLK
 * 3- NONE                     // in case HSE isn't in use
 **/

#define RCC_CLK_SEC_SYS         ON
/* RCC_CLK_SEC_SYS
 * --- OPTIONS ---
 * 1- ON
 * 2- OFF
 * */


#endif /* MCAL_RCC_RCC_CFG_H_ */
