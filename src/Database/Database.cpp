#include "Database.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

Database::Database() {
    databases = {"db1", "db2", "db3"};
}

string Database::getPrompt() const {
    return currentDatabase.empty() ? "db" : currentDatabase;
}

void Database::useDatabase(const string& dbName) {
    if (!dbName.empty() && find(databases.begin(), databases.end(), dbName) != databases.end()) {
        currentDatabase = dbName;
        cout << "Switched to database: " << dbName << endl;
    } else {
        cout << "Database " << dbName << " does not exist." << endl;
    }
}

void Database::select() {
    if (currentDatabase.empty()) {
        cout << "No database selected" << endl;
    } else {
        cout << "SELECT command executed in " << currentDatabase << endl;
    }
}

void Database::create(const string& option, const string& name) {
    if(option == "table") {

    } else if(option == "database") {
        string dbName = name;
        string path = "databases/" + dbName + ".bin";
        ofstream outFile(path, ios::binary);
        if(!outFile.is_open()) {
            cerr << "Failed to open the file" << endl;
            return;
        }

        DatabaseInfo data = { dbName, 1, vector<string>() };
        
        outFile.write(reinterpret_cast<char*>(&data), sizeof(data));
        if(!outFile.good()) {
            cerr << "Error while creating the database" << endl;
            return;
        }

        outFile.close();
    } else {
        cerr << "Unknown command: " << option << endl;
    }
}

void Database::display() {
    string dbName = "test";
    string path = "databases/" + dbName + ".bin";
    DatabaseInfo data;

    ifstream file(path, ios::binary);

    if(!file) {
        cout << "Database not found" << endl;
        return;
    }

    file.read(reinterpret_cast<char*>(&data), sizeof(data));

    if(!file) {
        cout << "Error while retrieving database data" << endl;
        return;
    }

    file.close();

    cout << "Name: " << data.name << endl << "Total tables: " << data.totalTables << endl;
}
