#pragma once
#include <functional>
#include <string>
#include <unordered_map>

using namespace std;

namespace router
{
    using Controller = function<string()>;

    class Router
    {
        public:
            void get(const string &path, Controller controller);
            string route_request(const string &path);

        private:
            unordered_map<string, Controller> get_routes;
    };
}