/* Experiment 3: POSIX threads. Compile with gcc -pthread. */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
static void *worker(void *arg){int id=*(int *)arg;printf("Worker thread %d is running\n",id);return NULL;}
int main(void){pthread_t t[2];int ids[2]={1,2};
 for(int i=0;i<2;i++)if(pthread_create(&t[i],NULL,worker,&ids[i])){fputs("pthread_create failed\n",stderr);return EXIT_FAILURE;}
 for(int i=0;i<2;i++)pthread_join(t[i],NULL);puts("All threads joined");return 0;}
