#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#define BAUDRATE(x) ((F_CPU / 16 / x ) - 1)
#include <util/delay.h>
volatile char speed=0;

int i = 0;

void DC_Motor(int speed)
{
	if(speed< 0) speed= 0;
	if(speed>100) speed=100;
	OCR1A=speed;
}
void uart_init(unsigned int baud)
{
	UBRR0H = (unsigned char)(baud >> 8);
	UBRR0L = (unsigned char)baud;
	UCSR0B = (1 << TXEN0) | (1 << RXEN0);
}

void uart_write(unsigned char data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

unsigned char uart_read()
{
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

int main(void)
{
	
	int ch = 0;
	DDRA=0xFF;
	DDRD=0x00;
	DDRB=0x60;
	TCCR1A=0x82;
	TCCR1B=0x1A;
	OCR1A=0;
	OCR1B=0;
	ICR1=100;
	sei();
	uart_init(BAUDRATE(9600));
	while(1)
	{
		ch = uart_read();
		if(ch == 48){ //0    꺼져
			DC_Motor(0);
			PORTA = 0X00;
			_delay_ms(100);
		}
		else if(ch == 49){ //1     풀파워
			DC_Motor(100);
			PORTA=0x01;
			_delay_ms(100);
		}
		else if(ch==50){ //2
			DC_Motor(80);
			PORTA=0x20;
			_delay_ms(100);
		}
		else if(ch==52){ //4
			DC_Motor(85);
			PORTA=0x10;
			_delay_ms(100);
		}
		else if(ch==54){ //6
			DC_Motor(90);
			PORTA=0x08;
			_delay_ms(100);
		}
		else if(ch==56){ //8
			DC_Motor(95);
			PORTA=0x04;
			_delay_ms(100);

		}
		else if(ch==57){ //9
			DC_Motor(95);
			PORTA=0x02;
			_delay_ms(100);

		}
		uart_write(ch);		
	}
}