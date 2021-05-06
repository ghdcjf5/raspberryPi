#include <stdio.h>
#include <wiringPi.h>

/*
volatile int led_state=LOW;
volatile int led_state_changed = 0;
void keyboardPressed(void){
	
	led_state = (led_state == LOW) ? HIGH : LOW;
	led_state_changed =1;
}
*/





int main(void){
	
	int led = LOW  ;
	int led_pin= 0;	
	
	wiringPiSetup();
	
	pinMode(led_pin,OUTPUT);
	
	
		
		
	
	
	
	
	while(1){
		
		
		char userInput = getchar();
		
		if (userInput == 'n'){
		led = HIGH;
		
		}
	else if(userInput == 'f'){
		led = LOW;
		
		}
	
	digitalWrite(led_pin,led);
		
	}
	
	
	
	
	
}