#pragma once


#define STEP_DELAY 10

class Stepper{
		public:
			Stepper(int IN1, int IN2, int IN3, int IN4);
			void forward();
			void backward();
	
		private:
			int A, B, C, D;
			void step(int nextStep, int prevStep);
};
