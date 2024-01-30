#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

class Database {
    std::string currentDatabase;
    std::vector<std::string> databases;

public:
    Database();
    std::string getPrompt() const;
    void useDatabase(const std::string& dbName);
    void select();
};

#endif // DATABASE_H
