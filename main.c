#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	unsigned char fnd[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xd8, 0x80, 0x90};
	//unsigned char digit, fnd_position=0x01;
	unsigned char sw=0;
	int i=0, j=0, k=0, m=0;
	DDRB=0xFF;
	DDRD=0xFF;
	DDRE = 0x00;

	PORTB=0xFF;
	PORTD=0xFF;
	while(1)
	{
		if((PINE&0x01) == 0x00) sw=1;
		else if((PINE&0x02) == 0x00) sw=2;

		for(int h = 0; h < 2; h++){
			PORTB=fnd[i];
			PORTD=0x08; //왼쪽에서 첫번째 FND 지정
			_delay_ms(1);
			PORTB=fnd[j];
			PORTD=0x04; //두번째 FND 지정
			_delay_ms(1);
			PORTB=fnd[k];
			PORTD=0x02; //세번째 FND 지정
			_delay_ms(1);
			PORTB=fnd[m];
			PORTD=0x01; //네번째 FND 지정
			_delay_ms(1);
		}
		
		if(sw == 1){
			m++;
			if(m > 9){
				m=0;
				k++;
				if(k > 9){
					k = 0;
					j++;
					if(j > 9){
						j = 0;
						i++;
						if(i > 9){
							i = 0;
						}
					}
				}
			}
		}
		
		else if(sw == 2){
			m--;
			if(m < 0){
				m=9;
				k--;
				if(k < 0){
					k = 9;
					j--;
					if(j < 0){
						j = 9;
						i--;
						if(i < 0){
							i = 9;
						}
					}
				}
			}
		}	
	}
}