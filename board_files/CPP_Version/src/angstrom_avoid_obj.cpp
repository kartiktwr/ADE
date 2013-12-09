/*
 * I2CServoDriver.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: kartik
 */

#include <iostream>
#include "Hexapod.h"
#include "Serial.h"

using namespace std;

Hexapod robot;
bool setup() {
	robot.Hexapod_init();
	return true;
}

bool loop(){
	if(kbhit()){
		char ch = getchar();
		switch (ch){
		case 'w':
			robot.walkFwd(1);
//			cout << 65;
			return true;
		case 's':
			robot.walkFwd(-1);
//			cout << 66;
			return true;
		case 'a':
			robot.walkSide(1);
//			cout << 67;
			return true;
		case 'd':
			robot.walkSide(-1);
//			cout << 68;
			return true;
		case 'c':
			robot.reliefStep();
//			delete robot;
			return false;
		}
	}
	return true;
}

