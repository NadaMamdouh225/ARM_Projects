/*
 * GPIO_int.h
 *
 *  Created on: Jul 5, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_

void MGPIO_vSetPinMode(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8Mode);
void MGPIO_vSetPinOutput_t(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8OutputType);
void MGPIO_vSetPinOutputSpeed(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8OutputSpeed);
void MGPIO_vSetPinInputPull(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8InputPull);
u8   MGPIO_u8GetPinData(u8 A_u8PortID, u8 A_u8PinNo);
void MGPIO_vSetPinVal(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8PinVal);
void MGPIO_vSetPinVal_Fast(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8PinVal);
void MGPIO_vAltFunc(u8 A_u8PortID, u8 A_u8PinNo, u8 A_u8AltFunc);



/* ----- PORTS ----- */
#define GPIO_PORTA        0
#define GPIO_PORTB        1
#define GPIO_PORTC        2

/* ----- PINS ----- */
#define GPIO_PIN0        0
#define GPIO_PIN1        1
#define GPIO_PIN2        2
#define GPIO_PIN3        3
#define GPIO_PIN4        4
#define GPIO_PIN5        5
#define GPIO_PIN6        6
#define GPIO_PIN7        7
#define GPIO_PIN8        8
#define GPIO_PIN9        9
#define GPIO_PIN10       10
#define GPIO_PIN11       11
#define GPIO_PIN12       12
#define GPIO_PIN13       13
#define GPIO_PIN14       14
#define GPIO_PIN15       15
#define GPIO_PIN16       16

/* ---------- MODES ---------- */
#define GPIO_MODE_INPUT    0b00
#define GPIO_MODE_OUTPUT   0b01
#define GPIO_MODE_ALTF     0b10
#define GPIO_MODE_ANALOG   0b11

/* -------- OUTPUT TYPE -------- */
#define GPIO_OT_PUSHPULL        0
#define GPIO_OT_OPEN_DRAIN      1

/* ---------- SPEED ---------- */
#define GPIO_LOW_SPEED    0b00
#define GPIO_MED_SPEED    0b01
#define GPIO_HIGH_SPEED   0b10
#define GPIO_VHIGH_SPEED  0b11

/* -------- PULL UP/DOWN -------- */
#define GPIO_NO_PULL      0b00
#define GPIO_PULL_UP      0b01
#define GPIO_PULL_DOWN    0b10

/* ------ PIN VALUE ------ */
#define GPIO_LOW      0
#define GPIO_HIGH     1

#endif /* MCAL_GPIO_GPIO_INT_H_ */
