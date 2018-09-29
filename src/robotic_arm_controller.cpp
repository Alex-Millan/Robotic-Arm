/*

 */ 

#include <iostream>
#include <wiringPi.h>
#include "robotic_arm_controller.h"


#include "GPIO.h"
#include "keyboard_input.h"

using namespace std;


#define SUCCESS 0
#define FAILURE 1

#define LED_GPIO_PIN 1
#define GREETING_MESSAGE "Get Ready for Robotic Movement!"
#define DEFAULT_MESSAGE "Expected \'a\' or \'b\' but got: "

#define GPIO_W 1
#define GPIO_A 26
#define GPIO_S 23
#define GPIO_D 24

#define GPIO_PWM_IN1 1
#define GPIO_PWM_IN2 26
#define GPIO_PWM_IN3 23
#define GPIO_PWM_IN4 24
#define PWM_PULSE	1024

#define TIME_DELAY 5



static int step_counter = 0;

int main() {
	cout << GREETING_MESSAGE << endl;
	GPIO_init();
	
	
	
		
	GPIO_setup(GPIO_W);
	GPIO_setup(GPIO_A);
	GPIO_setup(GPIO_S);
	GPIO_setup(GPIO_D);	
	


	cout << "Entering Motor Controls" << endl;

	turn_off();

		step_counter = 0;
	while(1) {
		controller();
		step_counter++;
		cout << endl << "Revolution Count: " << step_counter << endl;
	}
	
	return SUCCESS;
}

void controller() {
		int command = getInput();
		static int off_counter = 0;
		switch(command){
			case 'w':
				half_step();
				break;
			case 'a':
				step_counter = 0;
				break;
			case 's':
				turn_off();
				break;
			case 'd':
				full_step();
				break;
			default:
			cout << "Expected \'a\' or \'b\' but got " << command << endl;
		}
		off_counter++;
		if(off_counter > 4){
			GPIO_pwmWrite(GPIO_PWM_IN1, 0);
			GPIO_digitalLow(GPIO_A);
			GPIO_digitalLow(GPIO_S);
			GPIO_digitalLow(GPIO_D);
			off_counter = 0;
		}	 
		
}


void setStep(int a, int b, int c, int d){
	if(a){
		GPIO_digitalHigh(GPIO_PWM_IN1);
	} else {
		GPIO_digitalLow(GPIO_PWM_IN1);
	}
	if(b){
		GPIO_digitalHigh(GPIO_PWM_IN2);
	} else {
		GPIO_digitalLow(GPIO_PWM_IN2);
	}
	
	if(c){
		GPIO_digitalHigh(GPIO_PWM_IN3);
	} else {
		GPIO_digitalLow(GPIO_PWM_IN3);
	}
	
	if(d){
		GPIO_digitalHigh(GPIO_PWM_IN4);
	} else {
		GPIO_digitalLow(GPIO_PWM_IN4);
	}

	delay(TIME_DELAY);
	}
	
void full_step(){
	setStep(1, 0, 0, 0);
	setStep(0, 1, 0, 0);
	setStep(0, 0, 1, 0);
	setStep(0, 0, 0, 1);
	turn_off();
}

void half_step(){
	
	setStep(1, 0, 0, 0);
	setStep(1, 1, 0, 0);
	setStep(0, 1, 0, 0);
	setStep(0, 1, 1, 0);
	setStep(0, 0, 1, 0);
	setStep(0, 0, 1, 1);
	setStep(0, 0, 0, 1);
	setStep(1, 0, 0, 1);
	turn_off();
}

void turn_off(){
	GPIO_digitalLow(GPIO_PWM_IN1);
	GPIO_digitalLow(GPIO_PWM_IN2);	
	GPIO_digitalLow(GPIO_PWM_IN3);
	GPIO_digitalLow(GPIO_PWM_IN4);
	delay(TIME_DELAY);
}


