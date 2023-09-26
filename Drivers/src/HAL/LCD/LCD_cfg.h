/*
 * LCD_cfg.h
 *
 *  Created on: Sep 26, 2023
 *      Author: Nada Mamdouh
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

#define LCD_CLEAR                    0x01
#define Max_IDX_OF_ROWS              2
#define Max_IDX_OF_COLS              16
#define FIRST_ROW_IDX                0
#define SECOND_ROW_IDX               1
#define FIRST_ROW_START              0x00
#define SECOND_ROW_START             0x40
#define CGRAM_NUM_OF_PATTERNS        8
#define CGRAM_BASE_ADDRESS           0x40
#define DDRAM_BASE_ADDRESS           0x80

/* CTRL pins */
#define LCD_CTRL_PORT         GPIO_PORTA
#define LCD_DATA_PORT         GPIO_PORTA
#define LCD_RS_PIN            GPIO_PIN8
#define LCD_RW_PIN            GPIO_PIN9
#define LCD_EN_PIN            GPIO_PIN10


#define CTRL_PINS                    3
#define DATA_PINS                    8
extern MGPIO_Config_t LCD_CTRL[CTRL_PINS];
extern MGPIO_Config_t LCD_DATA[DATA_PINS];



#endif /* HAL_LCD_LCD_CFG_H_ */
