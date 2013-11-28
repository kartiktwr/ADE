#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include "rangeFinder.h"

#define MSGSZ     128


/*
 * Declare the message structure.
 */

class message_buf {
public:
         long mtype;
         char mtext[MSGSZ];
         };

int main()
{	
    rangeFinder device(true);
    int msqid;
    int msgflg = 0666;
    key_t key;
    message_buf sbuf;
    size_t buf_length;

    /*
     * Get the message queue id for the
     * "name" 1234, which was created by
     * the server.
     */
    key = 1234;

    if ((msqid = msgget(key, msgflg)) < 0) {
        perror("msgget");
//        return 1;
    }
    sbuf.mtype = 1;
    	int temp = device.dist();
    	sbuf.mtext[0] = temp;
    	buf_length = 1;    
    	if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
       		printf ("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
        	perror("msgsnd");
        	return 1;
    	}
//    msgctl(msqid, IPC_RMID, NULL);

    return 0;
}
