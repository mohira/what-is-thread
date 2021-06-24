#include "stdio.h"
#include "unistd.h"

int main() {
    printf("変身前: PID=%d\n", getpid());

    // calプロセスに変身
    execlp("ls", "");

    // calプロセスに変身しているので、ここからは実行されない！
    printf("calプロセスに変身しているので、ここからは実行されない！\n");
}