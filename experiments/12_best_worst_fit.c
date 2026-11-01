/* Experiment 12: Best Fit and Worst Fit memory allocation.
 * Sample block and process sizes are taken from the lab manual.
 */
#include <stdio.h>

#define BLOCK_COUNT 5
#define PROCESS_COUNT 4

static void allocate(const char *name, int use_worst_fit)
{
    int block_size[BLOCK_COUNT] = {100, 50, 30, 120, 35};
    int process_size[PROCESS_COUNT] = {40, 10, 30, 60};
    int block_used[BLOCK_COUNT] = {0};
    int allocation[PROCESS_COUNT];

    for (int process = 0; process < PROCESS_COUNT; ++process) {
        allocation[process] = -1;

        for (int block = 0; block < BLOCK_COUNT; ++block) {
            int fits = !block_used[block] &&
                       block_size[block] >= process_size[process];
            int is_better_fit =
                allocation[process] < 0 ||
                (use_worst_fit
                     ? block_size[block] > block_size[allocation[process]]
                     : block_size[block] < block_size[allocation[process]]);

            if (fits && is_better_fit) {
                allocation[process] = block;
            }
        }

        if (allocation[process] >= 0) {
            block_used[allocation[process]] = 1;
        }
    }

    printf("%s Memory Allocation\n", name);
    printf("Process\tSize\tBlock\n");

    for (int process = 0; process < PROCESS_COUNT; ++process) {
        printf("P%d\t%d\t", process + 1, process_size[process]);

        if (allocation[process] >= 0) {
            int block = allocation[process];
            printf("%d (size %d)\n", block + 1, block_size[block]);
        } else {
            puts("Not Allocated");
        }
    }
}

int main(void)
{
    allocate("Best Fit", 0);
    putchar('\n');
    allocate("Worst Fit", 1);

    return 0;
}
