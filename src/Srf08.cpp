/*
 * Srf08.cpp
 *
 *  Created on: Oct 8, 2013
 *      Author: Mike Lewis (mikelewis@alphalem.com) 
 *	Derived from: AdafruitServoDriver.cpp by Kartik Tiwari
 */

#include "Srf08.h"

using namespace std;

Srf08 :: Srf08(int i2cBus) {
	_i2cAddr = 0xE0;
	_i2cBus = i2cBus;
}

Srf08 :: Srf08(int8_t i2caddr, int i2cBus) {
	_i2cAddr = i2caddr;
	_i2cBus = i2cBus;
}

/*
 * Initiates a ranging session of 65mS (default). Result can be saved in the
 * following units: inches, centimeters, or micro-seconds.
 */
void Srf08 :: startRanging(int8_t units) {
	int file;
	// Command Register: location 0
	int8_t startAddr = 0;
	char buffer[2];

	buffer[0] = startAddr;
	buffer[1] = units;
	slave.accept(_i2cBus, _i2cAddr, buffer, 2);
}


Srf08 :: ~Srf08(){

}
