/*
 * led_driver.c
 *
 * Created: 25/02/2022 08:49:44
 *  Author: robin
 */ 

#include <avr/io.h>

void inits_leds() {
	DDRA = 0xFF; //DDRA is an output
	PORTA = 0xFF;// all the pin of PORTA to 1 to turn off all the LED
}

void set_led(uint8_t led_no, uint8_t state) {
	if (state == 1) {
		PORTA &= ~(1 << led_no - 1);//if state=1, turn on the led_no
	}
	else if (state == 0) {
		PORTA |= 1 << led_no - 1;//if state=0, turn off the led_no
	}
}