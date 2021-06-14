#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define MAXTIMINGS 85
#define DHTPIN 7

int dht_dat[5]={0, 0, 0, 0, 0};

void read_dht_dat(){
	uint8_t laststate = HIGH;
	uint8_t counter = 0;
	uint8_t j = 0, i;
	float f;

	dht_dat[0] = dht_dat[1] = dht_dat[2] = dht_dat[3] = dht_dat[4] = 0;

	pinMode(DHTPIN, OUTPUT);
	digitalWrite(DHTPIN, LOW);
	delay(18);
	digitalWrite(DHTPIN, HIGH);
	delayMicroseconds(40);
	pinMode(DHTPIN, INPUT);
	for( i = 0; i < MAXTIMINGS; i++){
		counter = 0;
		while(digitalRead(DHTPIN) == laststate) {
			counter++;
			delayMicroseconds(1);
			if (counter == 255){
				break;
			}
		}
		laststate = digitalRead(DHTPIN);

		if (counter == 255)
			break;
		if((i >= 4) && (i % 2 == 0)){
			dht_dat[j/8] <<= 1;
			if(counter >32)
				dht_dat[j/8] |=1;
			j++;
			
		}
	}
	if((j>=40) && (dht_dat[4] == (dht_dat[0] + dht_dat[1] + dht_dat[2] + dht_dat[3]) & 0xFF)){
		f = dht_dat[2] * 9. /5. + 32;
		printf( "Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",dht_dat[0], dht_dat[1], dht_dat[2], dht_dat[3], f);
	}
	else{
		printf("Data not good, skip\n");
	}
}


int main(void){
	printf("Welcome\n");
	printf("Test\n");
	if(wiringPiSetup() == -1)
		exit(1);
	while(1){
		read_dht_dat();
		delay(1000);
	}
	return 0;
}
