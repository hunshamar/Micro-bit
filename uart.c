#include "uart.h"

void uart_init(){
    /*  Pin 24 is TXD  Pin 25 is RXD  */ 
    
    GPIO->DIRSET |= (1 << 24); //Set as output
    GPIO->DIR &= ~(1 << 25); //Set as input //krasjer alt


    UART->PSELTXD = 24; //Set as TXD
    UART->PSELRXD = 25; //Set as RXD

    UART->BAUDRATE = 0x00275000; //Set baud rate to 9600 (actual rate 9598)

    UART->PSELCTS = 0xFFFFFFFF; //Disable CTS
    UART->PSELRTS = 0xFFFFFFFF; //Disable RTS
    UART->ENABLE = 4; //Enable uart;
    UART->STARTRX = 1; //Start uart reciever


}


void uart_send(char letter){
    UART->STARTTX = 1; //Start uart reciever
    UART->TXDRDY = 0; //Set interrupt register for UART low
    UART->TXD = letter; //Put character to be sendt into transfer register
    
    while (!(UART->TXDRDY)){ //Interrupt on TXDRDY is triggered when transmission is complete. wait until this trigger
        //Wait until transmission completed
    }

    UART->STOPTX = 1; //Trigger STOPTX task to stop UART transmission
    
}


char uart_read(){

    if (UART->RXDRDY){
        /*A byte has been moved to the RXD register*/
        UART->RXDRDY = 0;
        UART->STARTTX = 1; //UART reception squance is started

        char RXD_cont = UART->RXD;
        UART->STOPRX = 1; 
        return RXD_cont;
    }
    else{
        /*No byte in the RXD register*/
        return '\0';
    }
}

ssize_t _write(int fd   , const void *buf, size_t count){
	char * letter = (char *)(buf);
	for(int i = 0; i < count; i++){
		uart_send(*letter);
		letter++;
	}
	return count;
}
