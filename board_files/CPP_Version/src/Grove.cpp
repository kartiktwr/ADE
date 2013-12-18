/*
 * Grove.cpp
 *
 *  Created on: Dec 17, 2013
 *      Author: Mike Lewis (mikelewis@alphalem.com)
 *
 *	Datasheet: https://secure.robotshop.com/media/files/pdf/datasheet-rob72212p.pdf
 */

#include "Grove.h"
#include <iostream>

using namespace std;

Grove :: Grove(int i2cBus) {
	I2CAddress = DEFAULT_ADDR;
	I2CBus = i2cBus;
	slave.init_device(I2CBus, I2CAddress);
}

Grove :: Grove(int i2cBus, int8_t i2caddr) {
	I2CAddress = i2caddr;
	I2CBus = i2cBus;
	slave.init_device(I2CBus,I2CAddress);
}

// Set motor speeds for both A & B at the same time
// NOTE: Grove expects 2 values directly following the function address byte
// i.e. 0x28 > 0x82 > 255 > 255
void setPWMAB(int8_t speedA, int8_t speedB) {
	writeI2CByte(PWM_REG, speedA);
	writeI2CByte(PWM_REG, speedB);
}

// Sets frequency given a prescaler
void setFreq(int8_t prescaler) {
	writeI2CByte(FREQ_REG, prescaler);
	writeI2CByte(FREQ_REG, 0);
}

// Changes the device's address
// save should be an 'S' or 'N' char
void changeAddr(int8_t newAddr, char save) {
	writeI2CByte(CHG_ADDR_REG, newAddr);
	writeI2CByte(CHG_ADDR_REG, save);	
}

// Sets Motor 1's rotation direction (1/2) and speed (0-255)
void setM1Speed(int8_t rot, int8_t speed) {
	writeI2CByte(M1_SPEED, rot);
	writeI2CByte(M1_SPEED, speed);
}

// Sets Motor 2's rotation direction (1/2) and speed (0-255)
void setM2Speed(int8_t rot, int8_t speed) {
	writeI2CByte(M2_SPEED, rot);
	writeI2CByte(M2_SPEED, speed);
}

int8_t Grove :: readI2CByte(int8_t addr) {
	char buffer[1];
	if (slave.reveal(addr, 1, buffer)) {
		return (int8_t)buffer[0];
	}
	return (int8_t)0;
}

bool Grove :: writeI2CByte(int8_t regAddr, int8_t value) {
	char buffer[2];
	buffer[0] = (char)regAddr;
	buffer[1] = (char)value;
	return slave.accept(buffer, 2);
}

Grove :: ~Grove() {
}
