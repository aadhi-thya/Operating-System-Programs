// Message Queue IPC
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
struct msgbuf { long mtype; char mtext[100]; } msg;
int main() {
    int id = msgget(IPC_PRIVATE, IPC_CREAT|0666);
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello from Message Queue");
    msgsnd(id, &msg, sizeof(msg.mtext), 0);
    printf("Message Sent: %s\n", msg.mtext);
    msgrcv(id, &msg, sizeof(msg.mtext), 1, 0);
    printf("Message Received: %s\n", msg.mtext);
    msgctl(id, IPC_RMID, NULL);
    return 0;
}


