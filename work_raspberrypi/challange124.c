#include <stdio.h>
#include <wiringPi.h>



volatile int servo_state=0;
volatile int servo_state_changed = 0;



void buttonPressed(void){
	
	
	if (servo_state==0){
		servo_state=1000;
		
	}
	
	else if(servo_state==1000){
		servo_state=1500;
		
	}
	
	
	else if(servo_state==1500){
		servo_state=2000;
		
	}
	
	
	else if(servo_state==2000){
		servo_state=0;
		
	}
	
	servo_state_changed=1;
	
	
	
}






int main(void){
	
int servo_pin=24;
int button_pin=3;

wiringPiSetup();

pinMode(button_pin,INPUT);
pinMode(servo_pin,PWM_OUTPUT);


pwmSetClock(19);
pwmSetMode(PWM_MODE_MS);
pwmSetRange(20000);

wiringPiISR(button_pin,INT_EDGE_RISING,buttonPressed);
	while(1){
	
	
		if (servo_state_changed==1){
		
			servo_state_changed=0;
			pwmWrite(button_pin, servo_state);
		
		}
		
	
	
	}


	
	
}