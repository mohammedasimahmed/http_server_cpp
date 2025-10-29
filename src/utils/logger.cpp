#include "logger.h"
#include <cstdlib>

using namespace std;

namespace logger
{
    void log(const string &message)
    {
        cout << message << endl;
    }

    void exitWithError(const string &errorMessage)
    {
        cerr<<"ERROR: " + errorMessage <<endl;
        exit(1);
    }
}