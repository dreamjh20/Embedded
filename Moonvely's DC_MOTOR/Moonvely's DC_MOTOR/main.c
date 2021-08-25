#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
volatile char speed=0;
void DC_Motor(int speed)
{
	if(speed< 0) speed= 0;
	if(speed>100) speed=100;
	OCR1A=speed;
}

int main(void)
{
	int i;
	DDRA=0xFF;
	DDRD=0x00;
	DDRB=0x60;
	TCCR1A=0x82;
	TCCR1B=0x1A;
	OCR1A=0;
	OCR1B=0;
	ICR1=100;
	while(1)
	{
		if(PIND == 0x01)
		{
			PORTA=0xFF;
			i = 100;
		}
		else if(PIND == 0x02)
		{
			PORTA=0x0F;
			if(i == 100)
			{
				i = 0;
				PORTA=0x00;
			}
			else if(i == 0){
				i = 70;
			}
			else {
				i += 10;
			}
		}
		else if(PIND == 0x04)
		{
			PORTA=0x00;
			i = 0;
		}
		DC_Motor(i);
		
		/*
		for(i=0;i<=100;i++) {
			DC_Motor(i); _delay_ms(100);
		}
		for(i=100;i>=0;i--){
			DC_Motor(i); _delay_ms(100);
		}*/
	}
}
