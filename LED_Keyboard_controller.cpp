/*
 * Turning ON and OFF an LED with keyboard inputs
 * Pressing 'a' followed by the enter will turn ON an LED
 * Pressing 'b' followed by the enter will turn OFF an LED 
 * 
 * 
 */ 

#include <iostream>
#include <wiringPi.h>

#include <unistd.h>
#include <termios.h>

using namespace std;


#define SUCCESS 0
#define FAILURE 1

#define LED_GPIO_PIN 1
#define GREETING_MESSAGE "Type 'a' to turn LED on and 's'  to turn LED off"

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
	char userInput = ' ';
	cin >> userInput;
	return userInput;
	}
	
	//getch was provide by https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
char getch(){
	char buf = 0;
	struct termios old = {0};
	if(tcgetattr(0, &old) < 0) {
			perror("tcsetattr()");
		}
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if(tcsetattr(0, TCSANOW, &old) < 0 ) {
		perror("tcsetattr ICANON");
	} if(read(0, &buf, 1) < 0) {
			perror("read()");
		}
		old.c_lflag |= ICANON;
		old.c_lflag |= ECHO;
		if(tcsetattr(0, TCSADRAIN, &old) < 0)  {
				perror("tcsetattr ~ICANON");
			} 
		return (buf);
	
	}

int main() {
	GPIO_Setup();
	cout << GREETING_MESSAGE << endl;
	
	while(1) {
		char command = getch();
		switch(command){
			case 'a':
				LED_ON();
				break;
			case 's':
				LED_OFF();
				break;
			default:
			cout << "Expected \'a\' or \'b\' but got " << command << endl;
		}	
			
	}
	
	return SUCCESS;
}
