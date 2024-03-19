#incldue <Robot.h>
#include <motor.h>
#include <arduino.h>

bool programRunning = false;


void initRobot() {
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(PINSW3, INPUT);
	pinMode(PINSW2, INPUT);
	pinMode(PINSW1, INPUT);


	while (!programRunning) {
		if (!digitalRead(START_PIN)) {
			delay(20);
		}
	}

}




