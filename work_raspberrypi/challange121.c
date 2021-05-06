#include <stdio.h>
#include <wiringPi.h>

volatile int led_state = LOW;
volatile int led_state_changed=0;

void buttonPressed(void){
	if (led_state==LOW){
		led_state=HIGH;
	}
	else {
		led_state=LOW;
		
	}
	led_state_changed = 1;
	
	
	
}



int main(void){
	
	int	button_pin = 3;
	int led_pin = 0;
	
	wiringPiSetup();
	
	
	pinMode(led_pin,OUTPUT);
	pinMode(button_pin,INPUT);
	
	wiringPiISR(button_pin,INT_EDGE_RISING,buttonPressed);
	
	while(1){
	
	if (led_state_changed==1){
		led_state_changed=0;
	}
		
	
		
	
		digitalWrite(led_pin,led_state);
		
		
		
	}
	
	
	
}


