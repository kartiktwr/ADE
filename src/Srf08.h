/*
 * Srf08.h
 *
 *  Created on: Oct 8, 2013
 *      Author: Mike Lewis (mikelewis@alphalem.com)
 *	Derived from: AdaFruitServoDriver.h by Kartik Tiwari
 */

#ifndef SRF08_H_
#define SRF08_H_


#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <iostream>

#include "SlaveDevice.h"

#define RESULT_IN 0x50 // Decimal: 80
#define RESULT_CM 0x51 // Decimal: 81 
#define RESULT_MS 0x52 // Decimal: 82 

class Srf08 {

private:
	int8_t _i2cAddr;
	int _i2cBus;
	SlaveDevice slave;

public:
	Srf08(int);
	Srf08(int8_t, int);
	void startRanging(int8_t);
	~Srf08();
};

#endif /* SRF08_H_ */
