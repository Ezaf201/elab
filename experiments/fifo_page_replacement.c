/* Experiment 10: FIFO page replacement using the manual's sample. */
#include <stdio.h>

#define FRAME_COUNT 3
#define PAGE_COUNT 14

int main(void)
{
    int pages[PAGE_COUNT] = {7, 0, 1, 2, 0, 3, 0,
                             4, 2, 3, 0, 3, 2, 1};
    int frames[FRAME_COUNT] = {-1, -1, -1};
    int next_frame = 0;
    int page_faults = 0;

    printf("Page\tFrame1\tFrame2\tFrame3\tResult\n");

    for (int page_index = 0; page_index < PAGE_COUNT; ++page_index) {
        int page = pages[page_index];
        int hit = 0;

        for (int frame = 0; frame < FRAME_COUNT; ++frame) {
            if (frames[frame] == page) {
                hit = 1;
                break;
            }
        }

        if (!hit) {
            frames[next_frame] = page;
            next_frame = (next_frame + 1) % FRAME_COUNT;
            ++page_faults;
        }

        printf("%d\t", page);
        for (int frame = 0; frame < FRAME_COUNT; ++frame) {
            if (frames[frame] == -1) {
                printf("-\t");
            } else {
                printf("%d\t", frames[frame]);
            }
        }
        puts(hit ? "Hit" : "Fault");
    }

    printf("\nTotal page faults = %d\n", page_faults);
    printf("Total page hits = %d\n", PAGE_COUNT - page_faults);

    return 0;
}
