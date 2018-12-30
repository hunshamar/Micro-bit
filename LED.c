#include "LED.h"


void LED_init(void){
    LED_clear();
}

void LED_clear(void){
    for (int i = 4; i <= 12; i++){
        GPIO->OUTSET = (1 << i);
    }
    for (int i = 13; i <= 15; i++){
        GPIO->OUTCLR = (1 << i);
    }
}


void LED_pixel_on(uint8_t x, uint8_t y)
{
    
    int data[2] = {-1,-1};
    LED_coordinates_to_ground_supply(data, x,y);
    uint8_t supply = data[0];
    uint8_t ground = data[1];


    GPIO->OUTSET = (1 << supply);
    GPIO->OUTCLR = (1 << ground);
    LED_clear();
}

void LED_print_char(char c){
    int a = c - ' ';

    for (int i = 0; i < 5; i++){
        char line = font[a][i];
        for (int j = 0; j < 5; j++){
            if ((line << j) & (0b10000)){
                LED_pixel_on(i,j);
            }
        }
    }
}

void LED_print(char* string){
    int wait = 10000/4;
    while (*string){
        while(--wait)
        {
        LED_print_char(*string);
        }
        string++;
        wait = 10000/4;
    }
}


void LED_coordinates_to_ground_supply(int* data, int x, int y)
{
    uint8_t ground = -1;
    uint8_t supply = -1;
    switch(x)
    {
        case 0:
            switch(y)
            {
                case 0:
                    supply = 15;
                    ground = 6;
                    break;
                case 1:
                    supply = 13;
                    ground = 11;
                    break;
                case 2: 
                    supply = 14;
                    ground = 5;
                    break;
                case 3:
                    supply = 15;
                    ground = 7;
                    break;
                case 4:
                    supply = 13;
                    ground = 4;
                    break;
            }
            break;
        case 1:
            switch(y)
            {
                case 0:
                    supply = 14;
                    ground = 10;
                    break;
                case 1:
                    supply = 13;
                    ground = 10;
                    break;
                case 2: 
                    supply = 13;
                    ground = 12;
                    break;
                case 3:
                    supply = 15;
                    ground = 8;
                    break;
                case 4:
                    supply = 14;
                    ground = 7;
                    break;
            }
            break;
        case 2:
            switch(y)
            {
                case 0:
                    supply = 15;
                    ground = 4;
                    break;
                case 1:
                    supply = 13;
                    ground = 9;
                    break;
                case 2: 
                    supply = 14;
                    ground = 6;
                    break;
                case 3:
                    supply = 15;
                    ground = 9;
                    break;
                case 4:
                    supply = 13;
                    ground = 5;
                    break;
            }
            break;
        case 3:
            switch(y)
            { 
                case 0:
                    supply = 14;
                    ground = 9;
                    break;
                case 1:
                    supply = 13;
                    ground = 8;
                    break;
                case 2: 
                    supply = 15;
                    ground = 12;
                    break;
                case 3:
                    supply = 15;
                    ground = 10;
                    break;
                case 4:
                    supply = 14;
                    ground = 8;
                    break;
            }
            break;
        case 4:
            switch(y)
            {
                case 0:
                    supply = 15;
                    ground = 5;
                    break;
                case 1:
                    supply = 13;
                    ground = 7;
                    break;
                case 2: 
                    supply = 14;
                    ground = 4;
                    break;
                case 3:
                    supply = 15;
                    ground = 11;
                    break;
                case 4:
                    supply = 13;
                    ground = 6;
                    break;
            }      
            break;     
    }    
    data[0] = supply;
    data[1] = ground;
}