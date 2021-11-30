#define F_CPU 160000000UL
#include <avr/io.h>
#include <util/delay.h>

int init_adc(void)
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

void int_adc();
unsigned short read_adc();
void show_adc_led(unsigned short data);

int status_led = 0;

int main(void)
{
	int value;
	
	DDRF = 0x00;
	DDRA = 0xff;
	DDRB = 0xff;
	
	DDRD = 0x00;
	
	DDRC = 0xff;
	
	init_adc();
	
	PORTB = 0X00;
		

	while(1){
		PORTA = 0x00;
		PORTC = 0x00;
		if((PIND&0x01) == 0x00){   //use button as a switch
			status_led  = 1 - status_led;
			    //delay to divide
		}
		
		  
		if(status_led == 1){   //locked
			PORTB = 0x01;      //status led on
			PORTA = 0x09;      //laser on
			
			if(value < 630){
				PORTC = 0xff;
			}
			
		}
		else{                  //unlocked
			PORTB = 0x00;      //status led off
			PORTA = 0x04;      //laser off
		}
		
		
		_delay_ms(100);    
	}
	
}


