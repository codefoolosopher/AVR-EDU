/*
 * 1_Data_Types.c
 *
 * Created: 6/25/2023 12:11:20 AM
 * Author : William Woo
 * Purpose : To see data types and their size in ATmega MCU
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "uart0_driver.h"

FILE OUTPUT = FDEV_SETUP_STREAM(UART0_tx, NULL, _FDEV_SETUP_WRITE);

int main(void)
{
	UART0_init();
	stdout = &OUTPUT;
    
	printf("\n\r");
	printf("--- Size of data types in ATmega\n\r");
	printf("%d\n\r", sizeof(char));
	printf("%d\n\r", sizeof(int));
	printf("%d\n\r", sizeof(short));
	printf("%d\n\r", sizeof(long));
	printf("%d\n\r", sizeof(float));
	printf("%d\n\r", sizeof(double));
	
	
	
    while (1) 
    { // IDLE
    }
	return 0;
}

