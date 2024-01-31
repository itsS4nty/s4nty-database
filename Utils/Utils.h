#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

enum Commands {
    USE,
    SELECT,
    CREATE,
    DISPLAY,
    UNKNOWN
};

Commands resolveCommand(const string& command);
string extractCommandArgument(const string& command);
string extractNameCreate(const string& option);

#endif // UTILS_H
