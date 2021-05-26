#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
//  PC7 PC6 PC5 PC4 PC3 PC2 PC1 PC0
//  DB7 DB6 DB5 DB4          E   RW  RS

//void COMMAND(unsigned char byte);
//void DATA(unsigned char byte);
//void LCD_INIT(void);

//void COMMAND(unsigned char byte);
//void DATA(unsigned char byte);
//void LCD_INIT(void);

void STRING(unsigned char font[], unsigned char n)
{
	unsigned char i;
	for(i=0;i<n;i++)
	{
		DATA(font[i]);
	}
}

void MOVE(int y, int x)     //커서 이동
{
	unsigned char data;
	if(y==1) 	data=0x80+x-1;           //1행
	else     	data=0xc0+x-1;            //2행
	COMMAND(data);
}

void COMMAND(unsigned char byte)	// 명령어 함수
{
	_delay_ms(2);

	PORTC = byte&0xf0;		// 명령어 쓰기
	PORTC &= 0b11111110;		// RS = 0 명령어선택 설정
	PORTC &= 0b11111101;		// RW = 0 쓰기 설정
	_delay_us(1);           		// RS & RW setup time 40ns 지연
	PORTC |= 0b00000100;		// E = 1, lcd 동작
	_delay_us(1);          		// E pulse width time 230ns 지연
	PORTC &= 0b11111011;		// E = 0

	PORTC = (byte<<4)&0xf0;	// 명령어 쓰기
	PORTC &= 0b11111110;		// RS = 0 명령어선택 설정
	PORTC &= 0b11111101;		// RW = 0 쓰기 설정
	_delay_us(1);           		// RS & RW setup time 40ns 지연
	PORTC |= 0b00000100;		// E = 1, lcd 동작
	_delay_us(1);          		// E pulse width time 230ns 지연
	PORTC &= 0b11111011;		// E = 0
}

void LCD_INIT(void)			// 초기설정 함수
{
	_delay_ms(30);		// 전원 투입 후 30ms 이상 지연
	
	//Function set
	COMMAND(0b00101000);	// 인터페이스(DL)=0(4bit), 라인(N)=1(2라인), 폰트(F)=0(5*8 dot)	_delay_us(39);		// 39us 이상 지연

	//Display ON/OFF Control
	COMMAND(0b00001100);	// 화면 표시(D)=1(on), 커서(C)=0(off), 블링크(B)=0(off)	_delay_us(39);		// 39us 이상 지연

	//Clear Display
	COMMAND(0b00000001);	// 화면을 클리어하고 , 커서가 홈위치인 0번지로 돌아감.
	_delay_ms(1.53);		// 1.53ms 이상 지연

	//Entry Mode Set
	COMMAND(0b00000110);	// 커서방향(I/D)=1(address증가), 표시이동(S)=0(이동하지 않음)
}

void DATA(unsigned char byte)		// 데이터 함수x`
{
	_delay_ms(2);

	PORTC = byte&0xf0;		// 데이터 쓰기
	PORTC |= 0b00000001;		// RS = 1, 데이터를 쓰도록 설정
	PORTC &= 0b11111101;		// RW = 0, 데이터를 쓰도록 설정
	_delay_us(1);           		// RS & RW setup time 40ns 지연
	PORTC |= 0b00000100;		// E = 1, lcd 동작
	_delay_us(1);          		// E pulse width time 230ns 지연
	PORTC &= 0b11111011;		// E = 0

	PORTC = (byte<<4)&0xf0;	// 데이터 쓰기
	PORTC |= 0b00000001;		// RS = 1, 데이터를 쓰도록 설정
	PORTC &= 0b11111101;		// RW = 0, 데이터를 쓰도록 설정
	_delay_us(1);           		// RS & RW setup time 40ns 지연
	PORTC |= 0b00000100;		// E = 1, lcd 동작
	_delay_us(1);          		// E pulse width time 230ns 지연
	PORTC &= 0b11111011;		// E = 0
}

int main(void)
{
	
	unsigned int SEC=0,MIN=0,HOUR=0;
	unsigned char Title[]="             TIME";
	unsigned char Time[]="00:00:00";

	DDRC = 0xff;
	PORTC = 0x00;

	LCD_INIT();
	
	MOVE(1,1);
	STRING(Title,17);
	MOVE(2,5);
	STRING(Time,8);
	while(1)
	{
		MOVE(2,5);
		DATA(HOUR/10+0x30);		//시의 10자리
		DATA(HOUR%10+0x30);		//시의 1자리
		MOVE(2,8);
		DATA(MIN/10+0x30);		//분의 10자리
		DATA(MIN%10+0x30);		//분의 1자리
		MOVE(2,11);
		DATA(SEC/10+0x30);		//초의 10자리
		DATA(SEC%10+0x30);		//초의 1자리
		_delay_ms(1000);

		SEC++;
		if(SEC==60)	SEC=0, MIN++;
		if(MIN==60) MIN=0, HOUR++;
		if(HOUR==24) HOUR=0;
	}
	
}