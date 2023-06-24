/*
 * UART_Setup.c
 *
 * Created: 6/24/2023 10:49:13 PM
 * Author : William Woo
 * Purpose: Make basic skeleton of UART(0) to see programming result on
 *			a serial terminal because no monitor exists on this system.
 * TODO   : Plan to encapsulate this module for reuse
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

// Function Prototype
void UART0_init(void);
void UART0_tx(char data);

FILE OUTPUT = FDEV_SETUP_STREAM(UART0_tx, NULL, _FDEV_SETUP_WRITE);

// Function Implementation

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
	// wait RX enable
	while( !(UCSR0A & (1 << UDRE0)) ); 
	// tx data
	UDR0 = data; 
}

int main(void)
{
	// INIT: uart0
	UART0_init();
	stdout = &OUTPUT; // enable printf
	
	/* User defined code */
	unsigned int tick = 0;
    while (tick <= 10) // UART0 test code
    {
		printf("Hello World: %d\n\r", tick++);
		_delay_ms(1000);
    }
	printf("End of program!! \n\r");
	/* End of user defined code */
	return 0;
}

