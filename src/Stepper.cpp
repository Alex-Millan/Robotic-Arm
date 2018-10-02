#include "Stepper.h"
#include <wiringPi.h>
#include <iostream>

using namespace std;

Stepper::Stepper(int IN1, int IN2, int IN3, int IN4) {
		A = IN1;
		B = IN2;
		C = IN3;
		D = IN4;
		
		wiringPiSetup();
		pinMode(A, OUTPUT);
		pinMode(B, OUTPUT);
		pinMode(C, OUTPUT);
		pinMode(D, OUTPUT);
	}
	
void Stepper::forward() {
		cout << "Stepping forward with pins: " << A << " " << 
		B <<  " " << C << " " << D << endl;
		step(A, D);
		step(B, A);
		step(C, B);
		step(D, C);
		digitalWrite(D, LOW);
	}
void Stepper::backward() {
		cout << "Stepping backwards with pins: " << A << " " << 
		B <<  " " << C << " " << D << endl;
		step(D, A);
		step(C, D);
		step(B, C);
		step(A, B);
		digitalWrite(A, LOW);
	}
	
	
	
	
	
	
void Stepper::step(int nextStep, int prevStep) {
		digitalWrite(nextStep, HIGH);
		digitalWrite(prevStep, LOW);
		delay(STEP_DELAY);
	
	}
	
