#include <iostream>
#include "Serial.h"
#include "pubsub.h"

using namespace std;

//int msqid = 0;

bool setup() {
/*	int msqid = initTransfer(1234);
	if(msqid == 0)
		return false;*/
	return true;
}

char data[1];
bool loop() {
//	if(!kbhit()){
		bool flag = subscribe(data, 1);
		cout << (int)data[0] << endl;
		return flag;
//	}
/*	else{
		endTransfer(msqid);
		delete data;
		return false;
	}*/
}
