
#include <iostream>
#include <wiringPi.h>

//View RaspPi Pin reference for GPIO pin connections
#define LED_GPIO_PIN 1


using namespace std;

int main(int argc, char *argv[]) {
	wiringPiSetup();
	pinMode(LED_GPIO_PIN, OUTPUT);
	int i;
	for(i = 0; i < 20; i++) {
			
		cout << "Blinking GPIO PIN " << LED_GPIO_PIN << ". . ."<< endl;
		digitalWrite(LED_GPIO_PIN, HIGH);
		delay(250);
		digitalWrite(LED_GPIO_PIN, LOW);
		delay(250);

	}
	
	
	cout << "done" << endl;
	return 0;
}
