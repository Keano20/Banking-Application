#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include <vector>
#include <memory>
#include "Account.h"
#include "interface/Observer.h"

// Implements the Singleton Pattern to manage all account operations centrally
class BankManager {
private:
    std::vector<std::shared_ptr<Account>> accounts; // List of all account
    int nextAccountId = 1; // Auto-increment ID tracker
    Observer* logger = nullptr; // Attached observer for logging (Observer pattern)

    // Private constructor to enforce the singleton pattern
    BankManager() = default;

public:
    // Disable copy and move to ensure only one instance
    BankManager(const BankManager&) = delete;
    BankManager& operator=(const BankManager&) = delete;

    // Returns the single instance of BankManager
    static BankManager& getInstance();

    // Account management methods
    void createAccount(const std::string& type, const std::string& owner, float initialBalance);
    void showAccounts() const;
    void applyInterestToAllAccounts();
    bool depositToAccount(int accountId, float amount);
    bool withdrawFromAccount(int accountId, float amount);
    void registerObserver(Observer* obs);
};

#endif //BANKMANAGER_H
