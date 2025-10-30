#include "utils/logger.h"
#include <cstdlib>

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