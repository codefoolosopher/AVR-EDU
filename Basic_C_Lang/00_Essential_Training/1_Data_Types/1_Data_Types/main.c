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
	printf("char: %d byte\n\r", sizeof(char)); // 1byte
	printf("int: %d byte\n\r", sizeof(int)); // 2byte
	printf("short: %d byte\n\r", sizeof(short)); // 2byte
	printf("long: %d byte\n\r", sizeof(long)); // 4byte
	printf("float: %d byte\n\r", sizeof(float)); // 4byte
	printf("double: %d byte\n\r", sizeof(double)); // 4byte
	printf("--------------------------------\n\r");
	
	// Display each value corresponding to each data type
	char str[6] = "hello"; // contain null char
	
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

/* Appendix: how to represent floating number in a serial terminal
 * 1. RMB(Name of Project) -> Project property -> Toolchain -> AVR/GNU Linker -> Libraries
 * 2. [Add Libraries] -> type "libprintf_flt"
 * 3. Toolchain -> AVR/GNU Linker -> General
 * 4. Check "Use vprintf library"
 * 
 */ 