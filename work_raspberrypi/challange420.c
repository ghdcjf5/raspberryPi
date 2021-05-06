#include <stdio.h>
#include <wiringPi.h>


int redled_pin = 1;  
int greenled_pin = 24;  //pwm핀이 정해져있으므로 임의로 변경 x

volatile int cnt1=0;
volatile int cnt=0;

PI_THREAD(t1){
	pwmSetClock(19);
	pwmSetRange(650);  
	
	pwmSetMode(PWM_MODE_MS);
	
	while(1){
	for (cnt=0;cnt<=650;cnt1++){
			
			pwmWrite(greenled_pin,cnt1);
			delay(1);
			 //for 문이 돌아가는데 1ms걸리는것이니 650ms걸리면 다켜지고
			 //650ms가 걸리면 다꺼지는것
			 //즉 밝기의 절대치는 고정되있는것이다.
		
			
		}
	
		for (cnt=650;cnt>=0;cnt1--){
			pwmWrite(greenled_pin,cnt1);
			delay(1);
			
		}

	
	
	}
	
	
	
	
	
}









int main(void){
	
	wiringPiSetup();
	
	pinMode(redled_pin,PWM_OUTPUT);
	pinMode(greenled_pin,PWM_OUTPUT);
	
	pwmSetMode(PWM_MODE_MS);
	
	
	
	
	piThreadCreate(t1);
	
	
	
	
		
	pwmSetRange(350);
	pwmSetClock(19);
	
	
	
	while(1){

		for (cnt=0;cnt<=350;cnt++){
			
			pwmWrite(redled_pin,cnt);
			delay(1);
			
		
			
		}
	
		for (cnt=350;cnt>=0;cnt--){
			pwmWrite(redled_pin,cnt);
			delay(1);
			
		}

	





		
		
		
	}
	
	
	
	
}