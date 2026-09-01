// Shared Memory IPC
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main() {
    int id = shmget(IPC_PRIVATE, 1024, IPC_CREAT|0666);
    char *str = shmat(id, NULL, 0);
    strcpy(str, "Hello from Shared Memory");
    printf("Data written in shared memory: %s\n", str);
    printf("Data read from shared memory: %s\n", str);
    shmdt(str); shmctl(id, IPC_RMID, NULL);
    return 0;
}


