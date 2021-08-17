#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#define M0_HIGH (PORTA | 0x01)
#define M0_LOW (PORTA & 0xFE)

void Port_init(void)
{
	DDRA = 0xff;
	PORTA = 0xff;
	
}
void main(void)
{
	Port_init();
	while(1)
	{
		
		
		PORTA = 0xFF;     // Brake stop
		_delay_ms(1000);
		PORTA = 0x01;     // Drive forward
		_delay_ms(1000);
		
		PORTA = 0xFF;    // Brake stop
		_delay_ms(1000);
		PORTA = 0x02;     //  Drive backward
		_delay_ms(1000);
	}
}
