/* Experiment 4: mutual exclusion using a POSIX semaphore.
 * Compile with: gcc -Wall -Wextra -pthread -o semaphore semaphore_monitor.c
 */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

static sem_t mutex;
static int counter = 0;

static void *increment(void *unused)
{
    (void)unused;

    for (int i = 0; i < 100000; ++i) {
        sem_wait(&mutex);
        ++counter;
        sem_post(&mutex);
    }

    return NULL;
}

int main(void)
{
    pthread_t first;
    pthread_t second;

    if (sem_init(&mutex, 0, 1) != 0) {
        perror("sem_init");
        return EXIT_FAILURE;
    }

    if (pthread_create(&first, NULL, increment, NULL) != 0 ||
        pthread_create(&second, NULL, increment, NULL) != 0) {
        fputs("pthread_create failed\n", stderr);
        sem_destroy(&mutex);
        return EXIT_FAILURE;
    }

    pthread_join(first, NULL);
    pthread_join(second, NULL);

    printf("Counter = %d (expected 200000)\n", counter);

    sem_destroy(&mutex);
    return 0;
}
