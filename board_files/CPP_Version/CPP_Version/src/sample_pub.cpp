#include "rangeFinder.h"
#include "pubsub.h"
#include "Serial.h"

rangeFinder device(true);

int msqid = 0;
bool setup() {
	msqid = initTransfer(1234);
        if(msqid == 0)
                return false;
        return true;
}


bool loop() {
	char *dist = new char;
	if (!kbhit()) {
		dist[0] = device.dist();
		usleep(500 * 1000);
		return publish(msqid, dist);
	}
	else{
		endTransfer(msqid);
		delete dist;
		return false;
	}
}
