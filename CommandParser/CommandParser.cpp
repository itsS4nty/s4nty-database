#include "CommandParser.h"
#include "../Utils/Utils.h"
#include <iostream>
#include <algorithm>

void CommandParser::executeCommand(const std::string& command, Database& db) {
    Commands cmd = resolveCommand(command);

    switch (cmd) {
        case USE: {
            std::string dbName = extractCommandArgument(command);
            db.useDatabase(dbName);
            break;
        }
        case SELECT: {
            db.select();
            break; 
        }
        case UNKNOWN:
            std::cout << "Unknown command: " << command << std::endl;
            break;
        default:
            break;
    }
}
