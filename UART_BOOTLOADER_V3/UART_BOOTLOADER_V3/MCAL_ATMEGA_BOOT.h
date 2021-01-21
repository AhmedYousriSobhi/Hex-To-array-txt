/*
 * HAL_ATMEGA_BOOT.h
 *
 * Created: 1/12/2021 4:29:29 PM
 *  Author: Ahmed Yousri
 */ 


#ifndef MCAL_ATMEGA_BOOT_H_
#define MCAL_ATMEGA_BOOT_H_
/*Includes needed*/
#include "MCAL_REGISTER_FILE.h"
//#include <avr/interrupt.h>

typedef uint16_t ADDRESSBUSWIDTH;
typedef volatile ADDRESSBUSWIDTH *const BOOTRegTypeAddr;

#define SPM_PAGESIZE 128

#define SPMCR_ADDRESS 0x57
#define SPMCR_REG  *(BOOTRegTypeAddr)SPMCR_ADDRESS

#define SPMEN  0
#define PGERS  1
#define PGWRT  2
#define BLBSET 3
#define RWWSRE 4
#define RWWSB  6
#define SPMIE  7

#define _BOOT_PAGE_ERASE_CMD (_BV(PGERS) | _BV(SPMEN))
#define _BOOT_PAGE_FILL_CMD  (_BV(SPMEN))
#define _BOOT_PAGE_WRITE_CMD (_BV(SPMEN) | _BV(PGWRT))
#define _BOOT_RWW_ENABLE_CMD (_BV(SPMEN) | _BV(RWWSRE))

void BOOT_PAGE_ERASE(uint16_t address);
void BOOT_PAGE_FILL(uint16_t address, uint16_t data);
void BOOT_CLEAR_TEMP_BUFFER(uint16_t address);
void BOOT_PAGE_WRITE(uint16_t address);
void HAL_FLASH_SPM(uint16_t address, uint16_t data, uint8_t SPMCR_reg_value);
void BOOT_RWW_ENABLE(void);
/*
 //Setting Address like datasheet not mask method:
 void BOOT_PAGE_ERASE(uint16_t address);
 void BOOT_PAGE_FILL(uint16_t address, uint16_t data);
 void BOOT_CLEAR_TEMP_BUFFER(uint16_t address);
 void BOOT_PAGE_WRITE(uint16_t address);
 void HAL_FLASH_SPM(uint16_t address, uint16_t data, uint8_t SPMCR_reg_value, uint8_t page_word_selcet); //type: 0 PAGE, 1 Word.
 void BOOT_RWW_ENABLE(void);
*/

#endif /* HAL_ATMEGA_BOOT_H_ */