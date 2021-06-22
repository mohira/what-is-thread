#include "stdio.h"
#include "unistd.h"

int main() {
    fork();
    printf("プロセスid=%d\n", getpid());
}