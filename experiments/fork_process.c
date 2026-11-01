/* Experiment 2: fork(), getpid(), getppid(), and wait(). */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        printf("Child: PID=%ld, PPID=%ld\n",
               (long)getpid(), (long)getppid());
        return 0;
    }

    printf("Parent: PID=%ld, child PID=%ld\n",
           (long)getpid(), (long)pid);

    if (wait(NULL) < 0) {
        perror("wait");
        return EXIT_FAILURE;
    }

    puts("Parent: child has finished");
    return 0;
}
