#include "sys/types.h"
#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"

int main() {
    int status;

    if (fork() == 0) {
        printf("私は子プロセス\n");
        sleep(5);
    } else {
        wait(&status);
        printf("親プロセスですけん\n");
    }
}