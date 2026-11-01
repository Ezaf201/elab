# OS Lab Experiments 1–15

Standalone programs and notes for the OS lab manual. Experiments 1–9 are representative implementations based on the manual index; experiments 10–15 follow the extended manual's sample topics.

## Print an experiment

    ./elab help
    ./elab fork
    ./elab fifo
    ./elab 8
    ./elab "round robin"

The launcher prints the matching source or notes. Aliases include fork, fifo, bankers, round robin, reader writer, dining, best fit, scan, allocation, and directory.

## Compile and run C programs

    gcc -Wall -Wextra -o fork_process exp/fork_process.c
    ./fork_process
    gcc -Wall -Wextra -pthread -o multithreading exp/multithreading.c
    ./multithreading

Use -pthread for experiments 3–6. POSIX examples need Linux, WSL, or a compatible Unix environment. The algorithm programs use sample inputs; edit their arrays to try other values.

| No. | Topic | Source |
|---|---|---|
| 1 | Linux commands | exp/linux_commands.txt |
| 2 | Process creation and fork | exp/fork_process.c |
| 3 | Multithreading | exp/multithreading.c |
| 4 | Semaphore mutual exclusion | exp/semaphore_monitor.c |
| 5 | Reader-writer | exp/reader_writer.c |
| 6 | Dining philosophers | exp/dining_philosophers.c |
| 7 | Banker's algorithm | exp/bankers_algorithm.c |
| 8 | FCFS and SJF | exp/fcfs_sjf.c |
| 9 | Priority and Round Robin | exp/priority_round_robin.c |
| 10 | FIFO page replacement | exp/fifo_page_replacement.c |
| 11 | LRU and LFU | exp/lru_lfu_page_replacement.c |
| 12 | Best Fit and Worst Fit | exp/best_worst_fit.c |
| 13 | FCFS and SCAN disk scheduling | exp/fcfs_scan_disk.c |
| 14 | Sequential and indexed allocation | exp/file_allocation.c |
| 15 | Single and two-level directories | exp/directory_schemes.c |

Launcher: ./elab.
