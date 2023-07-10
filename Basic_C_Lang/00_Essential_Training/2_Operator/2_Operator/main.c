/*
 * 2_Operator.c
 *
 * Created: 7/10/2023 11:19:05 PM
 * Author : William Woo
 * Purpose : To see how operators are being used in C
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "uart0_driver.h"
FILE OUTPUT = FDEV_SETUP_STREAM(UART0_tx, NULL, _FDEV_SETUP_WRITE);


int main(void)
{
	/* UART0 Init */
	UART0_init();
	/* printf enable */
	stdout = &OUTPUT;
	
	float var1, var2, var3, var4;
	
	var1 = 3 / 2; // no type casting
	var2 = 3.0 / 2;
	var3 = 3 / 2.0;
	var4 = 3.0 / 2.0;
	
	printf("\n\r");
	printf("Result 1: %f\n\r", var1); // 1.000000
	printf("Result 2: %f\n\r", var2); // 1.500000
	printf("Result 3: %f\n\r", var3); // 1.500000
	printf("Result 4: %f\n\r", var4); // 1.500000
	
    /* Replace with your application code */
    while (1) 
    {
		// IDLE
    }
	return 0;
}

