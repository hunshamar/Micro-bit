
#include "gpio.h"
#include "buttons.h"
#include "LED.h"
#include "uart.h"
#include "test.h"

/*
ssize_t _read(int fd, void *buf, size_t count){
	char *str = (char*)(buf);
	char letter;

	do{
		letter = uart_read();
	} while(letter == '\0');

	*str = letter;
	return 1;
}
*/



int main(){

	//test_gpiote_ppi();

	/*

	SDA koblet til pin nr. 16, p0.30
	SCL koblet til port nr. 17, p0.00

	*/


	LED_init();
	uart_init();
	test_keyboard_to_LED();
	while(1){

	}


	

	return 0;












	/*

	buttons_init();

	
	test_LED_init();

	int sleep = 0;
	while(1){

		
		test_LED();
		sleep = 10000;
		while(--sleep);
	}
	return 0;

	*/
}
