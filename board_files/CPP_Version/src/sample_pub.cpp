#include "pubsub.h"
#include "Serial.h"
#include <iostream>

using namespace std;
//int msqid = 0;
bool setup() {
/*	msqid = initTransfer(1234);
        if(msqid == 0)
                return false;*/
        return true;
}

char dist[1];
bool loop() {
	if (!kbhit()) {
		dist[0] = (char) 10;
		return publish(dist, 1);
	}
	else{
		endTransfer();
//		delete dist;
		return false;
	}
}
