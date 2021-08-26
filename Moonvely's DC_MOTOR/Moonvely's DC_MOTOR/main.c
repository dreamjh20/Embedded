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
	int i = 0;
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
			
			if(i == 100)
			{
				i = 0;
				PORTA=0x00;
			}
			else if(i == 0){
				i = 75;
				PORTA=0x20;
			}
			else if(i == 75){
				i = 80;
				PORTA=0x30;
			}
			else if(i == 80){
				i = 85;
				PORTA=0x38;
			}
			else if(i == 85){
				i = 90;
				PORTA=0x3C;
			}
			else if(i == 90){
				i = 95;
				PORTA=0x3E;
			}
			else if(i == 95){
				i = 100;
				PORTA=0x3F;
			}
		}
		else if(PIND == 0x04)
		{
			PORTA=0x00;
			i = 0;
		}
	
		DC_Motor(i);
		_delay_ms(500);
		
		/*
		for(i=0;i<=100;i++) {
			DC_Motor(i); _delay_ms(100);
		}
		for(i=100;i>=0;i--){
			DC_Motor(i); _delay_ms(100);
		}*/
	}
}
