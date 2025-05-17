#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include <vector>
#include <memory>
#include "Account.h"

class BankManager {
private: // Private by default but I thought it would still be useful to show
    std::vector<std::shared_ptr<Account>> accounts;
    int nextAccountId = 1;

    // Private constructor for singleton
    BankManager() = default;

public:
    // Delete copy/move constructors to enforce Singleton
    BankManager(const BankManager&) = delete;
    BankManager& operator=(const BankManager&) = delete;

    // Singleton accessor
    static BankManager& getInstance();

    // Methods
    void createAccount(const std::string& type, const std::string& owner, float initialBalance);
    void showAccounts() const;
    bool depositToAccount(int accountId, float amount);
    bool withdrawFromAccount(int accountId, float amount);
};

#endif //BANKMANAGER_H
