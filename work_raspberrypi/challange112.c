#include <stdio.h>
#include <wiringPi.h>

int main (void){
	
	int led_pin =1;
	
	int led = 0;
	
	wiringPiSetup();
	
	pinMode(led_pin,PWM_OUTPUT);
	
	while(1){
		
		char keyboardInput = getchar();
		
		if(keyboardInput=='0'){
			led = 0;
			
		}
		
		
		else if(keyboardInput=='5'){
			led = 512;
			
		}
		
		
		else if(keyboardInput=='t'){
			led = 1024;
			
		}
		
		
		
		pwmWrite(led_pin,led);
		
	}
	
	
	
	
	
	
	
	
	
	
}