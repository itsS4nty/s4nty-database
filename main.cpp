#include "CommandParser/CommandParser.h"
#include "Database/Database.h"
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    CommandParser parser;
    Database db;
    std::string command;

    while (true) {
        std::cout << db.getPrompt() << "> ";
        std::getline(std::cin, command);

        if (command == "exit") {
            std::cout << "Exiting..." << std::endl;
            break;
        }

        parser.executeCommand(command, db);
    }
    return 0;
}


// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <map>

// enum Commands {
//     USE,
//     SELECT,
//     UNKNOWN
// };

// Commands resolveCommand(const std::string& command) {
//     static const std::map<std::string, Commands> commandsString {
//         { "use", USE },
//         { "select", SELECT },
//     };

//     auto spaceIndex = command.find(" ");
//     std::string cmd = spaceIndex != std::string::npos ? command.substr(0, spaceIndex) : command;

//     auto it = commandsString.find(cmd);
//     if(it != commandsString.end()) {
//         return it->second;
//     }
//     return UNKNOWN;
// }

// int main(int argc, char const *argv[])
// {
//     std::string prompt = "db";
//     std::string command;
//     std::string database;
//     std::vector<std::string> databases = {"db1", "db2", "db3"};

//     while(true) {
//         std::cout << prompt << "> ";
//         std::getline(std::cin, command);

//         if(command == "exit") {
//             std::cout << "Exiting..." << std::endl;
//             break;
//         }

//         Commands cmd = resolveCommand(command.substr(0, command.find(" ")));
        
//         switch (cmd)
//         {
//             case USE: {
//                 auto spaceIndex = command.find(" ") + 1;
//                 std::string dbName = spaceIndex < command.size() ? command.substr(spaceIndex) : "";
        
//                 if(!dbName.empty() && std::find(databases.begin(), databases.end(), dbName) != databases.end()) {
//                     database = dbName;
//                     prompt = database;
//                     std::cout << "Switched to database: " << database << std::endl;
//                 } else {
//                     std::cout << "Database " << dbName << " does not exists." << std::endl;
//                 }
//                 break;
//             }
//             case SELECT:
//                 if(database == "") {
//                     std::cout << "Any database selected" << std::endl;
//                     continue;
//                 }
//                 std::cout << "SELECT command executed" << std::endl;
//                 break; 
//             case UNKNOWN:
//                 std::cout << "Unknown command: " << command << std::endl;
//                 break;
//             default:
//                 break;
//         }
//     }
//     return 0;
// }
