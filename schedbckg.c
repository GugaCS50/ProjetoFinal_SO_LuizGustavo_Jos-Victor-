#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <politica> <caminho_programa>\n", argv[0]);
        return 1;
    }

    int policy;
    if (strcmp(argv[1], "OTHER") == 0) policy = SCHED_OTHER;
    else if (strcmp(argv[1], "FIFO") == 0) policy = SCHED_FIFO;
    else if (strcmp(argv[1], "RR") == 0) policy = SCHED_RR;
    else if (strcmp(argv[1], "BACKGROUND") == 0) policy = 7; // Valor definido por você
    else {
        fprintf(stderr, "Política desconhecida.\n");
        return 1;
    }

    struct sched_param param;
    param.sched_priority = (policy == SCHED_OTHER || policy == 7) ? 0 : 10;

    if (sched_setscheduler(0, policy, &param) < 0) {
        perror("sched_setscheduler");
        return 1;
    }

    execv(argv[2], &argv[2]);
    perror("execv");
    return 1;
}
