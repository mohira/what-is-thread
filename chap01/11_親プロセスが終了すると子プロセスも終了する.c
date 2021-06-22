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
        printf("sleepおわたよ");
        exit(3);
    } else {
        exit(1); // 親プロセスを終了すると、子プロセスも終了する
        wait(&status);
        printf("親プロセスですけん\n");
        printf("子プロセス終了時の値=%04x\n", status);
    }
}