#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

#define CDS_10 450
#define CDS_20 485
#define CDS_30 520
#define CDS_40 555
#define CDS_50 590
#define CDS_60 625
#define CDS_70 650
#define CDS_100 685

void int_adc();
unsigned short read_adc();
void show_adc_led(unsigned short data);

int main(void)
{
	unsigned short value;

	DDRA = 0xFF;
	DDRF = 0x00;
	DDRB = 0xFF;
	init_adc();

	PORTA = 0x01;   //green on
	_delay_ms(3000); //3초 대기
	PORTB = 0x01;  // laser on
	PORTA = 0x02;  //blue on

	while (1)
	{
		value = read_adc();
		show_adc_led(value);
	}
}

void init_adc(void)
{
	ADMUX = 0x40;
	ADCSRA = 0x87;    // adc en
}

unsigned short read_adc()
{
	unsigned char adc_low, adc_high;
	unsigned short value;

	ADCSRA |= 0x40;    // ADC start
	// ADC Complete
	while((ADCSRA & 0x10) != 0x10);
	adc_low = ADCL;
	adc_high = ADCH;
	value = (adc_high << 8) | adc_low;

	return value;
}

void show_adc_led(unsigned short value)
{
	if(value<=600) PORTA = 0x04;     //object detected
	else PORTA = 0x02;     //clear
} 
