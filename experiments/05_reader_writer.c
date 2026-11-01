/* Experiment 5: readers-writers with a POSIX read/write lock. Compile with -pthread. */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
static pthread_rwlock_t lock=PTHREAD_RWLOCK_INITIALIZER;static int value;
static void *reader(void *p){(void)p;pthread_rwlock_rdlock(&lock);printf("Reader sees value %d\n",value);pthread_rwlock_unlock(&lock);return NULL;}
static void *writer(void *p){(void)p;pthread_rwlock_wrlock(&lock);++value;printf("Writer updates value to %d\n",value);pthread_rwlock_unlock(&lock);return NULL;}
int main(void){pthread_t r,w;if(pthread_create(&r,NULL,reader,NULL)||pthread_create(&w,NULL,writer,NULL)){fputs("pthread_create failed\n",stderr);return EXIT_FAILURE;}
 pthread_join(r,NULL);pthread_join(w,NULL);pthread_rwlock_destroy(&lock);return 0;}
