/*
 * ULTRASONIC_cfg.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Nada Mamdouh
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_CFG_H_
#define HAL_ULTRASONIC_ULTRASONIC_CFG_H_

/* In case of using more then one Ultrasonic sensor change TRIG_PINS_NO and ECHO_PINS_NO */
#define  TRIG_PINS_NO    1
#define  ECHO_PINS_NO    1

#define INVERSE_SOUND_SPEED      57142             /* Speed of sound = 350 with Temperature:28 and humidity:86 */
                                                   /* 350/2 *(10^2(cm)/10^9(n)) */

extern MGPIO_Config_t TrigPins[TRIG_PINS_NO];
extern MGPIO_Config_t EchoPins[ECHO_PINS_NO];

#endif /* HAL_ULTRASONIC_ULTRASONIC_CFG_H_ */
