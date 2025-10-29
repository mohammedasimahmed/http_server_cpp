#ifndef HTTP_SERVER
#define HTTP_SERVER

#include <string>

using namespace std;

namespace http
{
    class HttpServer
    {
        public:
            HttpServer(string ip_address, int port);
            ~HttpServer();

            int startServer();
            void handleClient(int client_socket);
        
        private:
            string server_ip_address;
            int server_port;
            int server_socket;
            
            void closeServer();
    };
}

#endif