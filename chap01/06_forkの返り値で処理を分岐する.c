#include "sys/types.h"
#include "stdio.h"
#include "unistd.h"

int main() {
    pid_t val;
    val = fork();

    if (val == 0) {
        printf("子プロセス(PID=%d)からみたforkの返り値=%d\n", getpid(), val);
    } else {
        printf("親プロセス(PID=%d)からみたforkの返り値=%d\n", getpid(), val);
    }
}