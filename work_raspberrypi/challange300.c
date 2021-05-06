#include <stdio.h>
#include <wiringPi.h>

volatile int led_state=0;
volatile int led_state_changed=0;
volatile int led1=LOW;
volatile int led2=LOW;
volatile int led3=LOW;

	
	int redled_pin=0;
	int greenled_pin=2;
	int blueled_pin=4;
	int servo_pin=24;
	int button_pin=3;

	

	
	
	
void buttonPressed(void){  //isr에서 딜레이는 들어가면 안된다. 멈추는 개념이 아니어서(데이터를 받는 루틴) digitalWrite도 넣어도도



	

	
	if(led_state==0){
		led_state=1;
		led1=HIGH;
		led2=LOW;
		led3=LOW;
	}
	
	else if(led_state==1){
		led_state=2;
		//led2=HIGH;
		led1=HIGH;
		led2=HIGH;
		led3=LOW;
	}
	
	else if(led_state==2){
		led_state=3;
		//led3=HIGH;
		led1=HIGH;
		led2=HIGH;
		led3=HIGH;
	}
	
	else if(led_state==3){
		led_state=0;
		led1=LOW;
		led2=LOW;
		led3=LOW;
	}
	

	
	led_state_changed=1;
	
	
	
	if(led_state_changed==1){
			led_state_changed=0;
			//digitalWrite(led_pin[cnt],led_state);
			
			digitalWrite(redled_pin,led1);
			digitalWrite(greenled_pin,led2);
			digitalWrite(blueled_pin,led3);
	}		

	

		
	
	

	

}


	
	
	
	
	

	
	







int main(void){

	
	
	
	
	wiringPiSetup();
	
	pinMode(redled_pin,OUTPUT);
	pinMode(greenled_pin,OUTPUT);
	pinMode(blueled_pin,OUTPUT);
	pinMode(button_pin,INPUT);
	
	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(20000);
	pwmSetClock(19);
	
	wiringPiISR(button_pin,INT_EDGE_RISING,buttonPressed);
	
	
	//int led_pin[]={redled_pin,greenled_pin,blueled_pin};
	//int cnt=0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	while(1){
		
		char keyboardInput=getchar();  //blocking 함수다. 입력을 기다려야 해서 
		
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