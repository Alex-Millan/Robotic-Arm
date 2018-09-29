#pragma once
#include <wiringPi.h>

#define EMPTY -1

		
		void GPIO_init();
		void GPIO_setup(int GPIO_Out, int GPIO_Input = EMPTY);
		void GPIO_digitalHigh(int pin);
		void GPIO_digitalLow(int pin);
				void GPIO_PWN_setup(int GPIO_Out, int GPIO_Inpu= EMPTY);
		
		void GPIO_pwmWrite(int physPin, int value);
