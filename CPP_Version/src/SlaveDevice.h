/*
 * SlaveDevice.h
 *
 *  Created on: Aug 20, 2013
 *      Author: kartik
 */

#ifndef SLAVEDEVICE_H_
#define SLAVEDEVICE_H_

#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <unistd.h>


#define MAX_BUS 64

using namespace std;


class SlaveDevice{
private:
//	int8_t I2CBus;
//	int8_t I2CAddress;
	int file;
	void beginCommunication(int8_t, int8_t);

public:
//	SlaveDevice(int8_t, int8_t);
	void reveal(int8_t, int8_t, int, char*);
	void accept(int8_t, int8_t, char[], int);
	void endCommunication();
//	~SlaveDevice();
};



#endif /* SLAVEDEVICE_H_ */
