/*
 * LCD_int.h
 *
 *  Created on: Jul 2, 2022
 *      Author: Nada Mamdouh
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_


void HLCD_vInit(void);
void HLCD_vSendCommand(u8 A_u8Cmd);
void HLCD_vSendData(u8 A_u8Data);
void HLCD_vPrintString(char A_s8String[]);
void HLCD_vPrintNumber(s32 A_s32Number);
void HLCD_vSetCursorPosition(u8 A_u8Row, u8 A_u8Col);
void HLCD_vSaveCustomChar(u8 A_u8CGRAM_IDK, u8 A_u8CustomCharData[]);
void HLCD_vDisplayCustomChar(u8 A_u8CGRAM_IDX);
void HLCD_vClearScreen(void);



#endif /* HAL_LCD_LCD_INT_H_ */
