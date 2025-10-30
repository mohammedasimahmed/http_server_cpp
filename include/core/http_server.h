#pragma once
#include <string>
#include "routes/router.h"

using namespace std;

namespace http
{
    class HttpServer
    {
        public:
            HttpServer(string ip_address, int port, router::Router* router);
            ~HttpServer();

            int startServer();
            void handleClient(int client_socket);
        
        private:
            string server_ip_address;
            int server_port;
            int server_socket;
            router::Router* router;
            
            void closeServer();
    };
}