/*
 * UART_BOOTLOADER_V3.c
 *
 * Created: 1/13/2021 4:03:37 PM
 * Author : Ahmed Yousri
 */ 
/*
 *in V3: Assumption: App code Pages MAX = 2
*/
#include "MCAL_ATMEGA_BOOT.h"
#include "MCAL_ATMEGA_USART.h"

//#define BOOTLOADER_SECTION    __attribute__ ((section (".bootloader")))
//uint16_t BOOTLOADER_SECTION MyFlag = 5;
volatile unsigned char App_Code[384]=
{
	0
};
/*
#define CODE_SIZE 256
#define NUM_OF_PAGES 2
*/
#define BLD_ACK 'A'
uint16_t volatile code_size = 0;
uint8_t volatile num_of_pages = 0;
void boot_program_page (uint32_t page, uint8_t *buf)
{
	uint16_t i;
	uint32_t address;
	//uint16_t word;
	//uint8_t sreg;

	// Disable interrupts.
	//sreg = SREG; //Store last values of AVR STATUS REGISTER - SREG
	//cli();
	address = page*SPM_PAGESIZE;
	
	//eeprom_busy_wait (); // as we use safe in erase and fill.

	BOOT_PAGE_ERASE (address);
	
	//boot_spm_busy_wait ();      // Wait until the memory is erased.

	for (i=0; i<SPM_PAGESIZE; i+=2)
	{
		// Set up little-endian word.

		uint16_t w = *buf++;
		w += (*buf++) << 8;
		
		BOOT_PAGE_FILL (address + i, w);
	}

	BOOT_PAGE_WRITE (address);     // Store buffer in flash page.
	//boot_spm_busy_wait();       // Wait until the memory is written.

	// Reenable RWW-section again. We need this if we want to jump back
	// to the application after bootloading.

	BOOT_RWW_ENABLE ();

	// Re-enable interrupts (if they were ever enabled).

	//SREG = sreg;
}
void boot_uploade_app_code(void)
{
	//Future: add timeout for error checking return from function.
	uint16_t i;
	//uint8_t percestage =0;
	USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: SENDING ACK\n");
	USART_Transmit(BLD_ACK);
	USART_Transmit('\n');
	num_of_pages = USART_Receive();
	num_of_pages = num_of_pages - 48;
	code_size = (num_of_pages)*(uint8_t)128;
	for(i=0; i<code_size;i++) 
	{
		App_Code[i] = USART_Receive();
		//USART_Transmit('A');
		//USART_Transmit('\n');
		/*percestage = i;		
		USART_Transmit((percestage/100)+48);
		percestage%=100;
		USART_Transmit( (percestage/10) +48);
		percestage%=10;
		USART_Transmit( percestage +48);
		USART_Transmit_Msg((uint8_t *)"%\n");
		*/
	}	
}
int main(void)
{
	uint8_t pageNo;
	unsigned char tempBuffer = 0;
	USART_Init(12); // setting baudrate to 4800 : 12, 2400 : 25 || 9600 : 103 for 16MHZ
	USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: HELLO FROM BOOTLOADER\n");
	USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: WAITING FOR CMD\n");
	while(1)
	{
		
		tempBuffer = USART_Receive();
		USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: CMD RECIEVED IS\n ");
		USART_Transmit(tempBuffer);
		USART_Transmit(0x06);
		USART_Transmit_Msg((uint8_t *)"\n");

		switch (tempBuffer)
		{
			case 'A':   USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: SENDING COMMAND LIST:\n");
						USART_Transmit_Msg((uint8_t *)"\t F : TO FLASH\n");
						USART_Transmit_Msg((uint8_t *)"\t U : TO UPLOADE NEW APPLICATION HEX ARRAY\n");
						USART_Transmit_Msg((uint8_t *)"\t A : TO SEND CMD LIST\n");
						break;
			
			case 'U':	USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: UPLOADING APPLICATION CODE BYTES CMD RECIEVED\n");
						boot_uploade_app_code();
						//if(check != 0) USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: CODE UPLOADING ERROR\n");
						USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: CODE UPLOADING COMPLETED\n");
						//USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: CODE PAGES = \n");
						//USART_Transmit(num_of_pages+48);	
						break;
						
			
			case 'F':	USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: START FLASHING\n");
						//start at flash_start = 0x0000
						for(pageNo = 0 ; pageNo < (num_of_pages) ; pageNo++)
						{
							boot_program_page( pageNo, &App_Code[SPM_PAGESIZE*pageNo]);
						}
						USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: FLASHING IS FINISHED\n");
						//start the actual program
						asm("jmp 0");
						break;
			
			case 'R':   USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: JUMPING TO APPLICATION CODE");
						asm("jmp 0");
						break;			
			
			default:    USART_Transmit_Msg((uint8_t *)"BLD_DEBUG: UNDEFINED CMD, TO GET CMD LIST SEND A\n");			
		}
	}
}



