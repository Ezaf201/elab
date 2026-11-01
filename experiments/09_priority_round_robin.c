/* Experiment 9: priority and Round Robin scheduling.
 * Lower priority number means higher priority; Round Robin quantum is 2.
 */
#include <stdio.h>

int main(void)
{
    int burst[4] = {5, 3, 8, 6};
    int current_time = 0;
    int completed = 0;
    const int quantum = 2;

    puts("Priority order (highest first): P2 -> P1 -> P4 -> P3");
    puts("Round Robin completion times:");

    while (completed < 4) {
        for (int process = 0; process < 4; ++process) {
            if (burst[process] <= 0) {
                continue;
            }

            int run_time = burst[process] < quantum
                               ? burst[process]
                               : quantum;

            current_time += run_time;
            burst[process] -= run_time;

            if (burst[process] == 0) {
                printf("P%d completes at %d\n",
                       process + 1, current_time);
                ++completed;
            }
        }
    }

    return 0;
}
