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
int main(){
	Hexapod *robot = new Hexapod();
	bool flag = true;
	while(flag){
	if(kbhit()){
		char ch = getchar();
		switch (ch){
		case 65:
			robot->walkFwd(1);
			cout << 65;
			break;
		case 66:
			robot->walkFwd(-1);
			cout << 66;
			break;
		case 67:
			robot->walkSide(1);
			cout << 67;
			break;
		case 68:
			robot->walkSide(-1);
			cout << 68;
			break;
		case 27:
			delete robot;
			cout << "hi";
			flag = false;
		}
	}
	}
	return 0;
}


