#include <motor.h>
#include <arduino.h>

#DEFINE LMtrFwd 10
#DEFINE LMtrBwd 5
#DEFINE RMtrFwd 8
#DEFINE RMtrBwd 9


/*
 * MotorR
 * This function is used to control the right motor
 * speed is the speed of the motor
 * speed > 0 is forward
 * speed < 0 is backward
 * speed = 0 is stop
*/
void MotorR(int speed){
  if(speed > 0){
	analogWrite(RMtrFwd, speed);
	analogWrite(RMtrBwd, 0);
  }else if(speed < 0){
	analogWrite(RMtrFwd, 0);
	analogWrite(RMtrBwd, speed);
  }else{
	analogWrite(RMtrFwd, 0);
	analogWrite(RMtrBwd, 0);
  }
}

/*
 * MotorL
 * This function is used to control the left motor
 * speed is the speed of the motor
 * speed > 0 is forward
 * speed < 0 is backward
 * speed = 0 is stop
*/
void MotorL(int speed){
  if(speed > 0){
	analogWrite(LMtrFwd, speed);
	analogWrite(LMtrBwd, 0);
  }else if(speed < 0){
	analogWrite(LMtrFwd, 0);
	analogWrite(LMtrBwd, speed);
  }else{
	analogWrite(LMtrFwd, 0);
	analogWrite(LMtrBwd, 0);
  }
}

