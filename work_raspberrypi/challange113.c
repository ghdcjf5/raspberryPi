#include <stdio.h>
#include <wiringPi.h>

int main (void){
	
	int buzzer_pin = 24;
	int buzzer=0;
	
	
	wiringPiSetup();
	
	pinMode(buzzer_pin,PWM_OUTPUT);
	
	pwmSetClock(19);
	pwmSetMode(PWM_MODE_MS);
	
	
	
	while(1){
		
	char keyboardInput = getchar();	
		
	int melody[] = {262,294,330,349,392,440,494,523};
	
	
	int note;
	
	if(keyboardInput=='a'){
		
		note=0;
		
	}
	
	else if(keyboardInput=='s'){
		note=1;
		
	}
	
	else if(keyboardInput=='d'){
		note=2;
		
	}
	
	else if(keyboardInput=='f'){
		
		note=3;
	}
	
	else if(keyboardInput=='g'){
		note=4;
		
	}
	
	
	else if(keyboardInput=='h'){
		note=5;
		
	}
	
	else if(keyboardInput=='j'){
		
		note=6;
	}
	
	
	else if(keyboardInput=='k'){
		
		note=7;
	}
		
	pwmSetRange(1000000/melody[note]);
	pwmWrite(buzzer_pin,1000000/melody[note]/2);
	delay(500);
	
	pwmWrite(buzzer_pin,0);
		
		
		
		
	}
	
}