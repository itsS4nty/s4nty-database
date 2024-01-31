#include "CommandParser.h"
#include "../../Utils/Utils.h"
#include <iostream>
#include <algorithm>

using namespace std;

void CommandParser::executeCommand(const string& command, Database& db) {
    Commands cmd = resolveCommand(command);

    switch (cmd) {
        case USE: {
            string dbName = extractCommandArgument(command);
            db.useDatabase(dbName);
            break;
        }
        case SELECT: {
            db.select();
            break; 
        }
        case CREATE: {
            string option = extractCommandArgument(command);
            cout << option << endl;
            string name = extractCommandArgument(option);
            cout << name << endl;
            db.create(option, name);
            break;
        }
        case DISPLAY: {
            db.display();
            break;
        }
        case UNKNOWN:
            cout << "Unknown command: " << command << endl;
            break;
        default:
            break;
    }
}
