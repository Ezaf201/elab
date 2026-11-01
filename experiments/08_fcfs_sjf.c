/* Experiment 8: non-preemptive FCFS and SJF CPU scheduling. */
#include <stdio.h>

static void report_schedule(const char *name, const int order[],
                            int process_count, const int burst[])
{
    int elapsed_time = 0;
    int total_waiting_time = 0;

    printf("%s order: ", name);

    for (int i = 0; i < process_count; ++i) {
        int process = order[i];

        printf("P%d%s", process + 1,
               i == process_count - 1 ? "\n" : " -> ");

        total_waiting_time += elapsed_time;
        elapsed_time += burst[process];
    }

    printf("Average waiting time: %.2f\n",
           (double)total_waiting_time / process_count);
}

int main(void)
{
    int burst[4] = {6, 8, 7, 3};
    int fcfs_order[4] = {0, 1, 2, 3};
    int sjf_order[4] = {3, 0, 2, 1};

    report_schedule("FCFS", fcfs_order, 4, burst);
    report_schedule("SJF", sjf_order, 4, burst);

    return 0;
}
