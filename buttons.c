#include "buttons.h"

int buttons_check_a(){
    /*Check if register high*/
	if (GPIO->IN & (1<<17)) 
    {
        /* Active low */
		return 0; 
    }
    else
    {
        return 1;
    }
}

int buttons_check_b()
{
    /*Check if register high*/
	if (GPIO->IN & (1<<26)) 
    {
        /* Active low */
		return 0; 
    }
    else
    {
        return 1;
    }
}