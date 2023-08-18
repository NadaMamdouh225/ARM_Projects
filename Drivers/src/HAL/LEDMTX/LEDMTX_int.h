/*
 * LEDMTX_int.h
 *
 *  Created on: Aug 1, 2023
 *      Author: Nada Mamdouh
 */

#ifndef HAL_LEDMTX_LEDMTX_INT_H_
#define HAL_LEDMTX_LEDMTX_INT_H_


void HLEDMTX_vInit(void);
void HLEDMTX_vDisplayFrame(u8 A_u8Frame[],u32 A_u32FrameDelay);

void HLEDMTX_vDisplayMatrix(u8 matrix[][8],u32 A_u32MatrixDelay);


#endif /* HAL_LEDMTX_LEDMTX_INT_H_ */
