#include "stdio.h"
#include "unistd.h"

// http://networkprogramming.blog18.fc2.com/blog-entry-44.html
int main() {
    printf("Running ps with execlp\n");

    execlp("ps", "ps", NULL);

    printf("Done.\n");
}