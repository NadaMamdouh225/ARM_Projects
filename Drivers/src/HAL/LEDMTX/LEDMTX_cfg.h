/*
 * LEDMTX_cfg.h
 *
 *  Created on: Aug 1, 2023
 *      Author: Nada Mamdouh
 */

#ifndef HAL_LEDMTX_LEDMTX_CFG_H_
#define HAL_LEDMTX_LEDMTX_CFG_H_

#define NO_COLS     8
#define NO_ROWS     8
#define SCAN_TIME   2.5

extern MGPIO_Config_t rows[NO_ROWS];
extern MGPIO_Config_t cols[NO_COLS];


#endif /* HAL_LEDMTX_LEDMTX_CFG_H_ */
