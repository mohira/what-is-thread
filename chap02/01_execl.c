#include "stdio.h"
#include "unistd.h"

int main() {
    printf("cal 1 2020 に変身\n");

    // execl の最後の引数はヌルポインタを渡す
    execl("/usr/bin/cal", "cal", "1", "2020", (char *) 0);
}