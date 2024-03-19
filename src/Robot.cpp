#include "Robot.h"
#include "motor.h"
#include "arduino.h"

bool programRunning = false;


int robotInit() {
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(SW3, INPUT);
	pinMode(SW2, INPUT);
	pinMode(SW1, INPUT);

	MotorInit();
	EncoderInit();

	static bool releaseFlag = true;

	while (!programRunning) {
		if (!digitalRead(SW3)) {
			releaseFlag = false;
			delay(20);
		}

		if (!releaseFlag) {
			if (digitalRead(SW3)) {
				programRunning = true;
			}
		}
	}
}


int forward(int pwr) {
	if (!programRunning) {
		return -1;
	}
	else {
		if (pwr < 0) {
			pwr = -pwr;
		}

		MotorR(pwr);
		MotorL(pwr);
	}
	return 0;
}

int backward(int pwr) {
	if (!programRunning) {
		return -1;
	}
	else {
		if (pwr < 0) {
			pwr = -pwr;
		}

		MotorL(-pwr);
		MotorR(-pwr);
	}
	return 0;
}

int setMotors(int rtPwr, int lftPwr) {
	if (!programRunning) {
		return -1;
	}
	else {
		MotorR(rtPwr);
		MotorL(lftPwr);
	}
	return 0;
}

int stop() {
	if (!programRunning) {
		return -1;
	}
	else {
		MotorR(0);
		MotorL(0);
	}
}