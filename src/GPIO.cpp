#include "GPIO.h"
#include <iostream>

#include <softPwm.h>
using namespace std;



		void GPIO_init() {
			wiringPiSetup();
		}
		
		void GPIO_setup(int GPIO_Out, int GPIO_Input){
			pinMode(GPIO_Out, OUTPUT);
			cout << GPIO_Out << " is on!" << endl;	

			if(GPIO_Input != EMPTY) {
				pinMode(GPIO_Input, INPUT);
	
			}
		}
		
		void GPIO_PWN_setup(int GPIO_Out, int GPIO_Input) {


			cout << GPIO_Out << " is on!" << endl;
			softPwmCreate(GPIO_Out, 0, 1025);
			
		}
		
		void GPIO_pwmWrite(int physPin, int value) {
			softPwmWrite(physPin, value);
		
		}
		
		
		void GPIO_digitalHigh(int pin){
			digitalWrite(pin, HIGH);
		}
		
		void GPIO_digitalLow(int pin){
			digitalWrite(pin, LOW);
		}
		
