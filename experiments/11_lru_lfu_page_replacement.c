/* Experiment 11: LRU and LFU page replacement using the manual's sample. */
#include <stdio.h>

#define FRAME_COUNT 3
#define PAGE_COUNT 15

static void run_page_replacement(int use_lfu)
{
    int pages[PAGE_COUNT] = {1, 2, 3, 2, 1, 5, 2, 1,
                             6, 2, 5, 6, 3, 1, 3};
    int frames[FRAME_COUNT] = {-1, -1, -1};
    int last_used[FRAME_COUNT] = {0};
    int frequency[FRAME_COUNT] = {0};
    int page_faults = 0;

    printf("%s Page Replacement\n", use_lfu ? "LFU" : "LRU");

    for (int page_index = 0; page_index < PAGE_COUNT; ++page_index) {
        int page = pages[page_index];
        int hit_frame = -1;

        for (int frame = 0; frame < FRAME_COUNT; ++frame) {
            if (frames[frame] == page) {
                hit_frame = frame;
                break;
            }
        }

        if (hit_frame >= 0) {
            last_used[hit_frame] = page_index;
            ++frequency[hit_frame];
        } else {
            ++page_faults;
            int victim = -1;

            for (int frame = 0; frame < FRAME_COUNT; ++frame) {
                if (frames[frame] == -1) {
                    victim = frame;
                    break;
                }
            }

            if (victim == -1) {
                victim = 0;
                for (int frame = 1; frame < FRAME_COUNT; ++frame) {
                    int should_replace =
                        use_lfu
                            ? (frequency[frame] < frequency[victim] ||
                               (frequency[frame] == frequency[victim] &&
                                last_used[frame] < last_used[victim]))
                            : (last_used[frame] < last_used[victim]);

                    if (should_replace) {
                        victim = frame;
                    }
                }
            }

            frames[victim] = page;
            last_used[victim] = page_index;
            frequency[victim] = 1;
        }

        printf("%d\t", page);
        for (int frame = 0; frame < FRAME_COUNT; ++frame) {
            if (frames[frame] == -1) {
                printf("-\t");
            } else {
                printf("%d\t", frames[frame]);
            }
        }
        puts(hit_frame >= 0 ? "Hit" : "Fault");
    }

    printf("Total page faults = %d\n\n", page_faults);
}

int main(void)
{
    run_page_replacement(0);
    run_page_replacement(1);
    return 0;
}
