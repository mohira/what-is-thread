#include "sys/types.h"
#include "stdio.h"
#include "unistd.h"

int main() {
    pid_t forked_pid;
    forked_pid = fork();

    if (forked_pid != 0) {
        printf("私はPID=%d。こんにちは。私の親プロセスのIDは%d\n", getpid(), getppid());
    }
}