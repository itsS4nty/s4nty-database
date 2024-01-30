#ifndef UTILS_H
#define UTILS_H

#include <string>

enum Commands {
    USE,
    SELECT,
    UNKNOWN
};

Commands resolveCommand(const std::string& command);
std::string extractCommandArgument(const std::string& command);

#endif // UTILS_H
