#include "sys/types.h"
#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int main() {
    // 親プロセスが子プロセスを生成し、
    // 子プロセスが孫プロセスを生成する
    int status;

    if (fork() == 0) {
        if (fork() == 0) {
            printf("孫プロセス: PID=%d 親PID=%d\n", getpid(), getppid());
        } else {
            wait(&status);
            printf("子プロセス: PID=%d 親PID=%d\n", getpid(), getppid());
        }

    } else {
        wait(&status);
        printf("親プロセス: PID=%d 親PID=%d\n", getpid(), getppid());
    }


}