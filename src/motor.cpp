#include "motor.h"
#include "arduino.h"

volatile float CounterR = 0;
volatile float LastCounterR = 0;
volatile float CounterL = 0;
volatile float LastCounterL = 0;


#define MAX_PWR 255

int MotorInit() {
	/**MotorR Pin Set**/
	pinMode(RMTR_FWD, OUTPUT);
	pinMode(RMTR_BWD, OUTPUT);
	/**MotorL Pin Set**/
	pinMode(LMTR_FWD, OUTPUT);
	pinMode(LMTR_BWD, OUTPUT);

	return 0;
}



int MotorR(int pwr){
	/**Catches if power values are greater than max value**/
	if (pwr > MAX_PWR) {
		pwr = MAX_PWR;
	}
	else if (pwr < -MAX_PWR) {
		pwr = -MAX_PWR;
	}


	/**Sets the motor to the proper power and direction**/
	if (pwr > 0) {
		analogWrite(RMTR_FWD, pwr);
		analogWrite(RMTR_BWD, 0);
	}
	else if (pwr < 0) {
		analogWrite(RMTR_FWD, 0);
		analogWrite(RMTR_BWD, -pwr);
	}
	else {
		analogWrite(RMTR_FWD, 0);
		analogWrite(RMTR_BWD, 0);
	}
}

int MotorR(int pwr) {
	/**Catches if power values are greater than max value**/
	if (pwr > MAX_PWR) {
		pwr = MAX_PWR;
	}
	else if (pwr < -MAX_PWR) {
		pwr = -MAX_PWR;
	}


	/**Sets the motor to the proper power and direction**/
	if (pwr > 0) {
		analogWrite(LMTR_FWD, pwr);
		analogWrite(LMTR_BWD, 0);
	}
	else if (pwr < 0) {
		analogWrite(LMTR_FWD, 0);
		analogWrite(LMTR_BWD, -pwr);
	}
	else {
		analogWrite(LMTR_FWD, 0);
		analogWrite(LMTR_BWD, 0);
	}
}


int EncoderInit() {
	/**Right Encoder Pin Setup
	** Interrupt prevents encoder from continually counting up. **/
	pinMode(RENC_FWD, INPUT);
	pinMode(RENC_BWD, INPUT);
	attachInterrupt(2, RtEncodeFWD, CHANGE);
	attachInterrupt(3, RtEncodeBWD, CHANGE);

	/**Right Encoder Pin Setup
	** Interrupt prevents encoder from continually counting up. **/
	pinMode(LENC_FWD, INPUT);
	pinMode(LENC_BWD, INPUT);
	attachInterrupt(0, LftEncodeFWD, CHANGE);
	attachInterrupt(1, LftEncodeBWD, CHANGE);
	return 0;
}

void RtEncodeFWD() {
	if (digitalRead(RENC_FWD) == HIGH) {
		RtFWD_Set = true;
		if (!RtBWD_Set) {
			CounterR = CounterR + 1;
		}
	}

	if (digitalRead(RENC_FWD) == LOW) {
		RtFWD_Set = false;
	}
}

void RtEncodeBWD() {
	if (digitalRead(RENC_BWD) == HIGH) {
		RtBWD_Set = true;
		if (!RtFWD_Set) {
			CounterR = CounterR - 1;
		}
	}

	if (digitalRead(RENC_BWD) == LOW) {
		RtBWD_Set = false;
	}
}

void LftEncodeFWD() {
	if (digitalRead(LENC_FWD) == HIGH) {
		LftFWD_Set = true;
		if (!LftBWD_Set) {
			CounterL = CounterL + 1;
		}
	}

	if (digitalRead(LENC_FWD) == LOW) {
		LftFWD_Set = false;
	}
}

void LftEncodeBWD() {
	if (digitalRead(LENC_BWD) == HIGH) {
		LftBWD_Set = true;
		if (!LftFWD_Set) {
			CounterL = CounterL - 1;
		}
	}

	if (digitalRead(LENC_BWD) == LOW) {
		LftBWD_Set = false;
	}
}
