#ifndef USERSERVICE_H
#define USERSERVICE_H

#include "DatabaseManager.h"
#include <string>
#include <iostream>

class UserService {
public:
    UserService(DatabaseManager &dbManager) : db(dbManager.getDb()) {}

    void addUser(const std::string &cardNumber, const std::string &expiryDate, const std::string &cvv, double amount) {
        const char *sql = R"(
            INSERT INTO users (card_number, expiry_date, cvv, amount)
            VALUES (?, ?, ?, ?);
        )";

        sqlite3_stmt *stmt;
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Erreur lors de la préparation de l'instruction : " << sqlite3_errmsg(db) << std::endl;
            return;
        }

        sqlite3_bind_text(stmt, 1, cardNumber.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, expiryDate.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, cvv.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_double(stmt, 4, amount);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Erreur lors de l'insertion de l'utilisateur : " << sqlite3_errmsg(db) << std::endl;
        } else {
            std::cout << "Utilisateur ajouté avec succès." << std::endl;
        }

        sqlite3_finalize(stmt);
    }

    void listUsers() {
        const char *sql = "SELECT * FROM users;";
        sqlite3_stmt *stmt;

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Erreur lors de la préparation de l'instruction : " << sqlite3_errmsg(db) << std::endl;
            return;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const char *cardNumber = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            const char *expiryDate = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            const char *cvv = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
            double amount = sqlite3_column_double(stmt, 4);

            std::cout << "ID: " << id << ", Carte: " << cardNumber
                      << ", Expiration: " << expiryDate
                      << ", CVV: " << cvv
                      << ", Montant: " << amount << " EUR" << std::endl;
        }

        sqlite3_finalize(stmt);
    }

private:
    sqlite3 *db;
};

#endif // USERSERVICE_H
