#ifndef __SONAR_H
#define __SONAR_H

#define ECHO1 56
#define TRIG1 48

#define ECHO2 58
#define TRIG2 6

#define ECHO3 57
#define TRIG3 45

#define TIMEOUT 3000


extern int SonarTime;

enum sonarPorts{
	SONAR1,
	SONAR2,
	SONAR3
};

/********************SonarInit*********************/
/*************************************
** Function Name: SonarInit
** Description: Initializes Sonar 
** Input parameters: port (SONAR1, SONAR2, SONAR3)
** Output paramenters: none
** Return Values: none
********************************************/
extern int SonarInit(int port);

/********************SonarDist*********************/
/*************************************
** Function Name: SonarDist
** Description: Determines the distance from sonar to obstacle.
** Input parameters: port (SONAR1, SONAR2, SONAR3)
** Output paramenters: none
** Return Values: Distance
********************************************/
extern float SonarDist(int port);

#endif
