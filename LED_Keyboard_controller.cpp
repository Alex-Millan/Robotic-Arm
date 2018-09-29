/*
 * Turning ON and OFF an LED with keyboard inputs
 * Pressing 'a' followed by the enter will turn ON an LED
 * Pressing 'b' followed by the enter will turn OFF an LED 
 * 
 * 
 */ 

#include <iostream>
#include <wiringPi.h>

using namespace std;


#define SUCCESS 0
#define FAILURE 1

#define LED_GPIO_PIN 1
#define GREETING_MESSAGE "Type 'a' + enter to turn LED on and 'b' + enter to turn LED off"

int GPIO_Setup(){
	wiringPiSetup();
	pinMode(LED_GPIO_PIN, OUTPUT);
	return SUCCESS;
}

void LED_ON() {
	digitalWrite(LED_GPIO_PIN, HIGH);
	cout << "LED ON!" << endl;

}
void LED_OFF() {
	digitalWrite(LED_GPIO_PIN, LOW);
	cout << "LED OFF!" << endl;
}

char keyboard_input(){
	char userInput = ' ';a
	cin >> userInput;
	return userInput;
	}

int main() {
	GPIO_Setup();
	cout << GREETING_MESSAGE << endl;
	
	while(1) {
		char command = keyboard_input();
		switch(command){
			case 'a':
				LED_ON();
				break;
			case 'b':
				LED_OFF();
				break;
			default:
			cout << "Expected \'a\' or \'b\' but got " << command << endl;
		}	
			
	}
	
	return SUCCESS;
}
