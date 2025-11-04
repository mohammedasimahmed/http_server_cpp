#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace logger
{
    void log(const string &message);
    void exit_with_error(const string &error_message);
}