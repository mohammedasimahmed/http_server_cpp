#include "core/http_server.h"
#include "utils/logger.h"
#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>

using namespace std;

namespace http
{
    HttpServer::HttpServer(string ip_address, int port)
    {
        server_ip_address = ip_address;
        server_port = port;
        
        startServer();
    }

    HttpServer::~HttpServer()
    {
        closeServer();
    }

    int HttpServer::startServer()
    {
        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0)
        {
            logger::exitWithError("Cannot create socket");
        }

        sockaddr_in server_socket_addr;
        server_socket_addr.sin_family = AF_INET;
        server_socket_addr.sin_addr.s_addr = inet_addr(server_ip_address.c_str());
        server_socket_addr.sin_port = htons(server_port);

        // Allows the socket to reuse the same address immediately after closing
        int opt = 1;
        setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

        if(bind(server_socket, (struct sockaddr *) &server_socket_addr, sizeof(server_socket_addr)) < 0)
        {
            logger::exitWithError("Could not bind the server socket to IP Address: " + server_ip_address + "and PORT: " + to_string(server_port));
        }

        if(listen(server_socket, SOMAXCONN) < 0)
        {
            logger::exitWithError("Could not ready the server socket for accepting client connections");
        }

        logger::log("Server started on " + server_ip_address + ":" + to_string(server_port));
        
        while(true)
        {
            sockaddr_in client_socket_addr;
            socklen_t client_socket_addr_len = sizeof(client_socket_addr);
            int client_socket = accept(server_socket, (struct sockaddr *)&client_socket_addr, &client_socket_addr_len);

            if(client_socket < 0)
            {
                logger::log("Client connection failed");
                continue;
            }

            thread client_thread(&HttpServer::handleClient, this, client_socket);
            client_thread.detach();            
        }

        return 0;
    }

    void HttpServer::handleClient(int client_socket)
    {
        char buffer[4096];
        memset(buffer, 0, sizeof(buffer));

        read(client_socket, buffer, sizeof(buffer));
        
        string request(buffer);

        logger::log("Received request:\n" + request);

        string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 13\r\n"
            "Connection: close\r\n"
            "\r\n"
            "Hello, world!";

        send(client_socket, response.c_str(), response.size(), 0);
        close(client_socket);
    }

    void HttpServer::closeServer()
    {
        if (server_socket >= 0)
            close(server_socket);

        server_socket = -1;
    }
}