#include "BankManager.h"
#include "AccountFactory.h"
#include <iostream>

BankManager& BankManager::getInstance() {
    static BankManager instance;
    return instance;
}

void BankManager::createAccount(const std::string& type, const std::string& owner, float initialBalance) {
    auto account = AccountFactory::createAccount(type, nextAccountId, owner, initialBalance);
    if (account) {
        std::cout << "Created " << type << " account for " << owner
                  << " with ID: " << nextAccountId << " and balance: £" << account->getBalance() << "\n";
        accounts.push_back(std::move(account));
        nextAccountId++;
    } else {
        std::cout << "Failed to create account. Invalid type.\n";
    }
}

void BankManager::showAccounts() const {
    std::cout << "\n--- Account Summary ---\n";
    for (const auto& acc : accounts) {
        std::cout << "ID: " << acc->getId()
                  << " | Owner: " << acc->getOwnerName()
                  << " | Balance: £" << acc->getBalance() << "\n";
    }
    std::cout << "------------------------\n";
}

bool BankManager::depositToAccount(int accountId, float amount) {
    for (const auto& acc : accounts) {
        if (acc->getId() == accountId) {
            acc->deposit(amount);
            return true;
        }
    }
    return false;
}

bool BankManager::withdrawFromAccount(int accountId, float amount) {
    for (const auto& acc : accounts) {
        if (acc->getId() == accountId) {
            return acc->withdraw(amount);
        }
    }
    return false;
}