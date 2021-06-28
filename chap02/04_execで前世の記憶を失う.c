#include "stdio.h"
#include "unistd.h"

int main() {
    printf("変身前: PID=%d\n", getpid());

    // lsプロセスに変身
    execlp("ls", "");

    // lsプロセスに変身しているので、ここからは実行されない！
    printf("lsプロセスに変身しているので、ここからは実行されない！\n");
}