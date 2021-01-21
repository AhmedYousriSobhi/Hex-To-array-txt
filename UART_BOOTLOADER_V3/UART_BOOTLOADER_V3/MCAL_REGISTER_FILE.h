/*
 * HAL_REGISTER_FILE.h
 *
 * Created: 1/12/2021 4:58:42 PM
 *  Author: Ahmed Yousri
 */ 


#ifndef MCAL_REGISTER_FILE_H_
#define MCAL_REGISTER_FILE_H_

#include "STD_LIB.h"

typedef uint16_t DATAADDRESSWIDTH;
typedef volatile DATAADDRESSWIDTH *const REGFileTypeAddr;

#define R0_ADDRESS  0x00
#define R1_ADDRESS  0x01
#define R2_ADDRESS  0x02
#define R30_ADDRESS 0x1E
#define R31_ADDRESS 0x1F

#define R0    *(REGFileTypeAddr)R0_ADDRESS
#define R1    *(REGFileTypeAddr)R1_ADDRESS
#define R2    *(REGFileTypeAddr)R2_ADDRESS
#define R30   *(REGFileTypeAddr)R30_ADDRESS
#define R31   *(REGFileTypeAddr)R31_ADDRESS
#define Z_PTR *(REGFileTypeAddr)R30_ADDRESS
#define Z_PTR_LB R30        //Z-Register Low Byte
#define Z_PTR_HB R31        //Z-Register High Byte
#define PCPAGE_MASK  0x3F80 // Z13:Z7
#define PCWORD_MASK  0x007E // Z6:Z1

#endif /* HAL_REGISTER_FILE_H_ */