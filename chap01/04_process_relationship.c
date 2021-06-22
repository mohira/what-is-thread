#include "sys/types.h"
#include "stdio.h"
#include "unistd.h"

int main() {
    pid_t val; // pid_t型

    val = fork();
    printf("forkの戻り値=%d\n", val);
    printf("プロセスid=%d\n", getpid());
}