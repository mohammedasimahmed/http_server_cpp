#include <iostream>
#include "core/http_server.h"
using namespace http;

int main()
{
    HttpServer server = HttpServer("127.0.0.1", 5000);
    return 0;
}