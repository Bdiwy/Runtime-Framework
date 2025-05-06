#include <stdio.h>
#include <stdlib.h>

void watch_command() {
    printf("Watching for changes...\n");
    system("ls *.c *.h | entr gcc main.c -o server && ./server");
}
