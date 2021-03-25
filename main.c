/*
 * Tuto_1.c
 *
 * Created: 2021-03-24 오후 10:31:55
 * Author : Moonvely_i
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF;
	PORTA = 0x00;
    /* Replace with your application code */
    while (1)
    {
		PORTA = 0xFF;
		_delay_ms(400);
		PORTA = 0x00;
		_delay_ms(400);
    }
	return 0;
}

