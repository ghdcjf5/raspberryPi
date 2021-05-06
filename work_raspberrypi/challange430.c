#include <stdio.h>
#include <wiringPi.h>

int redled_pin =0;
int greenled_pin =2;
int yellowled_pin =1;
int servo_pin = 24;





PI_THREAD(t1){
	
	while(1){
		digitalWrite(greenled_pin,HIGH);
		delay(600);
		digitalWrite(greenled_pin,LOW);
		delay(600);
	
	}
	
}

PI_THREAD(t2){
	int cnt=0;
	
	
	
	while(1){
		
		for (cnt=0;cnt<=1024;cnt++){
			
			pwmWrite(yellowled_pin,cnt);
			delay(1);
			
			
		}
		
			for (cnt=1024;cnt>=0;cnt--){
			
			pwmWrite(yellowled_pin,cnt);
			delay(1);
			
			
		}
		
	}
	
	
	
	
	
	
	
	
}



PI_THREAD(t3){
	
	int cnt1;
	
	
	
	while(1){
		
		for(cnt1=1000;cnt1<=2000;cnt1++){
		
			pwmWrite(servo_pin,cnt1);
			delay(1);
		
		}
		
		for(cnt1=2000;cnt1>=1000;cnt1--){
			
			pwmWrite(servo_pin,cnt1);
			delay(1);
		}
		
		
	}
	
	
	//pwmWrite(servo_pin,0);
	
}









int main(void){
	
	wiringPiSetup();
	pinMode(redled_pin,OUTPUT);
	
	pinMode(greenled_pin,OUTPUT);
	
	pinMode(yellowled_pin,PWM_OUTPUT);

	pinMode(servo_pin,PWM_OUTPUT);
	
	
	pwmSetMode(PWM_MODE_MS);
	
	pwmSetClock(19);
	pwmSetRange(20000);  //servo를 돌리려면 20000이상의 range를 줘야한다.
	
	
	
	piThreadCreate(t1);
	piThreadCreate(t2);
	piThreadCreate(t3);
	
	
	
	
	while(1){
		
		digitalWrite(redled_pin,HIGH);
		delay(300);
		digitalWrite(redled_pin,LOW);
		delay(300);
		
		
	}
}