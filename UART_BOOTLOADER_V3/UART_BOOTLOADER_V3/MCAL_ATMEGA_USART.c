/*
 * MCAL_ATMEGA_UART.c
 *
 * Created: 1/13/2021 4:13:26 PM
 *  Author: Ahmed Yousri
 */ 

#include "MCAL_ATMEGA_USART.h"

void USART_Init( uint16_t baud )
{
	/* Set baud rate */
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 1stop bit */
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}

void USART_Transmit( uint8_t data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = data;
}

void USART_Transmit_Msg(uint8_t *word )
{
	uint8_t index = 0;
	while(word[index] != '\n')
	{
		USART_Transmit(word[index++]);
	}
	USART_Transmit('\n');
	
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;
}

unsigned char USART_Receive_Data(void)
{
	uint8_t index = 0;
	unsigned char data_arr[2];
	do 
	{
		data_arr[index] = USART_Receive();
	} while (data_arr[index++] != 'z'); // \n in dec = 10
	return data_arr[--index];
}

void USART_Flush( void )
{
	unsigned char dummy;
	while ( UCSRA & (1<<RXC) ) dummy = UDR;
}