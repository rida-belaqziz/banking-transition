#include "crow_all.h"
#include "DatabaseManager.h"
#include "UserService.h"

int main() {
    DatabaseManager dbManager("bank.db");
    dbManager.initialize();
    UserService userService(dbManager);

    crow::SimpleApp app;

    // Route pour ajouter un utilisateur
    CROW_ROUTE(app, "/add_user").methods(crow::HTTPMethod::POST)([&userService](const crow::request &req) {
        auto body = crow::json::load(req.body);
        if (!body) {
            return crow::response(400, "Invalid JSON");
        }

        std::string cardNumber = body["card_number"].s();
        std::string expiryDate = body["expiry_date"].s();
        std::string cvv = body["cvv"].s();
        double amount = body["amount"].d();

        userService.addUser(cardNumber, expiryDate, cvv, amount);
        return crow::response(200, "User added successfully");
    });

    // Route pour lister les utilisateurs
    CROW_ROUTE(app, "/list_users")([&userService]() {
        crow::json::wvalue users;
        userService.listUsers();  // Vous pouvez adapter pour retourner un JSON si nécessaire.
        return crow::response(200, "Listing users done!");
    });

    app.port(8080).multithreaded().run();
    return 0;
}
