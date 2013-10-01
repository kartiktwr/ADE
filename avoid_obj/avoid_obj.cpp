/*
 * I2CServoDriver.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: kartik
 */

#include <iostream>
#include "Hexapod.h"
#include "SlaveDevice.h"

#define THRESH 3

using namespace std;


int main(){
	int8_t I2CAddress = 0x04, I2CBus = 2;
	SlaveDevice slave;
	Hexapod *robot = new Hexapod();
	int dir = 1;
	int curDist, prevDist = 0;
	char *buffer = new char;
	while(true){
		slave.reveal(I2CBus, I2CAddress, 2, buffer);
		curDist = 256 * (int)buffer[1] + (int) buffer[0];
		cout << curDist << endl;
		if (curDist > 150 && curDist < 350){
			if (prevDist > curDist){
				dir = -1;
			}
			robot-> turn(1 * dir);
		}
		else if (curDist > 351){
			robot->walkFwd(-1);
		}
		else {
			robot->walkFwd(1);
		}
		dir = 1;
		prevDist = curDist;
		usleep(100 * 1000);
	}
	delete buffer;
	delete robot;
	return 0;
}
