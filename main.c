#include "src/commandLoad.c"
#include "src/app.c"
#include "app/Routes/web.c"

int main(int argc, char* argv[]) {
    if (argc > 1) {
        commandLoad(argv[1]);  
    } else {
        register_routes();
        app_run(5555);
    }

    return 0;
}
