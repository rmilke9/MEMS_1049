/*
 * PWM_example.c
 *
 * Created: 3/27/2016 8:53:34 PM
 * Author : WW Clark
 */ 
/*
This program sets up and runs a simple PWM signal on OC0A pin.  

The base frequency is set with the prescaler, and the duty cycle is adjustable in the code.
*/

#include <avr/io.h>


int main(void)
{
	DDRD = 1<<PD6 | 1<<PD5;// Make OC0A (PD6) and OC0B (PD5) output bits -- these are the PWM pins;
	
	OCR0A = 0x00;       // Load $00 into OCR0 to set initial duty cycle to 0 (motor off)
	TCCR0A = 1<<COM0A1 | 0<<COM0A0 | 1<<WGM01 | 1<<WGM00;      // Set non-inverting mode on OC0A pin (COMA1:0 = 10; Fast PWM (WGM1:0 bits = bits 1:0 = 11) (Note that we are not affecting OC0B because COMB0:1 bits stay at default = 00)
	TCCR0B = 0<<CS02 | 1<<CS01 | 1<<CS00; // Set base PWM frequency (CS02:0 - bits 2-0 = 011 for prescaler of 64, for approximately 1kHz base frequency)
	// PWM is now running on selected pin at selected base frequency.  Duty cycle is set by loading/changing value in OCR0A register.

/* DDRD = 1<<PD6 | 1<<PD5;		// Make OC0A (PD6) and OC0B (PD5) output bits -- these are the PWM pins; 
								 
	OCR0A = 0x00;       // Load $00 into OCR0 to set initial duty cycle to 0 (motor off)
	TCCR0A = 1<<COM0A1 | 1<<WGM01 | 1<<WGM00;      // Set non-inverting mode on OC0A pin (COMA1:0 and COMB0:1 bits = bits 7:4 = 1000; Fast PWM (WGM1:0 bits = bits 1:0 = 11)
	TCCR0B = 0<<CS02 | 1<<CS01 | 1<<CS00; // Set base PWM frequency (CS02:0 - bits 2-0 = 011 for prescaler of 64, for approximately 1kHz base frequency)
		// PWM is now running on selected pin at selected duty cycle
*/
    
    while(1)
    {
	    
	    OCR0A = 191; //0xfb; // Load a number between 0-255 into OCR0A to set the duty cycle (0 = motor off, 255 = motor full on)

    }
    
    return(0);
}

