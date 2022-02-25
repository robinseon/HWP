/*
 * handin3.c
 *
 * Created: 25/02/2022 08:47:30
 * Author : robin
 */ 

#include <avr/io.h>
#include "key/key_driver.h"
#include "led/led_driver.h"


int main(void)
{
    /* Replace with your application code */
	init_keys();
	inits_leds();
    while (1) 
    {
		//LED1 --> AND
		set_led(1,get_key(1)&get_key(2));
		//LED2 --> OR
		set_led(2,get_key(1)|get_key(2));
		//LED3 --> XOR
		set_led(3,get_key(1)^get_key(2));
		//LED4 --> NAND
		set_led(4,!(get_key(1)&get_key(2)));
		//LED5 --> NOR
		set_led(5,!(get_key(1)|get_key(2)));
		//LED6 --> NXOR
		set_led(6,!(get_key(1)^get_key(2)));
    }
}

