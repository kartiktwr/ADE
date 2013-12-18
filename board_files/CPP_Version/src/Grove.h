/*
 * Grove.h
 *
 *  Created on: Dec 17, 2013
 *      Author: Mike Lewis (mikelewis@alphalem.com)
 */

#ifndef Grove_H_
#define Grove_H_


#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>

#include "SlaveDevice.h"

#define MAX_BUS 64

/* Grove CONSTANTS */

// Write mode
#define COMMAND_REG 0x00
#define MAX_GAIN_REG 0x01
#define RANGE_REG 0x02

// Read mode
#define LIGHT 0x01
#define ECHO_1_HI 0x02
#define ECHO_1_LO 0x03
#define ECHO_2_HI 0x04
#define ECHO_2_LO 0x05
#define ECHO_3_HI 0x06
#define ECHO_3_LO 0x07
#define ECHO_4_HI 0x08
#define ECHO_4_LO 0x09

#define DEFAULT_ADDR 0xE0

class Grove {

private:
	int8_t I2CAddress;
	int I2CBus;
	SlaveDevice slave;
	initRanging(int8_t units);
	int8_t readI2CByte(int8_t);
	bool writeI2CByte(int8_t, int8_t);

public:
	Grove(int);
	Grove(int, int8_t);
	int8_t* getRange();
	int8_t getLight();
	~Grove();
};

#endif /* Grove_H_ */
