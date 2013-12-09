#include "pubsub.h"
#include "Serial.h"
#include <iostream>

using namespace std;
int msqid = 0;
bool setup() {
	key_t key = 1234;
	msqid = initTransfer(key);
        if(msqid == 0)
                return false;
        return true;
}

char dist[1];
bool loop() {
	if (!kbhit()) {
		dist[0] = (char) 10;
		return publish(msqid, dist, 1);
	}
	else{
		endTransfer(msqid);
		return false;
	}
}
