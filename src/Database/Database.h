#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

using namespace std;

struct DatabaseInfo {
    string name;
    int totalTables;
    vector<string> tables;
};

class Database {
    string currentDatabase;
    vector<string> databases;
    

public:
    Database();
    string getPrompt() const;
    void useDatabase(const string& dbName);
    void select();
    void create(const string& option, const string& name);
    void display();
};

#endif // DATABASE_H
