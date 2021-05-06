#include <stdio.h>
#include <wiringPi.h>





void showMenu(){
	
	printf("==<<MENU>>==\n");
	printf("n. 빨간색 LED 켜기\n");
	printf("f. 빨간색 LED 끄기\n");
	printf("0. 파란색 LED 밝기 0%\n");
	printf("5. 파란색 LED 밝기 50%\n");
	printf("t. 파란색 LED 밝기 100%\n");
	printf("q. servo 180도\n");
	printf("w. servo 90도\n");
	printf("e. servo 0도\n");
	
}

int main(){
	
	int redled_pin=0;
	int blueled_pin=1;
	int servo_pin = 24;
	
	pinMode(redled_pin,OUTPUT);
	pinMode(blueled_pin,PWM_OUTPUT);
	pinMode(servo_pin,PWM_OUTPUT);
	
	wiringPiSetup();
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(19);
	pwmSetRange(20000);
	
	
	showMenu();
	while(1){
		char userInput = getchar();
		
		if(userInput=='n'){
			digitalWrite(redled_pin,HIGH);
			
		}
		
		else if(userInput=='f'){
			digitalWrite(redled_pin,LOW);
			
		}
		
		else if(userInput=='0'){
			pwmWrite(blueled_pin,0);
			
		}
		
		else if(userInput=='5'){
			pwmWrite(blueled_pin,512);
			
		}
		
		else if(userInput=='t'){
			pwmWrite(blueled_pin,1024);
			
		}
		
		else if(userInput=='q'){
			pwmWrite(servo_pin,2000);
			
		}
		else if(userInput=='w'){
			pwmWrite(servo_pin,1500);
			
		}
		
		
		else if(userInput=='e'){
			pwmWrite(servo_pin,1000);
			
		}
		
	}
	
	
	
}







