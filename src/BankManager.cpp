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

        if (logger) {
            logger->notify("Created " + type + " account for " + owner + " (ID: " + std::to_string(nextAccountId) + ")");
        }
        accounts.push_back(std::move(account));
        nextAccountId++;
    } else {
        std::cout << "Failed to create account. Invalid type.\n";
        if (logger) {
            logger->notify("Failed to create account: invalid type '" + type + "'");
        }
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

            if (logger) {
                logger->notify("Deposited £" + std::to_string(amount) + " to account ID " + std::to_string(accountId));
            }
            return true;
        }
    }
    return false;
}

bool BankManager::withdrawFromAccount(int accountId, float amount) {
    for (const auto& acc : accounts) {
        if (acc->getId() == accountId) {
            bool success = acc->withdraw(amount);

            if (success && logger) {
                logger->notify("Withdrew £" + std::to_string(amount) + " from account ID " + std::to_string(accountId));
            }
            return success;
        }
    }
    return false;
}

void BankManager::applyInterestToAllAccounts() {
    std::cout << "\nApplying interest to all accounts...\n";
    for (const auto& acc : accounts) {
        acc->calculateInterest();

        if (logger) {
            logger->notify("Applied interest to account ID " + std::to_string(acc->getId()));
        }
    }
}

void BankManager::registerObserver(Observer* obs) {
    logger = obs;
}