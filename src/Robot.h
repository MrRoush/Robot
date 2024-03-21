#ifndef __ROBOT_H
#define __ROBOT_H


#include "arduino.h"
#include "motor.h"
#include "TimerOne.h"
#include "Sonar.h"

#define SW1 35
#define SW2 36
#define SW3	37

#define LED1 13
#define LED2 12

extern bool programRunning;

/********************robotInit*********************/
/*************************************
** Function Name: robotInit
** Description: Initialized Robot Commands and Sensors
** Input parameters: none
** Output paramenters: none
** Return Values: none
********************************************/
extern int robotInit();

/********************forward()*********************/
/*************************************
** Function Name: forward()
** Description: Applies power to both motors to make robot go forward.
** Input parameters: power (0-255)
** Output paramenters: none
** Return Values: none
********************************************/
extern int forward(int pwr);

/********************backward()*********************/
/*************************************
** Function Name: backward()
** Description: Applies power to both motors to make robot go backwards.
** Input parameters: power (0-255)
** Output paramenters: none
** Return Values: none
********************************************/
extern int backward(int pwr);

/********************setMotors()*********************/
/*************************************
** Function Name: setMotors()
** Description: Sets the power of the right and left motors to fine turn movements.
** Input parameters: rtpwr (-255 - 255), lftpwer (-255-255)
** Output paramenters: none
** Return Values: none
********************************************/
extern int setMotors(int rtPwr, int lftPwr);

/********************stop()*********************/
/*************************************
** Function Name: stop()
** Description: Stops all power going to motors.
** Input parameters: none
** Output paramenters: none
** Return Values: none
********************************************/
extern int stop();


/********************getDist()*********************/
/*************************************
** Function Name: getDist()
** Description: Gets the distance in centimeters from a specific Sonar.
** Input parameters: int port (SONAR1, SONAR2, SONAR3)
** Output paramenters: none
** Return Values: distance in centimeters.
********************************************/
extern float getDist(int port);

/********************detectBarrier()*********************/
/*************************************
** Function Name: detectBarrier()
** Description: Detects if a barrier is in range of the robot.
** Input parameters: int port (SONAR1, SONAR2, SONAR3), int dist (cm)
** Output paramenters: none
** Return Values: True/False
********************************************/
extern bool detectBarrier(int port, int dist);

#endif