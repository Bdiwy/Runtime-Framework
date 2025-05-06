#include <stdio.h>
#include <stdlib.h>

void commandLoad() {
    printf("Building the project...\n");
    system("rm server");
    system("gcc main.c -o server");
    printf("Build complete.\n");
    system("./server");
}
