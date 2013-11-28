#ifndef PUBSUB_H_
#define PUBSUB_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define MSGSZ 128

class message_buf{
public:
	long mtype;
	char mtext[MSGSZ];
};

int initTransfer(key_t);

bool publish(int, char*);

bool subscribe(int, char*, int);

bool endTransfer(int);

#endif
