/* Experiment 6: dining philosophers.
 * A room semaphore limits entry to four philosophers and prevents circular wait.
 * Compile with: gcc -Wall -Wextra -pthread -o dining dining_philosophers.c
 */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define PHILOSOPHER_COUNT 5

static pthread_mutex_t forks[PHILOSOPHER_COUNT];
static sem_t room;

static void *philosopher(void *argument)
{
    int id = *(int *)argument;

    for (int round = 0; round < 2; ++round) {
        printf("Philosopher %d thinking\n", id);
        sem_wait(&room);

        pthread_mutex_lock(&forks[id]);
        pthread_mutex_lock(&forks[(id + 1) % PHILOSOPHER_COUNT]);

        printf("Philosopher %d eating\n", id);
        usleep(10000);

        pthread_mutex_unlock(&forks[(id + 1) % PHILOSOPHER_COUNT]);
        pthread_mutex_unlock(&forks[id]);
        sem_post(&room);
    }

    return NULL;
}

int main(void)
{
    pthread_t threads[PHILOSOPHER_COUNT];
    int ids[PHILOSOPHER_COUNT];

    sem_init(&room, 0, PHILOSOPHER_COUNT - 1);

    for (int i = 0; i < PHILOSOPHER_COUNT; ++i) {
        pthread_mutex_init(&forks[i], NULL);
        ids[i] = i;
    }

    for (int i = 0; i < PHILOSOPHER_COUNT; ++i) {
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < PHILOSOPHER_COUNT; ++i) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < PHILOSOPHER_COUNT; ++i) {
        pthread_mutex_destroy(&forks[i]);
    }

    sem_destroy(&room);
    return 0;
}
