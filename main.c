
#include "gpio.h"
#include "buttons.h"
#include "LED.h"
#include "uart.h"

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

	
	
	LED_init();
	uart_init();
	char a = 'A';
	int sleep = 10000;
	while(1){
		
		sleep = 10000/5;


		//uart_send('b');
		//sleep = 10000/3;
		while(sleep--)
			LED_print_char(a);
		a++;
		uart_send(a);
		iprintf("funker detta? %c \n\r",a);		
		//iprintf("test %d \n\r", 5);


		
		if (a > 'Z'){
			a = 'A';
		}
		
		
		/* Check if button B is pressed;
		 * turn on LED matrix if it is. */

		/* Check if button A is pressed;
		 * turn off LED matrix if it is. */

		/*
		sleep = 10000;
		while(--sleep);
		*/
		
	}
	return 0;
}
