#include "utils/logger.h"
#include <cstdlib>

namespace logger
{
    void log(const string &message)
    {
        cout << message << endl;
    }

    void exit_with_error(const string &error_message)
    {
        cerr<<"ERROR: " + error_message <<endl;
        exit(1);
    }
}