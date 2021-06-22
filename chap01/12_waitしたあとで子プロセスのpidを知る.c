#include "sys/types.h"
#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int main() {
    int status;
    pid_t pid;

    if (fork() == 0) {
        printf("私は子プロセス\n");
        sleep(5);
        printf("sleepおわたよ\n\n");
        exit(3);
    } else {
        pid = wait(&status);
        printf("親プロセスですけん\n");
        printf("子プロセスのPID=%d\n", pid);
        printf("子プロセス終了時の値=%04x\n", status);
    }
}