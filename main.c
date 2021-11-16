#define F_CPU 160000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int number = 0;
    DDRD = 0x00;
	DDRA = 0xff;
	PORTA = 0xFF;
	DDRE = 0x00;

    while (1) 
	{
		
		if((PIND&0x10) == 0x00){
			number++;
			_delay_ms(100);
		}
		if((PINE&0x10) == 0x00){
			number = 0;
			_delay_ms(100);
		}
		
		if(number == 0) PORTA = 0b11111111;
		if(number == 1) PORTA = 0b11111110;
		if(number == 2) PORTA = 0b11111101;
		if(number == 3) PORTA = 0b11111100;
		if(number == 4) PORTA = 0b11111011;
		if(number == 5) PORTA = 0b11111010;
		if(number == 6) PORTA = 0b11111001;
		if(number == 7) PORTA = 0b11111000;
		if(number == 8) PORTA = 0b11110111;
		if(number == 9) PORTA = 0b11110110;
		if(number == 10) PORTA = 0b11110101;
		if(number == 11) PORTA = 0b11110100;
		if(number == 12) PORTA = 0b11110011;
		if(number == 13) PORTA = 0b11110010;
		if(number == 14) PORTA = 0b11110001;
		if(number == 15) PORTA = 0b11110000;
		if(number > 15) PORTA = 0b11110000;
		
    }
}