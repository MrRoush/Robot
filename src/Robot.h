#indef __ROBOT_H
#define __ROBOT_H


#include "arduino.h"
#include "motor.h"
#include "TimerOne.h"

#define SW1 35
#define SW2 36
#define SW3	37

#define LED1 13
#define LED2 12

extern bool programRunning;

extern int robotInit();
extern int forward(int pwr);
extern int backward(int pwr);
extern int setMotors(int rtPwr, int lftPwr);
extern int stop();

#endif