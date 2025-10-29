#ifndef LOGGER
#define LOGGER

#include <string>
#include <iostream>

using namespace std;

namespace logger
{
    void log(const string &message);
    void exitWithError(const string &errorMessage);
}

#endif