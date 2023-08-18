/*
 * STK_prv.h
 *
 *  Created on: Jul 27, 2023
 *      Author: Nada Mamdouh
 */

#ifndef MCAL_STK_STK_PRV_H_
#define MCAL_STK_STK_PRV_H_

#define STK_BASE_ADDR                  0xE000E010

typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}STK_RegMap_t;



#define STK              ((volatile STK_RegMap_t*)(STK_BASE_ADDR))

/*  -------------- REGISTERS --------------  */

// CTRL
#define CTRL_ENABLE       0
#define TICKINT           1
#define CLKSOURCE         2
#define COUNTFLAG         16

/* --------------------------------------------------------------- */

/* CLK_SOURCE --- options --- */
#define STK_AHB           0
#define STK_AHB_DIV_8     1

/* INTERRUPT CONTROL --- options --- */
#define INT_DISABLE       0
#define INT_ENABLE        1



#endif /* MCAL_STK_STK_PRV_H_ */
