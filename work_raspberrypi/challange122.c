#include <stdio.h>
#include <wiringPi.h>

volatile int led_state = 0;
volatile int led_state_changed =0;

void buttonPressed(void){
	if (led_state==0){
		led_state = 512; 
	}
	else if(led_state == 512){
		led_state=1024;
		
	}
	else if(led_state == 1024){
		led_state=0;
	}
	
	led_state_changed =1;
	
	
}







int main(void){
	
	int led_pin = 1;
int button_pin = 3;

wiringPiSetup();

pinMode(led_pin,PWM_OUTPUT);
pinMode(button_pin,INPUT);



wiringPiISR(button_pin,INT_EDGE_RISING,buttonPressed);


	
	
	
	while(1){
		
		
		if (led_state_changed==1){
			led_state_changed=0;
			
			
			pwmWrite(led_pin,led_state);
			
		}
		
		
		
	}
	
	
	
	
}