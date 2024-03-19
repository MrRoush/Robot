#ifndef __MOTOR_H	
#define __MOTOR_H

#define RMTR_BWD 5		//Right Motor Backward 
#define RMTR_FWD 10		//Right Motor Forward

#define LMTR_BWD 8		//Left Motor Backward
#define LMTR_FWD 9		//Left Motor Forward

#define RENC_FWD 20		//Right Encoder Forward
#define RENC_BWD 21		//Right Encoder Backward

#define LENC_FWD 3		//Left Encoder Forward
#define LENC_BWD 2		//Left Encoder Backward

extern volatile float CounterR;
extern volatile float LastCounterR;

extern volatile float CounterL;
extern volatile float LastCounterL;



/********************MotorInit*********************/
/*************************************
** Function Name: MotorInit
** Description: Initialized Motor Commands 
** Input parameters: none
** Output paramenters: none
** Return Values: none 
********************************************/
extern int MotorInit();


/********************MotorR*********************/
/*************************************
** Function Name: MotorR
** Description: Turns on the right motor in a given direction
** Input parameters: pwr (Power Value)
** Output paramenters: none
** Return Values: none
********************************************/
extern int MotorR(int pwr);

/********************MotorL*********************/
/*************************************
** Function Name: MotorL
** Description: Turns on the left motor in a given direction
** Input parameters: pwr (Power Value)
** Output paramenters: none
** Return Values: none
********************************************/
extern int MotorL(int pwr);


/********************EncoderInit*********************/
/*************************************
** Function Name: EncoderInit
** Description: Initializes the encoders on the motors 
** Input parameters: none
** Output paramenters: none
** Return Values: none
********************************************/
extern int EncoderInit();


#endif




