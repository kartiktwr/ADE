/*
 * I2CArduino.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: kartik
 */

#include <iostream>
#include "SlaveDevice.h"

using namespace std;


int main(){
	int8_t I2CAddress = 0x04, I2CBus = 2;
	int data[2];
	char *buffer = new char;
	SlaveDevice slave;
	for(int i = 0; i < 30; i++){
		slave.reveal(I2CBus, I2CAddress, 4, buffer);
		data[0] = 256 * (int)buffer[1] + (int) buffer[0];
		data[1] = 256 * (int)buffer[3] + (int) buffer[2];
		cout << data[0] << " " << data[1] << endl;
	}
	delete buffer;
//	delete slave;
	return 0;
}
