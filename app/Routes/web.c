#include "../Controllers/HomeController.c"
#include "../Controllers/AboutController.c"

void register_routes() {
    app_get("/", home_handler);
    app_get("/about", about); 
    app_get("/me", me); 
}
