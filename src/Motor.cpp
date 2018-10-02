#include "Motor.h"
#include <wiringPi.h>
#include <iostream>

using namespace std;

Motor::Motor(){
		cout << "Basic Motor called" << endl;
	}
Motor::Motor(int my_pin_clock_wise, int my_pin_counter_clock_wise){
	
		cout << "Motor initalizing for pins" << my_pin_clock_wise
		<< "and" << my_pin_counter_clock_wise << endl;
		
		setupPins(my_pin_clock_wise, my_pin_counter_clock_wise);
		Motor::pin_clock_wise = my_pin_clock_wise;
		Motor::pin_counter_clock_wise = my_pin_counter_clock_wise;
		
	}
void Motor::setupPins(int pin1, int pin2){
		static int first_setup = 1;
		if(first_setup) {
			wiringPiSetup();
			first_setup = 0;
			cout << "wiringPi initalized!" << endl;
		}
		pinMode(pin1, OUTPUT);
		pinMode(pin2, OUTPUT);
	}
void Motor::forward(){
		digitalWrite(pin_clock_wise, HIGH);
		cout << "Motor Forward called: " << pin_clock_wise <<endl;
	}

void Motor::backward(){
		digitalWrite(pin_counter_clock_wise, HIGH);
		
		cout << "Motor backwards called: " << pin_counter_clock_wise << endl;
	}
