
#include "test.h"
#include "LED.h"
#include "uart.h"


void test_keyboard_to_LED(){

	char a = 0;
	char lastchar = 'a';
	//int sleep = 10000;
	iprintf("Enter '-' to exit \n\r");
	while(lastchar != '-'){
		
		//uart_init();

		
		do{
			a = uart_read();
			LED_print_char(lastchar-0x20);
		}while(a == 0);

		//uart_send(a - 0x20);
		iprintf("Mottatt character: %c \n\r", a);

		lastchar = a;	
		a = 0;
	}
	iprintf("Exited \n\r");
}