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
	
	float f_var1, f_var2, f_var3, f_var4;
	int n_var1 = 3, n_var2 = 5;
	
	f_var1 = 3 / 2; // no type casting
	f_var2 = 3.0 / 2;
	f_var3 = 3 / 2.0;
	f_var4 = 3.0 / 2.0;
	
	printf("\n\rLet'see arithmetic operators\n\r");
	printf("Result 1: %f\n\r", f_var1); // 1.000000
	printf("Result 2: %f\n\r", f_var2); // 1.500000
	printf("Result 3: %f\n\r", f_var3); // 1.500000
	printf("Result 4: %f\n\r", f_var4); // 1.500000
	printf("++++++++++++++++++++++++++++++++++++++++\n\r");
	
	printf("\n\rLet's see assignment & logical operators\n\r");
	
	if ( n_var1 == n_var2) printf("They are same\n\r");
	else printf("They are not the same\n\r");
	
	if ((n_var1 = n_var2)) printf("Result of conditional operation is TRUE\n\r"); // b/c it is not 0(false)
	printf("n_var1 : %d\n\r", n_var1);
    /* Replace with your application code */
    while (1) 
    {
		// IDLE
    }
	return 0;
}

