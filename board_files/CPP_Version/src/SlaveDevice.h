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
	int file;
	bool beginCommunication(int8_t, int8_t);

public:
	bool reveal(int8_t, int8_t, int, char*);
	bool accept(int8_t, int8_t, char[], int);
	bool endCommunication();
};



#endif /* SLAVEDEVICE_H_ */
