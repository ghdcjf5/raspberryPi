#include <stdio.h>
#include <wiringPi.h>

int redled_pin = 0;
int greenled_pin = 2;
int blueled_pin = 4;



PI_THREAD(t1){
	while(1){
		
		digitalWrite(greenled_pin,HIGH);
		delay(650);
		digitalWrite(greenled_pin,LOW);
		delay(650);
		
		
		
		
	}
	
	
	
}



PI_THREAD(t2){
	while(1){
		
		digitalWrite(blueled_pin,HIGH);
		delay(850);
		digitalWrite(blueled_pin,LOW);
		delay(850);
		
		
		
		
	}
	
	
	
}






int main(void){
	
	
	wiringPiSetup();
	
	pinMode(redled_pin,OUTPUT);
	pinMode(greenled_pin,OUTPUT);
	pinMode(blueled_pin,OUTPUT); // blue=yellow?
	
	
	piThreadCreate(t1);
	
	piThreadCreate(t2);
	
	while(1){
		
		digitalWrite(redled_pin,HIGH);
		delay(350);
		digitalWrite(redled_pin,LOW);
		delay(350);
		
		
	}
	
	
	
	
}