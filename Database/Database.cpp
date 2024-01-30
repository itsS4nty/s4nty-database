#include "Database.h"
#include <iostream>
#include <algorithm>

Database::Database() {
    databases = {"db1", "db2", "db3"};
}

std::string Database::getPrompt() const {
    return currentDatabase.empty() ? "db" : currentDatabase;
}

void Database::useDatabase(const std::string& dbName) {
    if (!dbName.empty() && std::find(databases.begin(), databases.end(), dbName) != databases.end()) {
        currentDatabase = dbName;
        std::cout << "Switched to database: " << dbName << std::endl;
    } else {
        std::cout << "Database " << dbName << " does not exist." << std::endl;
    }
}

void Database::select() {
    if (currentDatabase.empty()) {
        std::cout << "No database selected" << std::endl;
    } else {
        std::cout << "SELECT command executed in " << currentDatabase << std::endl;
    }
}
