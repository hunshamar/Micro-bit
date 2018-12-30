
#include "gpio.h"
#include "buttons.h"
#include "LED.h"


int main(){

		for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	
	LED_init();


	while(1){
		char alph[30];
		

		char a = 'A';	
		while(a <= 'Z'){
			alph[a-'A'] = a;
			a++;
		}

		LED_print(alph);

		



		/*

		if (buttons_check_a()){
			
			GPIO->OUTSET = (1 << 13); 
			GPIO->OUTSET = (1 << 14);
			//GPIO->OUTSET = (1 << 15); 
			GPIO->OUTCLR = (1 << 6);
			
			//GPIO->OUTSET = (1 << 4);
			GPIO->OUTSET = (1 << 5);
			GPIO->OUTSET = (1 << 7);
			GPIO->OUTSET = (1 << 8);
			GPIO->OUTSET = (1 << 9);
			//GPIO->OUTSET = (1 << 10);
			GPIO->OUTSET = (1 << 11);
			GPIO->OUTSET = (1 << 12);
		}
		if (buttons_check_b()){
			GPIO->OUTCLR = (1 << 13); 
			GPIO->OUTCLR = (1 << 14); 
			//GPIO->OUTCLR = (1 << 15); 
			
			GPIO->OUTSET = (1 << 6);
		}
		*/
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
