#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char* command_name;
    void (*command_function)(); 
} Command;

void commandLoad(Command* command, const char* input_command);

#endif

