/*
 * HAL_ATMEGA_BOOT.c
 *
 * Created: 1/12/2021 4:49:56 PM
 *  Author: Ahmed Yousri
 */ 

#include "MCAL_ATMEGA_BOOT.h"

void BOOT_PAGE_ERASE(uint16_t address)
{
	/*
	* PAGE Erase uses PCPAGE which is bits [13:6] in Z-Pointer. so mask = 0x3F80
	*/
	//SPMCR_REG = _BOOT_PAGE_ERASE_CMD;
	address &= PCPAGE_MASK;
	HAL_FLASH_SPM(address, 0, _BOOT_PAGE_ERASE_CMD);
}

void BOOT_PAGE_FILL(uint16_t address,uint16_t data)
{
	//SPMCR_REG = _BOOT_PAGE_FILL_CMD;
	address &= PCWORD_MASK;
	HAL_FLASH_SPM(address,data,_BOOT_PAGE_FILL_CMD);	
}

void BOOT_PAGE_WRITE(uint16_t address)
{
	address &= PCPAGE_MASK;
	HAL_FLASH_SPM(address, 0, _BOOT_PAGE_WRITE_CMD);
}

void HAL_FLASH_SPM(uint16_t address, uint16_t data, uint8_t SPMCR_reg_value)
{
	/*
	* Put word in R1:R0
	* Put address in R31:R30 (Z-Pointer)
	* Execute SPM Instruction.
	*/
	//uint8_t sreg = SREG;			       //Save Status Register.
	//cli();                             //Disable Interrupts.
	volatile uint16_t old_word = R0;     // Save R1:R2
	R0 = data;                           // Put data into R1:R0
	volatile uint16_t old_Z_Ptr = Z_PTR; // Save z-Pointer (R31:R30)
	Z_PTR = address;                     // Put address into Z-Pointer.
	SPMCR_REG = SPMCR_reg_value;             // Set the SPMCR Register.
	asm volatile("spm");                  // Execute SPM Instruction.
	while((SPMCR_REG & _BV(SPMEN)) != 0);    // Wait for SPM to finish.
	Z_PTR = old_Z_Ptr;                   // Restore z-Pointer.
	R0 = old_word;                       //Restore R0:R1
	//SREG = sreg;                         // Restore Status Register.
}

void BOOT_CLEAR_TEMP_BUFFER(uint16_t address)
{
	SPMCR_REG |= _BV(RWWSRE);
}

void BOOT_RWW_ENABLE(void)
{
	SPMCR_REG |= _BOOT_RWW_ENABLE_CMD;
	asm volatile("spm");                  // Execute SPM Instruction.
}

/*
  void BOOT_PAGE_ERASE(uint16_t address)
{
	// PAGE Erase uses PCPAGE which is bits [13:6] in Z-Pointer. so mask = 0x3F80	
	//SPMCR_REG = _BOOT_PAGE_ERASE_CMD;
	HAL_FLASH_SPM(address, 0, _BOOT_PAGE_ERASE_CMD,0);
}

void BOOT_PAGE_FILL(uint16_t address,uint16_t data)
{
	//SPMCR_REG = _BOOT_PAGE_FILL_CMD;
	HAL_FLASH_SPM(address,data,_BOOT_PAGE_FILL_CMD,1);	
}

void BOOT_PAGE_WRITE(uint16_t address)
{
	address &= PCPAGE_MASK;
	HAL_FLASH_SPM(address, 0, _BOOT_PAGE_WRITE_CMD,0);
}

void HAL_FLASH_SPM(uint16_t address, uint16_t data, uint8_t SPMCR_reg_value, uint8_t page_word_select)
{
	//Put word in R1:R0
	// Put address in R31:R30 (Z-Pointer)
	//Execute SPM Instruction.
	
	//uint8_t sreg = SREG;			       //Save Status Register.
	//cli();                             //Disable Interrupts.
	volatile uint16_t old_word = R0;     // Save R1:R2
	R0 = data;                           // Put data into R1:R0
	volatile uint16_t old_Z_Ptr = Z_PTR; // Save z-Pointer (R31:R30)
	// Put address into Z-Pointer.
	if(page_word_select == 1) Z_PTR= address<<1;   // PCWORD
	else if(page_word_select == 0) {Z_PTR_LB = (address<<6); Z_PTR_HB = (address>>1);}                     
	
	SPMCR_REG = SPMCR_reg_value;             // Set the SPMCR Register.
	asm volatile("spm");                  // Execute SPM Instruction.
	while((SPMCR_REG & _BV(SPMEN)) != 0);    // Wait for SPM to finish.
	Z_PTR = old_Z_Ptr;                   // Restore z-Pointer.
	R0 = old_word;                       //Restore R0:R1
	//SREG = sreg;                         // Restore Status Register.
}

void BOOT_CLEAR_TEMP_BUFFER(uint16_t address)
{
	SPMCR_REG |= _BV(RWWSRE);
}

void BOOT_RWW_ENABLE(void)
{
	SPMCR_REG |= _BOOT_RWW_ENABLE_CMD;
	asm volatile("spm");                  // Execute SPM Instruction.
}

*/