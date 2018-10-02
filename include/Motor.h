#pragma once
#include <wiringPi.h>


class Motor {
	public:
		Motor();
		Motor(int my_pin_clock_wise, int my_pin_counter_clock_wise);
		void forward();
		void backward();
		void setupPins(int pin1, int pin2);
	private:
		int pin_clock_wise;
		int pin_counter_clock_wise;
};
