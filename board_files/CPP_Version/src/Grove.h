/*
 * Grove.h
 *
 *  Created on: Dec 17, 2013
 *      Author: Mike Lewis (mikelewis@alphalem.com)
 */

#ifndef GROVE_H_
#define GROVE_H_


#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>

#include "SlaveDevice.h"

#define MAX_BUS 64

/* GROVE CONSTANTS */
#define DEFAULT_ADDR 0x28

// Registers
#define PWM_REG			0x28
#define FREQ_REG		0x84
#define CHG_ADDR_REG	0x83
#define CHANNEL_SET_REG	0xAA
#define M1_SPEED		0xA1
#define M2_SPEED		0xA5

class Grove {

private:
	int8_t I2CAddress;
	int I2CBus;
	SlaveDevice slave;
	int8_t readI2CByte(int8_t);
	bool writeI2CByte(int8_t, int8_t);

public:
	Grove(int);
	Grove(int, int8_t);

	void setPWMAB(int8_t, int8_t);
	void setFreq(int8_t);
	void changeAddr(int8_t, char);
	void setM1Speed(int8_t, int8_t);
	void setM2Speed(int8_t, int8_t);

	~Grove();
};

#endif /* GROVE_H_ */
