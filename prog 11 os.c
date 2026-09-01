//11. Multithreading
//Program:
#include <stdio.h>
#include <pthread.h>
void* task(void* arg) {
    printf("Thread %ld running\n", (long)arg);
    return NULL;
}
int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, task, (void*)1);
    pthread_create(&t2, NULL, task, (void*)2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Main thread finished\n");
    return 0;
}
