#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

#define MSGSZ     128


/*
 * Declare the message structure.
 */

class message_buf {
public:
    long    mtype;
    char    mtext[MSGSZ];
};


int main()
{
    int msqid;
    key_t key;
    message_buf  rbuf;

    /*
     * Get the message queue id for the
     * "name" 1234, which was created by
     * the server.
     */
    key = 1234;

    if ((msqid = msgget(key, 0666)) < 0) {
        perror("msgget");
        return 1;
    }

    
    /*
     * Receive an answer of message type 1.
     */
      for(int i = 0; i < 100; i++){
	    if (msgrcv(msqid, &rbuf, MSGSZ, 1, 0) < 0) {
	        perror("msgrcv");
        	return 1;
    	    }
            printf("%i\n", rbuf.mtext[0]);
    }
    return 0;
}
