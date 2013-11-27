/*
 * I2CServoDriver.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: kartik
 */

#include <iostream>
//#include "rangeFinder.h"
#include "Hexapod.h"
#include <unistd.h>

using namespace std;


int main(){
	Hexapod *robot = new Hexapod();
	while(true)
		robot -> walkFwd(100);
/*	robot -> reliefStep();
	float pos[3] = {2.0, 5.0, 0.0};
	robot -> move_single_leg(1, pos);
	pos[0] = 1.0;
	pos[1] = 6.0;
	sleep(1);
	robot -> move_single_leg(1, pos);*/
//	delete robot;
/*	rangeFinder *device = new rangeFinder(true);
	while(true){
		cout << device -> dist() << endl;
		usleep(50 * 1000);
	}
	delete device;*/
	return 0;
}
