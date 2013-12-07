#include "pubsub.h"
#include "Serial.h"
#include <iostream>

using namespace std;
int msqid = 0;
bool setup() {
	msqid = initTransfer(1234);
	cout << msqid << endl;
        if(msqid == 0)
                return false;
        return true;
}

char *dist = new char;
bool loop() {
	if (!kbhit()) {
		dist[0] = (char)10;
		return publish(msqid, dist, 1);
	}
	else{
		endTransfer(msqid);
		delete dist;
		return false;
	}
}
