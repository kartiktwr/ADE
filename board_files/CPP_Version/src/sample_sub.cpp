#include <iostream>
#include "Serial.h"
#include "pubsub.h"

using namespace std;

int msqid = 0;

bool setup() {
	key_t key = 1234;
	int msqid = initTransfer(key);
	if(msqid == 0)
		return false;
	return true;
}

char data[1];
bool loop() {
//	if(!kbhit()){
		bool flag = subscribe(msqid, data, 1);
		cout << (int)data[0] << endl;
		return flag;
/*	}
	else{
		endTransfer(msqid);
		return false;
	}*/
}
