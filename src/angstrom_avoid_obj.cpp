/*
 * I2CServoDriver.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: kartik
 */

#include <iostream>
#include "Hexapod.h"
#include "SlaveDevice.h"
#include "arm.h"


using namespace std;


int main(){
/*	int8_t I2CAddress = 0x04, I2CBus = 2;
	SlaveDevice slave;
	Hexapod *robot = new Hexapod();
	int sensorValue_us = 0;
	char *buffer = new char;
	while(true){
		slave.reveal(I2CBus, I2CAddress, 2, buffer);
		sensorValue_us = 256 * (int)buffer[1] + (int) buffer[0];
//		sensorValue_ir = 256 * (int)buffer[3] + (int) buffer[2];
		cout << sensorValue_us << endl;
		if (sensorValue_us < 30)
			robot->turn(3);
		else
			robot->walkFwd(1);
	}
	delete buffer;
	delete robot;*/
	arm gripper;
	float pos_grab[3] = {60, 20, -75};
	gripper.goto_XYZ(pos_grab, true);
	float pos_leave[3] = {80, -20, 10};
	gripper.goto_XYZ(pos_leave, false);
	return 0;
}
