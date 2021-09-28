#include <avr/io.h>
#include <util/delay.h>
#define TRIG 6
#define ECHO 7
#define SOUND_VELOCITY 340UL
#define F_CPU 16000000

int main(void)
{
	unsigned int distance;
	unsigned int i;
	DDRB = 0x10;
	DDRE = ((DDRE | (1<<TRIG)) & ~(1<<ECHO));
	DDRD = 0xFF;
	PORTD = 0xFF;
	
	while(1)
	{
		TCCR1B = 0x03;
		PORTE &= ~(1<<TRIG);
		_delay_us(10);
		PORTE |= (1<<TRIG);
		_delay_us(10);
		PORTE &= ~(1<<TRIG);
		while(!(PINE & (1<<ECHO)));
		TCNT1 = 0x0000;
		while(PINE & (1<<ECHO));
		TCCR1B = 0x00;
		distance = (unsigned int)(SOUND_VELOCITY * (TCNT1 * 4 / 2) / 1000);

		//음파의 속도는 340m/s 이므로 1cm를 이동하는데 약 29us.왕복거리
		
		/*if(distance < 300){
			for(i=0; i<5; i++)
			{
				PORTB = 0x10;
				_delay_ms(1);
				PORTB = 0x00;
				_delay_ms(1);
			}
			} else if(distance < 600){
			for(i=0; i<5; i++)
			{
				PORTB = 0x10;
				_delay_ms(1);
				PORTB = 0x00;
				_delay_ms(1);
			}
			_delay_ms(100);
			}   else if(distance < 1000){
			for(i=0; i<5; i++)
			{
				PORTB = 0x10;
				_delay_ms(1);
				PORTB = 0x00;
				_delay_ms(1);
			}
			_delay_ms(300);
		}
		else;
		*/
		
		if(distance < 50)
		{
			PORTD = 0x01;
		}
		else if(distance < 100)
		{
			PORTD = 0x02;
		}
		else if(distance < 150)
		{
			PORTD = 0x04;
		}
		else if(distance < 200)
		{
			PORTD = 0x08;
		}
		else if(distance < 250)
		{
			PORTD = 0x10;
		}
		else
		{
			PORTD = 0x20;
		}
	}
}
