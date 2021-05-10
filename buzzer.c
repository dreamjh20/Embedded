#include <wiringPi.h>
#include <softTone.h>

#define SPKR  6
#define TOTAL 32

int notes[] = {
	391, 391, 440, 440, 391, 391, 329.63, 329.63,
	391, 391, 329.63,329.63, 293.66, 293.66, 293.66, 0,
	391, 391, 440, 440, 391, 391, 329.63, 329.63,
	391, 329.63, 293.66, 329.63, 261.63, 261.63, 261.63, 0
};

int Play(){
	int i;

	softToneCreate(SPKR);
	
	for(int i = 0; i < TOTAL; i++){
		softToneWrite(SPKR, notes[i]);
		delay(280);
	}
	
	return 0;
}

int main(){
	while(1){
		wiringPiSetup();
		Play();
	}
	return 0;
}
