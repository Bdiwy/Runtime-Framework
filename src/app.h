#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define MAX_ROUTES 100

typedef struct {
    char method[8];
    char path[128];
    char* (*handler)();
} Route;

Route routes[MAX_ROUTES];
int route_count = 0;

void app_get(const char* path, char* (*handler)());
void register_routes();
void app_run(int port);

#endif
