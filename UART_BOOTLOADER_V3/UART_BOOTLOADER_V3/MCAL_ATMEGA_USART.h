/*
 * MCAL_ATMEGA_USART.h
 *
 * Created: 1/13/2021 4:13:52 PM
 *  Author: Ahmed Yousri
 */ 


#ifndef MCAL_ATMEGA_USART_H_
#define MCAL_ATMEGA_USART_H_

#include "STD_LIB.h"

typedef uint8_t USARTADDRESSBUSWIDTH;
typedef volatile USARTADDRESSBUSWIDTH * const USARTRegTypeAddr;

#define UBRRH_ADDRESS 0x40
#define UCSRC_ADDRESS 0x40
#define UDR_ADDRESS   0x2C
#define UCSRA_ADDRESS 0x2B
#define UCSRB_ADDRESS 0x2A
#define UBRRL_ADDRESS 0x29

#define UBRRH  *(USARTRegTypeAddr)UBRRH_ADDRESS
#define UCSRC  *(USARTRegTypeAddr)UCSRC_ADDRESS
#define UDR    *(USARTRegTypeAddr)UDR_ADDRESS
#define UCSRA  *(USARTRegTypeAddr)UCSRA_ADDRESS
#define UCSRB  *(USARTRegTypeAddr)UCSRB_ADDRESS
#define UBRRL  *(USARTRegTypeAddr)UBRRL_ADDRESS
/*UCSRA*/
#define MPCM  0
#define U2X   1
#define PE    2
#define DOR   3
#define FE    4
#define UDRE  5
#define TXC   6
#define RXC   7
/*UCSRB*/
#define TXB8  0
#define RXB8  1
#define UCSZ2 2
#define TXEN  3
#define RXEN  4
#define UDRIE 5
#define TXCIE 6
#define RXCIE 7
/*UCSRC*/
#define UCPOL 0
#define UCSZ0 1
#define UCSZ1 2
#define USBS  3
#define UPM0  4
#define UPM1  5
#define UMSEL 6
#define URSEL 7

#define UART_INDATA_AVAILABLE  (UCSRA & (1<<RXC))

void USART_Init( unsigned int baud );
void USART_Transmit( unsigned char data );
void USART_Transmit_Msg(uint8_t *word );
unsigned char USART_Receive( void );
unsigned char USART_Receive_Data(void);
void USART_Flush( void );

#endif /* MCAL_ATMEGA_USART_H_ */