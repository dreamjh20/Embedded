#define F_CPU 16000000UL
#define BAUDRATE(x) ((F_CPU / 16 / x) - 1)
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

#define TRIG 6
#define ECHO 7
#define SOUND_VELOCITY 340UL

void uart_init(unsigned int baud)
{
	UBRR0H = (unsigned char)(baud >> 8);
	UBRR0L = (unsigned char)baud;
	UCSR0B = (1 << TXEN0) | (1 << RXEN0);
	
}

void uart_write(unsigned char data)
{
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

unsigned char uart_read()
{
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

void UART1_print_string(char *str)
{
	for(int i = 0; str[i]; i++)
	uart_write(str[i]);
}


int main(void)
{
	uart_init(BAUDRATE(9600));
	char data[5];
	unsigned char ch;
	
	unsigned int distance;
	unsigned int i;
	DDRE = ((DDRE | (1<<TRIG)) & ~(1<<ECHO));
	DDRD = 0xFF;
	
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

		if(distance < 30){
			PORTD = 0b11111110;
			}else if(distance < 70){
			PORTD = 0b11111101;
			}else if(distance < 100){
			PORTD = 0b11111011;
			}else if(distance < 130){
			PORTD = 0b11110111;
		}
		else if(distance < 200){
			PORTD = 0b11101111;
			}else{
			PORTD = 0b11011111;
		}
		
		
		itoa(distance, data, 10);
		UART1_print_string(data);
		_delay_ms(1000);
		
		
	}
}