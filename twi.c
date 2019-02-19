#include "twi.h"
#include "gpio.h"
#include "uart.h"


void twi_init(){
        

    TWIO->PSELSCL = 0; //Set port 0 as SCL
    TWIO->PSELSDA = 30; //Srt port 30 as SDA
    GPIO->PIN_CNF[0] = (1<<9) | (1 <<10) | (1 << 3) | (1 << 2);
    GPIO->PIN_CNF[30] = (1<<9) | (1 <<10) | (1 << 3) | (1 << 2);

    
    TWIO->RXDREADY = 0;
    TWIO->ERROR = 0;
    TWIO->TXDSENT = 0;
    TWIO->FREQUENCY = 0x01980000; //Set frequency to 100 kbps
    TWIO->ENABLE = 5; //Enable TWI

}


void twi_multi_read(uint8_t slave_address, uint8_t start_register, int registers_to_read, uint8_t * data_buffer){
    TWIO->ADRESS = slave_address; //Sett ADDRESS-registeret til slave_adress
    TWIO->STARTTX = 1; //Start en skriveoperasjon

    TWIO->TXDSENT = 0;

    TWIO->TXD = start_register; //Overfør start_Register til TWI-bussen

    while(!TWIO->TXDSENT){
        //wait
    } //TXDSENT-hendelse nå generert

    TWIO->STARTRX; //Start leseoperasjon



    TWIO->RXDREADY = 0;
    TWIO->STARTRX = 1;

    for(int i=0; i<=(registers_to_read-1); i++){

        if (i == registers_to_read-1){
            TWIO->STOPPED = 1;
        }

        while(!TWIO->RXDREADY);
        TWIO->RXDREADY = 0;
        data_buffer[i]=TWIO->RXD;
    }

    TWIO->RXDREADY = 0;
    TWIO->STARTRX = 1;

}