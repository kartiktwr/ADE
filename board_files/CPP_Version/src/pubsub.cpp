#include "pubsub.h"
key_t key = 1234;
int initTransfer(key_t key) {
	int msqid = 0;                                                              
	int msgflg = IPC_CREAT | IPC_EXCL | 0666;                                          
	if ((msqid = msgget(key, msgflg)) < 0) {
		msqid = msgget(key, 0666);
	}
	return msqid;
}

bool publish(char* data, int len) {
	int msqid = 0;
        int msgflg = IPC_CREAT | IPC_EXCL | 0666;
        if ((msqid = msgget(key, msgflg)) < 0) {
                msqid = msgget(key, 0666);
        }

	message_buf sbuf;
	size_t buf_length;
	
	sbuf.mtype = 1;
	for(int i = 0; i < len; i++)
		sbuf.mtext[i] = data[i];
	buf_length = len;    
	if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
		printf ("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
		perror("msgsnd");
		return false;
	}

	return true;
}

bool subscribe(char* data, int len) {
	int msqid = 0;
        int msgflg = IPC_CREAT | IPC_EXCL | 0666;
        if ((msqid = msgget(key, msgflg)) < 0) {
                msqid = msgget(key, 0666);
        }

	message_buf rbuf;

	if (msgrcv(msqid, &rbuf, MSGSZ, 1, 0) < 0) {
		perror("msgrcv");
		return false;
	}
	for(int i = 0; i < len; i++)
		data[i] = rbuf.mtext[i];
	return true;
}

bool endTransfer() {
	int msqid = 0;                              
        int msgflg = IPC_CREAT | IPC_EXCL | 0666;   
        if ((msqid = msgget(key, msgflg)) < 0) {    
                msqid = msgget(key, 0666);          
        }  
	if ((msgctl(msqid, IPC_RMID, NULL)) < 0) {   
                perror("msgctl");                
                return false;                                  
        }
	return true;
}
