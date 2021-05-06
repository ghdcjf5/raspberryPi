#include <stdio.h>
#include <wiringPi.h>
#include <mqueue.h>

mqd_t mfd;


int redled_pin = 0;
int greenled_pin = 2;
int blackled_pin = 4;
int whiteled_pin = 5;
int yellowled_pin = 1;
int button_pin = 3;
int servo_pin = 24;
volatile int led_state =0;
//volatile int led_state_changed =0;
volatile int r_led=0;
volatile int g_led=0;
volatile int b_led=0;

void buttonPressed(void){
	
	struct mq_attr attr = {
		.mq_maxmsg=10,
		.mq_msgsize =4,
		
	};
	
	//구조체를 만들어줘야한다. 
	
	
	if (led_state==0){
		led_state=1;
		r_led=1;
	}
	
	else if (led_state == 1){
		led_state=2;
		g_led=1;
	}
	
	else if (led_state == 2){
		led_state=3;
		b_led=1;
	}
	
	
	else if (led_state == 3){
		led_state=0;
		r_led = 0;
		g_led = 0;
		b_led = 0;
	}
	
	
	//led_state_changed = 1;
	
	mq_send(mfd,(char *)&led_state,attr.mq_msgsize,1); 
	//1은 우선순위 
	

	
}








PI_THREAD(t1){
	

	while(1){
		
		digitalWrite(whiteled_pin,HIGH);
		delay(600);
		digitalWrite(whiteled_pin,LOW);
		delay(600);
		
	}
	
	
}


PI_THREAD(t2){
	
	int cnt;
	
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




PI_THREAD(asd){
	
	
	
	
	while(1){
		
		
		char keyboardInput = getchar();
		int cng;
			if(keyboardInput=='q'){
		
			cng=1000;
		
			}
	
			else if(keyboardInput=='w'){
		
			cng=1500;
		
			}
	
	
			else if(keyboardInput=='e'){
		
			cng =2000;
		
			}
	
	pwmWrite(servo_pin,cng);
	}

	
	

}










int main(void){
	
	//wiringsetup->pinmode->setrange순으로 코딩
	
	wiringPiSetup();
	
	pinMode(redled_pin,OUTPUT);
	pinMode(greenled_pin,OUTPUT);
	pinMode(blackled_pin,OUTPUT);
	pinMode(whiteled_pin,OUTPUT);
	pinMode(yellowled_pin,PWM_OUTPUT);
	pinMode(servo_pin,PWM_OUTPUT);
	pinMode(button_pin,INPUT);
	
	pwmSetClock(19);
	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(20000);
	
	piThreadCreate(t1);
	piThreadCreate(t2);
	piThreadCreate(asd);
	
	
	struct mq_attr attr = {
		
		.mq_maxmsg =10,
		.mq_msgsize = 4,
	};
	
	mq_unlink("/msg_q");
	mfd = mq_open("/msg_q",O_RDWR|O_CREAT,0666,&attr);
	
	if(mfd == -1){
		perror("open error");
		return -1;
		
		
	}
	
	
	
	wiringPiISR(button_pin,INT_EDGE_RISING,buttonPressed);
	
	
	
	
	
	while(1){
		
		
		mq_receive(mfd,(char*)&led_state,attr.mq_msgsize,NULL);
		
		
		digitalWrite(redled_pin,r_led);
		digitalWrite(greenled_pin,g_led);
		digitalWrite(blackled_pin,b_led);
	}	
		
		
	
	
	
	
	
}
//gcc challange500.c -o challange500 -lwiringPi -lrt 해줘야함

