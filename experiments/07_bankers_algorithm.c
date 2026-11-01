/* Experiment 7: Banker's algorithm for deadlock avoidance. */
#include <stdio.h>

#define PROCESS_COUNT 5
#define RESOURCE_COUNT 3

int main(void)
{
    int allocation[PROCESS_COUNT][RESOURCE_COUNT] = {
        {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}
    };
    int maximum[PROCESS_COUNT][RESOURCE_COUNT] = {
        {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}
    };
    int available[RESOURCE_COUNT] = {3, 3, 2};
    int need[PROCESS_COUNT][RESOURCE_COUNT];
    int finished[PROCESS_COUNT] = {0};
    int sequence[PROCESS_COUNT];
    int sequence_count = 0;

    for (int process = 0; process < PROCESS_COUNT; ++process) {
        for (int resource = 0; resource < RESOURCE_COUNT; ++resource) {
            need[process][resource] =
                maximum[process][resource] - allocation[process][resource];
        }
    }

    while (sequence_count < PROCESS_COUNT) {
        int made_progress = 0;

        for (int process = 0; process < PROCESS_COUNT; ++process) {
            if (finished[process]) {
                continue;
            }

            int can_finish = 1;
            for (int resource = 0; resource < RESOURCE_COUNT; ++resource) {
                if (need[process][resource] > available[resource]) {
                    can_finish = 0;
                    break;
                }
            }

            if (can_finish) {
                for (int resource = 0; resource < RESOURCE_COUNT; ++resource) {
                    available[resource] += allocation[process][resource];
                }

                finished[process] = 1;
                sequence[sequence_count++] = process;
                made_progress = 1;
            }
        }

        if (!made_progress) {
            break;
        }
    }

    if (sequence_count == PROCESS_COUNT) {
        printf("Safe sequence: ");
        for (int i = 0; i < PROCESS_COUNT; ++i) {
            printf("P%d%s", sequence[i], i == PROCESS_COUNT - 1 ? "\n" : " -> ");
        }
    } else {
        puts("Unsafe state");
    }

    return 0;
}
