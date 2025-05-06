#include "app.h"

void app_get(const char* path, char* (*handler)()) {
    strcpy(routes[route_count].method, "GET");
    strcpy(routes[route_count].path, path);
    routes[route_count].handler = handler;
    route_count++;
}


void app_run(int port) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 10);

    printf("Server listening on port %d...\n", port);

    while (1) {
        int client_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        char buffer[4096] = {0};
        read(client_fd, buffer, 4096);

        char method[8], path[128];
        sscanf(buffer, "%s %s", method, path);

        int found = 0;
        char* body = "404 Not Found";

        for (int i = 0; i < route_count; i++) {
            if (strcmp(routes[i].method, method) == 0 && strcmp(routes[i].path, path) == 0) {
                body = routes[i].handler();
                found = 1;
                break;
            }
        }

        char response[8192];
        sprintf(response,
            "HTTP/1.1 %s\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: %lu\r\n"
            "\r\n%s",
            found ? "200 OK" : "404 Not Found",
            strlen(body),
            body
        );

        send(client_fd, response, strlen(response), 0);
        close(client_fd);
    }
}
