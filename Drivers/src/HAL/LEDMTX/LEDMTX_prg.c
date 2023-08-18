/*
 * LEDMTX_prg.c
 *
 *  Created on: Aug 1, 2023
 *      Author: Nada Mamdouh
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/STK/STK_int.h"
#include "../DELAY/DELAY_int.h"

#include "LEDMTX_cfg.h"
#include "LEDMTX_int.h"
#include "LEDMTX_prv.h"

static void HLEDMTX_vDisableAllCols(void);
static void HLEDMTX_vEnableCurrentColumn(u8 A_u8ColumnNo);
static void HLEDMTX_vSetRowValue(u8 A_u8RowValue);

void HLEDMTX_vInit(void)
{
	/* set GPIO pin configuration */

	for(u8 L_u8index = 0;L_u8index<NO_ROWS;L_u8index++)
	{
		MGPIO_vInit(&rows[L_u8index]);
	}
	for(u8 L_u8index = 0;L_u8index<NO_COLS;L_u8index++)
	{
		MGPIO_vInit(&cols[L_u8index]);
	}
	MSTK_vInit();

}
void HLEDMTX_vDisplayFrame(u8 A_u8Frame[],u32 A_u32FrameDelay)
{
	for (u8 L_u8Jindex=0;L_u8Jindex < A_u32FrameDelay;L_u8Jindex++)
	{
		for(u8 L_u8index = 0;L_u8index<NO_COLS;L_u8index++)
		{
			/* Disable all columns */
			HLEDMTX_vDisableAllCols();
			/* Set row values */
			HLEDMTX_vSetRowValue(A_u8Frame[L_u8index]);
			/* Enable current column*/
			HLEDMTX_vEnableCurrentColumn(L_u8index);
			/* Calculated delay */
			HDELAY_vBusyWait_ms(SCAN_TIME);

		}
	}

}

static void HLEDMTX_vDisableAllCols(void)
{
	for(u8 L_u8index = 0;L_u8index<NO_COLS;L_u8index++)
	{
		MGPIO_vSetPinVal(cols[L_u8index].Port,cols[L_u8index].Pin,GPIO_HIGH); // Cathode is connected to GND
	}
}

static void HLEDMTX_vEnableCurrentColumn(u8 A_u8ColumnNo)
{
	MGPIO_vSetPinVal(cols[A_u8ColumnNo].Port,cols[A_u8ColumnNo].Pin,GPIO_LOW); // Cathode is connected to GND
}
static void HLEDMTX_vSetRowValue(u8 A_u8RowValue)
{

	for(u8 L_u8index = 0;L_u8index <NO_ROWS;L_u8index++)
	{
		MGPIO_vSetPinVal(rows[L_u8index].Port,rows[L_u8index].Pin,GET_BIT(A_u8RowValue,L_u8index));
	}
}
