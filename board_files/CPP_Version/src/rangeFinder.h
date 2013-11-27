#ifndef RANGEFINDER_H_
#include "SlaveDevice.h"
#include <iostream>

#define I2CBus 2
#define I2CAddress 0x70

class rangeFinder{
private:
	float range;
	SlaveDevice slave;
public:
	rangeFinder(bool);
	float dist();
	~rangeFinder();
};

#endif
