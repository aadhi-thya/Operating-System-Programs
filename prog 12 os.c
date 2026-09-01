//12. Dining Philosophers Problem
//Program:
#include <stdio.h>
#include <pthread.h>
#define N 5
pthread_mutex_t chop[N];
void* philosopher(void* num) {
    int i = *(int*)num;
    pthread_mutex_lock(&chop[i]);
    pthread_mutex_lock(&chop[(i+1)%N]);
    printf("Philosopher %d is eating\n", i);
    pthread_mutex_unlock(&chop[(i+1)%N]);
    pthread_mutex_unlock(&chop[i]);
    return NULL;
}
int main() {
    pthread_t th[N]; int id[N];
    for (int i=0;i<N;i++) pthread_mutex_init(&chop[i], NULL);
    for (int i=0;i<N;i++){ id[i]=i; pthread_create(&th[i], NULL, philosopher, &id[i]); }
    for (int i=0;i<N;i++) pthread_join(th[i], NULL);
    return 0;
}