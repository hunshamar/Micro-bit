#include <stdint.h>



#define TWIO ((NRF_TWI_REG*)0x4003000)

typedef struct{

    /* Tasks */
    volatile uint32_t STARTRX; //Start TWI receive sequence
    volatile uint32_t RESERVED0;
    volatile uint32_t STARTTX; //Start TWI transmit sequence
    volatile uint32_t RESERVED1[2];
    volatile uint32_t STOP; //Stop TWI transaction
    volatile uint32_t RESERVED2;
    volatile uint32_t SUSPEND; //Suspend TWI transaction
    volatile uint32_t RESUME; //Resume TWI transaction
    volatile uint32_t RESERVED3[56];
    
    /*Events*/
    volatile uint32_t STOPPED; //TWI stopped
    volatile uint32_t RXDREADY; //TWI RXD byte received
    volatile uint32_t RESERVED4[4];
    volatile uint32_t TXDSENT; //TWI TXD byte sent
    volatile uint32_t RESERVED5[1];
    volatile uint32_t ERROR; //TWI error
    volatile uint32_t RESERVED6[4];
    volatile uint32_t BB; //TWI byte boundary, generated before each byte that is sent or received
    volatile uint32_t RESERVED7[49];

    /* Registers */
    volatile uint32_t SHORTS; //Shortcut register
    volatile uint32_t RESERVED8[63];
    volatile uint32_t INTEN; //Enable or disable interrupt
    volatile uint32_t INTENSET; //Enable interrupt
    volatile uint32_t INTENCLR; //Disable interrupt
    volatile uint32_t RESERVED9[110];
    volatile uint32_t ERRORSRC; //Error source
    volatile uint32_t RESERVED10[14];
    volatile uint32_t ENABLE; //Enable TWI
    volatile uint32_t RESERVED11;
    volatile uint32_t PSELSCL; //Pin select for SCL
    volatile uint32_t PSELSDA; //Pin select for SDA
    volatile uint32_t RESERVED12[2];
    volatile uint32_t RXD; //RXD register
    volatile uint32_t TXD; //TXD register
    volatile uint32_t RESERVED13;
    volatile uint32_t FREQUENCY; //TWI frequency
    volatile uint32_t RESERVED14[24];
    volatile uint32_t ADRESS; //Address used in the TWI transfer


}NRF_TWI_REG;

void twi_init();

void twi_multi_read(uint8_t slave_address, uint8_t start_register, int registers_to_read, uint8_t * data_buffer);


