/*
 * UART_Setup.c
 *
 * Created: 6/24/2023 11:35:13 PM
 * Author : William Woo
 * Purpose: Encapsulate UART0 project by making header and .c file for constant reuse.
 * TODO   : Plan to encapsulate this module for reuse
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "uart0_driver.h" // load uart0 driver

FILE OUTPUT = FDEV_SETUP_STREAM(UART0_tx, NULL, _FDEV_SETUP_WRITE);

/* Main function for test */
int main(void)
{
	UART0_init(); // uart0 init
	stdout = &OUTPUT; // printf enable
	
    unsigned int tick = 0;
    while (tick <= 10) 
    {
		printf("Hello World: %d\n\r", tick++);
		_delay_ms(1000);
    }
	printf("End of this program!\n\r");
	return 0;
}

