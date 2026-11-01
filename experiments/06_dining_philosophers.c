/* Experiment 6: a room semaphore prevents circular wait. Compile with -pthread. */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#define N 5
static pthread_mutex_t forks[N];static sem_t room;
static void *philosopher(void *arg){int id=*(int*)arg;for(int k=0;k<2;k++){printf("Philosopher %d thinking\n",id);sem_wait(&room);
 pthread_mutex_lock(&forks[id]);pthread_mutex_lock(&forks[(id+1)%N]);printf("Philosopher %d eating\n",id);usleep(10000);
 pthread_mutex_unlock(&forks[(id+1)%N]);pthread_mutex_unlock(&forks[id]);sem_post(&room);}return NULL;}
int main(void){pthread_t t[N];int id[N];sem_init(&room,0,N-1);for(int i=0;i<N;i++){pthread_mutex_init(&forks[i],NULL);id[i]=i;}
 for(int i=0;i<N;i++)pthread_create(&t[i],NULL,philosopher,&id[i]);for(int i=0;i<N;i++)pthread_join(t[i],NULL);
 for(int i=0;i<N;i++)pthread_mutex_destroy(&forks[i]);sem_destroy(&room);return 0;}
