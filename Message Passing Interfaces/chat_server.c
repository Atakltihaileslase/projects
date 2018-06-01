#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1

int main() {

    int shm_id;
    size_t size = 300;
    int shm_flg =  IPC_CREAT | 0666; // read write permission for all users

    key_t key = 12345;
    
    char *msg, *chars;

    shm_id = shmget(key, size, shm_flg);

    if(shm_id == -1) {
        perror("Error: shmget has failed\n");
        exit(0);
    }

    // attached shared memory to the process's address space
    chars = shmat(shm_id, NULL, 0);

    if(chars == (char*)-1) {
        perror("ERROR: shmat has failed \n");
        exit(0);
    }

	// reserve the first char for flagging purpose
	msg = chars + 1;

	while (TRUE) {

		// wait for a reply
		while(chars[0] != 'y') {
		    sleep(1);
		}
		
		// set the not ready flag
		chars[0] = 'n';

		// print the friend's reply
		printf("the shared friend >>> %s",msg);

		// print the prompt 
		printf("I am >>> ");

		// get input message
		fgets(msg, size - 2, stdin);

		// set flag in read state
		chars[0] = 'f';

	}

    // detach the shared memory
    if(shmdt(chars) == -1) {
        perror("ERROR: detaching shared memory failed");
    }

    // finally free the shared memory
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;

}
