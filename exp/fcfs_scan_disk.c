/* Experiment 13: FCFS and SCAN disk scheduling.
 * Manual sample: queue 95, 180, 34, 119, 11, 123, 62, 64;
 * initial head 50; disk tracks 0–199.
 */
#include <stdio.h>
#include <stdlib.h>

#define REQUEST_COUNT 8
#define LAST_TRACK 199

static void run_fcfs(const int requests[])
{
    int head = 50;
    int total_movement = 0;

    puts("FCFS Disk Scheduling");
    printf("Initial head position = %d\n", head);
    printf("Seek sequence: %d", head);

    for (int i = 0; i < REQUEST_COUNT; ++i) {
        total_movement += abs(requests[i] - head);
        head = requests[i];
        printf(" -> %d", head);
    }

    printf("\nTotal head movement = %d\n\n", total_movement);
}

static void run_scan(const int requests[])
{
    int sorted[REQUEST_COUNT];
    int head = 50;
    int total_movement = 0;
    int first_higher_request = 0;

    for (int i = 0; i < REQUEST_COUNT; ++i) {
        sorted[i] = requests[i];
    }

    for (int i = 0; i < REQUEST_COUNT - 1; ++i) {
        for (int j = 0; j < REQUEST_COUNT - i - 1; ++j) {
            if (sorted[j] > sorted[j + 1]) {
                int temporary = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temporary;
            }
        }
    }

    while (first_higher_request < REQUEST_COUNT &&
           sorted[first_higher_request] <= head) {
        ++first_higher_request;
    }

    puts("SCAN Disk Scheduling (head moving towards higher tracks)");
    printf("Initial head position = %d, disk size = 200\n", head);
    printf("Seek sequence: %d", head);

    for (int i = first_higher_request; i < REQUEST_COUNT; ++i) {
        total_movement += abs(sorted[i] - head);
        head = sorted[i];
        printf(" -> %d", head);
    }

    total_movement += abs(LAST_TRACK - head);
    head = LAST_TRACK;
    printf(" -> %d", head);

    for (int i = first_higher_request - 1; i >= 0; --i) {
        total_movement += abs(sorted[i] - head);
        head = sorted[i];
        printf(" -> %d", head);
    }

    printf("\nTotal head movement = %d\n", total_movement);
}

int main(void)
{
    int requests[REQUEST_COUNT] = {95, 180, 34, 119, 11, 123, 62, 64};

    run_fcfs(requests);
    run_scan(requests);
    return 0;
}
