#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "../Database/Database.h"
#include <string>

class CommandParser {
public:
    void executeCommand(const std::string& command, Database& db);
};

#endif // COMMANDPARSER_H
