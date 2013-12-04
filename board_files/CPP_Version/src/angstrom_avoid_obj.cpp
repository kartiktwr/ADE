/*
 * I2CServoDriver.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: kartik
 */

#include <iostream>
#include "Hexapod.h"
#include <unistd.h>

using namespace std;


bool kick_the_mug(){
	Hexapod *robot = new Hexapod();
	sleep(7);
	robot -> walkFwd(5);
	usleep(500 * 1000);
	robot -> turn(-5);
	robot -> reliefStep();
	float pos[3] = {2.0, 3.5, 0.0}; 
	robot -> move_single_leg(6, pos);
	pos[0] += 2.5;
	pos[1] += 2.5;
	usleep(500 * 1000);
	robot -> move_single_leg(6, pos);
	usleep(500 * 1000);
	robot -> stand_pos(-4.0);
	delete robot;
	return true;
}

int main() {
	// For proper vengeance
	kick_the mug();
	return 0;
}


