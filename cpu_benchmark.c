#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

void run_cpu_intensive_task() {
    volatile unsigned long long i, sum = 0;
    for (i = 0; i < 1000000000ULL; i++) {
        sum += i;
    }
}

void print_times(struct timeval start, struct timeval end, struct rusage usage) {
    long wallclock = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
    long user = usage.ru_utime.tv_sec * 1000 + usage.ru_utime.tv_usec / 1000;
    long sys  = usage.ru_stime.tv_sec * 1000 + usage.ru_stime.tv_usec / 1000;

    printf("Wallclock Time: %ld ms\n", wallclock);
    printf("User Time: %ld ms\n", user);
    printf("System Time: %ld ms\n", sys);
}

int main() {
    struct timeval start, end;
    struct rusage usage;

    gettimeofday(&start, NULL);
    run_cpu_intensive_task();
    gettimeofday(&end, NULL);
    getrusage(RUSAGE_SELF, &usage);

    print_times(start, end, usage);
    return 0;
}
