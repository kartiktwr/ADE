//#include "Hexapod.h"
#include <iostream>
#include "Serial.h"
#include "pubsub.h"

using namespace std;

int msqid = 0;

bool setup() {
//	Hexapod robot();
	int msqid = initTransfer(1234);
	if(msqid == 0)
		return false;
	return true;
}


bool loop() {
	char *data = new char;
	if(!kbhit()){
		bool flag = subscribe(msqid, data, 1);
		cout << (int)data;
		return flag;
	}
	else{
		endTransfer(msqid);
		delete data;
		return false;
	}
}
