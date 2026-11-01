/* Experiment 3: POSIX threads. Compile with gcc -pthread. */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static void *worker(void *argument)
{
    int id = *(int *)argument;
    printf("Worker thread %d is running\n", id);
    return NULL;
}

int main(void)
{
    pthread_t threads[2];
    int ids[2] = {1, 2};

    for (int i = 0; i < 2; ++i) {
        if (pthread_create(&threads[i], NULL, worker, &ids[i]) != 0) {
            fputs("pthread_create failed\n", stderr);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < 2; ++i) {
        pthread_join(threads[i], NULL);
    }

    puts("All threads joined");
    return 0;
}
