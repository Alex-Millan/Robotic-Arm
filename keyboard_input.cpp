#include <iostream>
#include <stdio.h>

#include <unistd.h>
#include <termios.h>


using namespace std;


//getch was provide by https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
int getch(){
	int buf = 0;
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
	cout << "Enter a command:" << endl;
	
	while(1) {
	int input = getch();
	cout << "You Pressed: " << input << ":" << endl;
	}
	return 0;
	
	}
	
