#include <stdio.h>
#include <wiringPi.h>


volatile int buzzer_state = 0;
volatile int buzzer_state_changed=0;
volatile int cnt =0;


void buttonPressed(void){

cnt++;

	if(cnt==1){	
		if (buzzer_state == 0){
			buzzer_state =262;
		
		}
	
		else if (buzzer_state ==262){
			buzzer_state =294;
		
		}
	
		else if (buzzer_state ==294){
			buzzer_state =330;
		
		}
		else if (buzzer_state ==330){
			buzzer_state =349;
		
		
		
		
		}
	
	
		else if (buzzer_state ==349){
			buzzer_state =392;
		
		
		
		
		}
	
		else if (buzzer_state ==392){
			buzzer_state =440;
		
		}
	
	
		else if (buzzer_state ==440){
			buzzer_state =494;
			
		}
	
		else if (buzzer_state ==494){
			buzzer_state =523;
		
		}
		else if (buzzer_state ==523){
			buzzer_state =262;
		
		}
	
	buzzer_state_changed=1;
	
	
	}

	
	
	
	else{
	cnt=0;
	
	}
	
}




int main(void){
	
	int buzzer_pin = 24;
	int button_pin = 3;
	
	
	pinMode(buzzer_pin,PWM_OUTPUT);
	pinMode(button_pin,INPUT);
	
	
	wiringPiSetup();
	
	
	pwmSetClock(19);
	
	pwmSetMode(PWM_MODE_MS);
	
	
	
	
	
	wiringPiISR(button_pin,INT_EDGE_RISING,buttonPressed);
	
	while(1){
		
	
		if(buzzer_state_changed==1){
			
			buzzer_state_changed=0;
			cnt=0;
		pwmSetRange(1000000/buzzer_state);		
		pwmWrite(buzzer_pin, buzzer_state/2  );
		delay(500);
		
		pwmWrite(buzzer_pin,0);
			
		}
		
	
		
		
	
		
		
		
		
		
		
	
		
	}
	
	
	
	
	
}