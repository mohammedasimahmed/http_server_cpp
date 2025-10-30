#include <iostream>
#include "core/http_server.h"
#include "routes/router.h"
#include "controllers/default_controller.h"
using namespace http;

int main()
{
    router::Router router;
    router.get("/", controller::default_controller);

    HttpServer server = HttpServer("127.0.0.1", 5000, &router);
    return 0;
}