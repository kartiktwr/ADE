#include <iostream>
#include "Serial.h"
#include "pubsub.h"

using namespace std;

int msqid = 0;

bool setup() {
	int msqid = initTransfer(1234);
	cout << msqid << endl;
	if(msqid == 0)
		return false;
	return true;
}

char *data = new char;
bool loop() {
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
