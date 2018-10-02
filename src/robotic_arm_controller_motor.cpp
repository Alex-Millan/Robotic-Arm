/*

 */ 

#include <iostream>
#include <wiringPi.h>
#include "robotic_arm_controller_motor.h"


#include "GPIO.h"
#include "Motor.h"
#include "keyboard_input.h"
#include "Stepper.h"

using namespace std;


#define SUCCESS 0
#define FAILURE 1

#define GREETING_MESSAGE "Get Ready for Robotic Movement!"

#define MOTOR_CLAW_PIN_1 1
#define MOTOR_CLAW_PIN_2 0
#define MOTOR_WRIST_PIN_1 2
#define MOTOR_WRIST_PIN_2 3
#define MOTOR_ELBOW_PIN_1 4
#define MOTOR_ELBOW_PIN_2 5


#define MOTOR_STEPPER_IN1 22
#define MOTOR_STEPPER_IN2 23
#define MOTOR_STEPPER_IN3 24
#define MOTOR_STEPPER_IN4 25

#define PWM_PULSE	1024

#define TIME_DELAY 20		

#define CONTROL_KEY_1	'w'
#define CONTROL_KEY_2	'e'
#define CONTROL_KEY_3	's'
#define CONTROL_KEY_4	'd'
#define CONTROL_KEY_5	'x'
#define CONTROL_KEY_6	'c'
#define CONTROL_KEY_7	'j'
#define CONTROL_KEY_8	'k'



Motor claw(MOTOR_CLAW_PIN_1, MOTOR_CLAW_PIN_2);
Motor wrist(MOTOR_WRIST_PIN_1, MOTOR_WRIST_PIN_2);
Motor elbow(MOTOR_ELBOW_PIN_1, MOTOR_ELBOW_PIN_2);
Stepper base(MOTOR_STEPPER_IN1,MOTOR_STEPPER_IN2,
			MOTOR_STEPPER_IN3,MOTOR_STEPPER_IN4);
			


int main() {
	cout << GREETING_MESSAGE << endl;
	
	cout << "Entering Motor Controls" << endl;

	turn_off();
	while(1) {
		controller();
	}
	
	return SUCCESS;
}



void controller() {
		int command = getInput();
		switch(command){
			case CONTROL_KEY_1:
				claw.forward();
				break;
			case CONTROL_KEY_2:
				claw.backward();
				break;
			case CONTROL_KEY_3:
				wrist.forward();
				break;
			case CONTROL_KEY_4:
				wrist.backward();
				break;
			case CONTROL_KEY_5:
				elbow.forward();
				break;
			case CONTROL_KEY_6:
				elbow.backward();
				break;
			case CONTROL_KEY_7:
				base.forward();
				break;
			case CONTROL_KEY_8:
				base.backward();
				break;
			default:
			cout << "Expected " << CONTROL_KEY_1 << CONTROL_KEY_2 <<
			CONTROL_KEY_3 << CONTROL_KEY_4 << " but got: " << command << endl;
		}
		delay(TIME_DELAY);
		turn_off();
		
}

/* Future stepper motor class
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


Future stepper motor class*/

void turn_off(){
	GPIO_digitalLow(MOTOR_CLAW_PIN_1);
	GPIO_digitalLow(MOTOR_CLAW_PIN_2);	
	
	GPIO_digitalLow(MOTOR_WRIST_PIN_1);
	GPIO_digitalLow(MOTOR_WRIST_PIN_2);
		
	GPIO_digitalLow(MOTOR_ELBOW_PIN_1);
	GPIO_digitalLow(MOTOR_ELBOW_PIN_2);
	delay(TIME_DELAY);
}


