/* Experiment 4: mutual exclusion using a POSIX semaphore. Compile with -pthread. */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
static sem_t mutex;static int counter;
static void *increment(void *unused){(void)unused;for(int i=0;i<100000;i++){sem_wait(&mutex);counter++;sem_post(&mutex);}return NULL;}
int main(void){pthread_t a,b;if(sem_init(&mutex,0,1)){perror("sem_init");return EXIT_FAILURE;}
 if(pthread_create(&a,NULL,increment,NULL)||pthread_create(&b,NULL,increment,NULL)){fputs("pthread_create failed\n",stderr);return EXIT_FAILURE;}
 pthread_join(a,NULL);pthread_join(b,NULL);printf("Counter = %d (expected 200000)\n",counter);sem_destroy(&mutex);return 0;}
