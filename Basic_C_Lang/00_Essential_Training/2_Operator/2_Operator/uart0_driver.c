/*
 * uart0_driver.c
 *
 * Created: 6/24/2023 11:39:44 PM
 * Author: William Woo
 */ 
#include <avr/io.h>

void UART0_init(void)
{
	// set baud rate: 9,600
	UBRR0H = 0x00;
	UBRR0L = 207;
	
	// set 2x mode
	UCSR0A |= _BV(U2X0);
	
	// set: ASYNC | 8bit data | no parity | 1bit stop mode
	UCSR0C |= 0x06;
	
	// set TX/RX available
	UCSR0B |= _BV(RXEN0);
	UCSR0B |= _BV(TXEN0);
}

void UART0_tx(char data)
{
	// wait for data to be received
	while( !(UCSR0A & (1 << UDRE0)) );
	// tx data
	UDR0 = data;
}



