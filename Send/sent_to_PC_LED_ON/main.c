#define F_CPU 16000000UL
#define BAUDRATE(x) ((F_CPU / 16 / x) - 1)

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void uart_init(unsigned int baud)
{
	UBRR0H = (unsigned char)(baud >> 8);
	UBRR0L = (unsigned char)baud;
	UCSR0B = (1 << TXEN0) | (1 << RXEN0) |         (1<<RXCIE0);
}
void uart_write(unsigned char data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

int main(void)
{
	uart_init(BAUDRATE(9600));
	sei();
	while(1);
}
unsigned char uart_read()
{
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}


ISR(USART0_RX_vect)
{
	DDRA=0xFF;
	DDRE=0x00;
	unsigned char ch =uart_read();
	if(ch=='8')
	{
		_delay_ms(300);
		PORTA=0xFF;
		_delay_ms(300);
		PORTA=0xFE;
		_delay_ms(300);
		PORTA=0xFC;
		_delay_ms(300);
		PORTA=0xF8;
		_delay_ms(300);
		PORTA=0xF0;
		_delay_ms(300);
		PORTA=0xE0;
		_delay_ms(300);
		PORTA=0xC0; // 0011 1111
		_delay_ms(300);
		PORTA=0x80;
		_delay_ms(300);
		PORTA=0x00; 
		_delay_ms(300);
	}
	else if(ch=='7')
	{
		_delay_ms(300);
		PORTA=0xFF;
		_delay_ms(300);
		PORTA=0xFE;
		_delay_ms(300);
		PORTA=0xFC;
		_delay_ms(300);
		PORTA=0xF8;
		_delay_ms(300);
		PORTA=0xF0;
		_delay_ms(300);
		PORTA=0xE0;
		_delay_ms(300);
		PORTA=0xC0; // 0011 1111
		_delay_ms(300);
		PORTA=0x80;
		_delay_ms(300);
	}
	else if(ch=='6')
	{
		_delay_ms(300);
		PORTA=0xFF;
		_delay_ms(300);
		PORTA=0xFE;
		_delay_ms(300);
		PORTA=0xFC;
		_delay_ms(300);
		PORTA=0xF8;
		_delay_ms(300);
		PORTA=0xF0;
		_delay_ms(300);
		PORTA=0xE0;
		_delay_ms(300);
		PORTA=0xC0; // 0011 1111
		_delay_ms(300);
	}
	else if(ch=='5') // 0001 1111
	{
		_delay_ms(300);
		PORTA=0xFF;
		_delay_ms(300);
		PORTA=0xFE;
		_delay_ms(300);
		PORTA=0xFC;
		_delay_ms(300);
		PORTA=0xF8;
		_delay_ms(300);
		PORTA=0xF0;
		_delay_ms(300);
		PORTA=0xE0;
		_delay_ms(300);
	}
	else if(ch=='4') // 0000 1111
	{
		_delay_ms(300);
		PORTA=0xFF;
		_delay_ms(300);
		PORTA=0xFE;
		_delay_ms(300);
		PORTA=0xFC;
		_delay_ms(300);
		PORTA=0xF8;
		_delay_ms(300);
		PORTA=0xF0;
		_delay_ms(300);
	}
	else if(ch=='3') // 0000 0111
	{
		_delay_ms(300);
		PORTA=0xFF;
		_delay_ms(300);
		PORTA=0xFE;
		_delay_ms(300);
		PORTA=0xFC;
		_delay_ms(300);
		PORTA=0xF8;
		_delay_ms(300);
	}
	else if(ch=='2') //0000 0011
	{
		_delay_ms(300);
		PORTA=0xFF;
		_delay_ms(300);
		PORTA=0xFE;
		_delay_ms(300);
		PORTA=0xFC;
		_delay_ms(300);
	}
	else if(ch=='1') // 0000 0001
	{
		_delay_ms(300);
		PORTA=0xFF;
		_delay_ms(300);
		PORTA=0xFE;
		_delay_ms(300);
	}
	else
	{
		PORTA=0xFF;
	}
}