/* Experiment 5: readers-writers using a POSIX read/write lock.
 * Compile with: gcc -Wall -Wextra -pthread -o reader_writer reader_writer.c
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static pthread_rwlock_t lock = PTHREAD_RWLOCK_INITIALIZER;
static int shared_value = 0;

static void *reader(void *unused)
{
    (void)unused;

    pthread_rwlock_rdlock(&lock);
    printf("Reader sees value %d\n", shared_value);
    pthread_rwlock_unlock(&lock);

    return NULL;
}

static void *writer(void *unused)
{
    (void)unused;

    pthread_rwlock_wrlock(&lock);
    ++shared_value;
    printf("Writer updates value to %d\n", shared_value);
    pthread_rwlock_unlock(&lock);

    return NULL;
}

int main(void)
{
    pthread_t reader_thread;
    pthread_t writer_thread;

    if (pthread_create(&reader_thread, NULL, reader, NULL) != 0 ||
        pthread_create(&writer_thread, NULL, writer, NULL) != 0) {
        fputs("pthread_create failed\n", stderr);
        return EXIT_FAILURE;
    }

    pthread_join(reader_thread, NULL);
    pthread_join(writer_thread, NULL);
    pthread_rwlock_destroy(&lock);

    return 0;
}
