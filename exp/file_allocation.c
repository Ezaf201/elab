/* Experiment 14: sequential and indexed file allocation. */
#include <stdio.h>

#define DISK_BLOCK_COUNT 50

static void sequential_allocation(void)
{
    int disk[DISK_BLOCK_COUNT] = {0};
    int starts[4] = {5, 8, 20, 2};
    int lengths[4] = {3, 4, 5, 4};

    puts("Sequential File Allocation");

    for (int file = 0; file < 4; ++file) {
        int available = 1;
        int end = starts[file] + lengths[file];

        for (int block = starts[file]; block < end; ++block) {
            if (block >= DISK_BLOCK_COUNT || disk[block]) {
                available = 0;
                break;
            }
        }

        printf("\nFile %d: start block = %d, length = %d\n",
               file + 1, starts[file], lengths[file]);

        if (!available) {
            puts("File is not allocated (blocks already in use)");
            continue;
        }

        for (int block = starts[file]; block < end; ++block) {
            disk[block] = 1;
            printf("%d -> %d\n", block, disk[block]);
        }

        printf("File %d is allocated to the disk\n", file + 1);
    }
}

static void indexed_allocation(void)
{
    int disk[DISK_BLOCK_COUNT] = {0};
    int index_blocks[3] = {9, 20, 9};
    int data_blocks[3][4] = {
        {1, 2, 3, 4},
        {10, 11, 12, 13},
        {30, 31, 32, 33}
    };

    puts("\nIndexed File Allocation");

    for (int file = 0; file < 3; ++file) {
        int index_block = index_blocks[file];
        int available = !disk[index_block];

        printf("\nFile %d: index block = %d\n", file + 1, index_block);

        for (int i = 0; i < 4; ++i) {
            if (disk[data_blocks[file][i]]) {
                available = 0;
            }
        }

        if (!available) {
            puts("Not allocated (an index or data block is already in use)");
            continue;
        }

        disk[index_block] = 1;
        for (int i = 0; i < 4; ++i) {
            int block = data_blocks[file][i];
            disk[block] = 1;
            printf("%d -> %d : %d\n", index_block, block, disk[block]);
        }
    }
}

int main(void)
{
    sequential_allocation();
    indexed_allocation();
    return 0;
}
