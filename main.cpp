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
