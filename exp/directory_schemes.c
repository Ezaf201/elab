/* Experiment 15: single-level and two-level directory schemes. */
#include <stdio.h>
#include <string.h>

#define FILE_NAME_LENGTH 20

static int find_file(char files[][FILE_NAME_LENGTH],
                     int file_count, const char *name)
{
    for (int i = 0; i < file_count; ++i) {
        if (strcmp(files[i], name) == 0) {
            return i;
        }
    }

    return -1;
}

static void single_level_directory(void)
{
    char directory[10][FILE_NAME_LENGTH];
    int file_count = 0;
    const char *files_to_create[5] = {
        "notes.txt", "prog.c", "data.dat", "prog.c", "memo.doc"
    };

    puts("Single Level Directory");

    for (int i = 0; i < 5; ++i) {
        if (find_file(directory, file_count, files_to_create[i]) >= 0) {
            printf("Create %s: failed, name already exists\n",
                   files_to_create[i]);
        } else {
            strcpy(directory[file_count++], files_to_create[i]);
            printf("Create %s: done\n", files_to_create[i]);
        }
    }

    printf("\nSearch memo.doc: %s\n",
           find_file(directory, file_count, "memo.doc") >= 0
               ? "found" : "not found");
    printf("Search temp.txt: %s\n",
           find_file(directory, file_count, "temp.txt") >= 0
               ? "found" : "not found");

    int position = find_file(directory, file_count, "prog.c");
    if (position >= 0) {
        for (int i = position; i < file_count - 1; ++i) {
            strcpy(directory[i], directory[i + 1]);
        }
        --file_count;
        puts("Delete prog.c: done");
    }

    printf("\nDirectory contents (%d files):\n", file_count);
    for (int i = 0; i < file_count; ++i) {
        printf("%d. %s\n", i + 1, directory[i]);
    }
}

typedef struct {
    char name[FILE_NAME_LENGTH];
    char files[10][FILE_NAME_LENGTH];
    int file_count;
} UserDirectory;

static void two_level_directory(void)
{
    UserDirectory users[3] = {
        {.name = "user1"},
        {.name = "user2"},
        {.name = "user3"}
    };
    int owners[6] = {0, 0, 1, 1, 0, 2};
    const char *file_names[6] = {
        "a.txt", "b.c", "a.txt", "c.dat", "a.txt", "b.c"
    };

    puts("\nTwo Level Directory");

    for (int i = 0; i < 6; ++i) {
        UserDirectory *user = &users[owners[i]];

        if (find_file(user->files, user->file_count, file_names[i]) >= 0) {
            printf("%s: create %s failed (already exists)\n",
                   user->name, file_names[i]);
        } else {
            strcpy(user->files[user->file_count++], file_names[i]);
            printf("%s: create %s done\n", user->name, file_names[i]);
        }
    }

    puts("\nMaster File Directory");
    for (int user = 0; user < 3; ++user) {
        printf("%s:", users[user].name);
        for (int i = 0; i < users[user].file_count; ++i) {
            printf(" %s", users[user].files[i]);
        }
        putchar('\n');
    }
}

int main(void)
{
    single_level_directory();
    two_level_directory();
    return 0;
}
