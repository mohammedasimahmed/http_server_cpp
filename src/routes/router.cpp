#include "routes/router.h"
#include "controllers/default_controller.h"
#include <cstring>
#include <sstream>
#include <iostream>

using namespace std;

namespace router
{
    void Router::get(const string &path, Controller controller)
    {
        get_routes[path] = controller;
    }

    string Router::route_request(const string &request)
    {
        istringstream stream(request);
        string method, path, version;
        stream >> method >> path >> version;

        if(method != "GET" || path != "/")
        {
            return "Not Found";
        }

        return controller::default_controller();
    }
}