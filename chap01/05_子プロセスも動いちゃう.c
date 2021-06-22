#include "sys/types.h"
#include "stdio.h"
#include "unistd.h"

int main() {
    fork();
    printf("子プロセス\n");
    printf("親プロセス\n");
}