#include "gpio.h"
#include "font.h"

void LED_init(void);

void LED_clear(void);



/*
 * Turns on a single led on the 5x5 LED matrix
 * Coordinate system with 0,0 at lower left corner, 4,4 upper right corner
 *
 *
 */


void LED_pixel_on(uint8_t x, uint8_t y);

void LED_coordinates_to_ground_supply(int* data, int x, int y);

void LED_print(char* string);