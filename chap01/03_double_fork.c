#include "sys/types.h"
#include "stdio.h"
#include "unistd.h"

int main() {
    fork();
    fork();
    printf("プロセスid=%d\n", getpid());
}