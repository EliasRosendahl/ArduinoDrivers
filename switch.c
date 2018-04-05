/**********************************************************
* "Switch.c"                                              *
* Implementation for "Mega2560 I/O Shield" SWITCH driver. *
* Henning Hargaard, 23/9 2015                             *
***********************************************************/
#include <avr/io.h>

// Klargør switch-porten
void initSwitchPort()
{
	DDRA = 0x00;
}

// Læser alle switches samtidigt
unsigned char switchStatus()
{
	return ~PINA;
}

// Returnerer TRUE, hvis switchen med nummeret
// "switch_nr" er aktiveret - ellers returneres FALSE
unsigned char switchOn(unsigned char switch_nr)
{
	
	if(switch_nr <= 7)
	{
		//Returns the status of the buttons and'ed with the "mask"
		//If the button is pressed, the return value is non zero
		return switchStatus() & 0b00000001 << switch_nr;
	}
	return 0;
}