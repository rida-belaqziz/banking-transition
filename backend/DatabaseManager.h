#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <sqlite3.h>
#include <string>
#include <iostream>

class DatabaseManager {
public:
    DatabaseManager(const std::string &dbName) {
        if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK) {
            std::cerr << "Erreur lors de l'ouverture de la base de données : " << sqlite3_errmsg(db) << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    ~DatabaseManager() {
        sqlite3_close(db);
    }

    void initialize() {
        const char *sql = R"(
            CREATE TABLE IF NOT EXISTS users (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                card_number TEXT NOT NULL,
                expiry_date TEXT NOT NULL,
                cvv TEXT NOT NULL,
                amount REAL NOT NULL
            );
        )";

        char *errMsg = nullptr;
        if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
            std::cerr << "Erreur lors de la création de la table : " << errMsg << std::endl;
            sqlite3_free(errMsg);
            exit(EXIT_FAILURE);
        } else {
            std::cout << "Table 'users' initialisée avec succès." << std::endl;
        }
    }

    sqlite3 *getDb() {
        return db;
    }

private:
    sqlite3 *db;
};

#endif // DATABASEMANAGER_H
