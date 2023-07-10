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
    
	// Display the size of each data type
	printf("\n\r");
	printf("--- Size of data types in ATmega\n\r");
	printf("char: %d byte\n\r", sizeof(char));
	printf("int: %d byte\n\r", sizeof(int));
	printf("short: %d byte\n\r", sizeof(short));
	printf("long: %d byte\n\r", sizeof(long));
	printf("float: %d byte\n\r", sizeof(float));
	printf("double: %d byte\n\r", sizeof(double));
	printf("--------------------------------\n\r");
	
	// Display each value corresponding to each data type
	char str[6] = "hello";
	
	printf("--- Values to each data type----\n\r");
	printf("Integer: %d\n\r", 128);
	printf("Float: %f\n\r", 1.28);
	printf("String: %s\n\r", str);
	printf("Character: %c\n\r", 'a');
	
    while (1) 
    { // IDLE
    }
	return 0;
}

