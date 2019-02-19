
#include "test.h"
#include "LED.h"
#include "uart.h"
#include "buttons.h"
#include "gpiote.h"
#include "ppi.h"


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

void test_LED_init(){
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}
}

void test_LED(){
	

	/* Check if button A is pressed; */
	if(buttons_check_a()){
		for (int i = 13; i <= 15; i++){
			GPIO->OUTCLR = (1<<i);
		}
	}
	
	/* Check if button B is pressed; */
	if(buttons_check_b()){
		for (int i = 13; i <= 15; i++){
			GPIO->OUTSET = (1<<i);
		}
	}
	
	
}

void test_gpiote_ppi(){
		/*Jordingspinnene til LED-matrisen konfigueres som output*/
	for (int i = 4; i <= 12; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}             //                  D  CC   BBBBB      AA
                  //       10987654321098765432109876543210
	GPIOTE->CONFIG[0] =  0b00000000000000100001000100000001; // A=Event, B= pin 17, C=LoToHi, D=Low - a-knapp = 0x00021101
 	              //       10987654321098765432109876543210
	GPIOTE->CONFIG[1] =  0b00000000000000110000110100000011; // A=task, B= pin 13, C = Toggle, D = Low, forsyningspinne = 0x00030D03
                 //        10987654321098765432109876543210
	GPIOTE->CONFIG[2] =  0b00000000000000110000111000000011; // A=task, B= pin 14, C = Toggle, D = Low, forsyningspinne = 0x00030E03
                 //        10987654321098765432109876543210
	GPIOTE->CONFIG[3] =  0b00000000000000110000111100000011; // A=task, B= pin 15, C = Toggle, D = Low, forsyningspinne = 0x00030F03

  PPI->CHENSET = 0x0000000E; // E = 1110, channel 0 no effect, channel 1,2,3 = write enable
  PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->IN[0]);
  PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->OUT[1]);
  PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->IN[0]);
  PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->OUT[2]);
  PPI->PPI_CH[3].EEP = (uint32_t)&(GPIOTE->IN[0]);
  PPI->PPI_CH[3].TEP = (uint32_t)&(GPIOTE->OUT[3]);

}