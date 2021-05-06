#include <stdio.h>
#include <wiringPi.h>

int main(void){
	
	int servo_pin =24;
	
	
	wiringPiSetup();
	
	pinMode(servo_pin,PWM_OUTPUT);
	
	pwmSetClock(19);
	pwmSetMode(PWM_MODE_MS);
	
	pwmSetRange(20000);
	
	
	
	while(1){
		
	char keyboardInput = getchar();
		
		
	if(keyboardInput=='q'){
		pwmWrite(servo_pin,1000);
		
	}	
			
	else if(keyboardInput=='w'){
		pwmWrite(servo_pin,1500);
		
	}	
	
	
	else if(keyboardInput=='e'){
		pwmWrite(servo_pin,2000);
		
	}	
	
	

		
	}
	

	
}