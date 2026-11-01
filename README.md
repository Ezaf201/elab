# OS Lab Experiments 1–15

Standalone programs and notes for the OS lab manual. Experiments 1–9 are representative implementations from the manual index; experiments 10–15 follow the extended manual's sample topics.

## Print an experiment

```sh
chmod +x ./elab
./elab help
./elab fork
./elab fifo
./elab 8
./elab "round robin"
```

The launcher prints the matching source or notes. Aliases include `fork`, `fifo`, `bankers`, `round robin`, `reader writer`, `dining`, `best fit`, `scan`, `allocation`, and `directory`.

## Compile and run C programs

```sh
gcc -Wall -Wextra -o fork_process experiments/02_fork_process.c
./fork_process
gcc -Wall -Wextra -pthread -o multithreading experiments/03_multithreading.c
./multithreading
```

Use `-pthread` for experiments 3–6. POSIX examples need Linux, WSL, or a compatible Unix environment. The algorithm programs use sample inputs; edit their arrays to try other values.

| No. | Topic | Source |
|---|---|---|
| 1 | Linux commands | `experiments/01_linux_commands.txt` |
| 2 | Process creation and fork | `experiments/02_fork_process.c` |
| 3 | Multithreading | `experiments/03_multithreading.c` |
| 4 | Semaphore mutual exclusion | `experiments/04_semaphore_monitor.c` |
| 5 | Reader-writer | `experiments/05_reader_writer.c` |
| 6 | Dining philosophers | `experiments/06_dining_philosophers.c` |
| 7 | Banker's algorithm | `experiments/07_bankers_algorithm.c` |
| 8 | FCFS and SJF | `experiments/08_fcfs_sjf.c` |
| 9 | Priority and Round Robin | `experiments/09_priority_round_robin.c` |
| 10 | FIFO page replacement | `experiments/10_fifo_page_replacement.c` |
| 11 | LRU and LFU | `experiments/11_lru_lfu_page_replacement.c` |
| 12 | Best Fit and Worst Fit | `experiments/12_best_worst_fit.c` |
| 13 | FCFS and SCAN disk scheduling | `experiments/13_fcfs_scan_disk.c` |
| 14 | Sequential and indexed allocation | `experiments/14_file_allocation.c` |
| 15 | Single and two-level directories | `experiments/15_directory_schemes.c` |

Launcher: `./elab`.
