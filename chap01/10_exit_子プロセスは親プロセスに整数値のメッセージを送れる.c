#include "sys/types.h"
#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int main() {
    int status;

    if (fork() == 0) {
        printf("私は子プロセス\n");
        sleep(5);
        exit(3);
    } else {
        wait(&status);
        printf("親プロセスですけん\n");
        printf("子プロセス終了時の値=%04x\n", status);
    }
}