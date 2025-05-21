#include "BankManager.h"
#include "AccountFactory.h"
#include <iostream>

// Returns the singleton instance of BankManager
BankManager& BankManager::getInstance() {
    static BankManager instance;
    return instance;
}

// Creates a new account using the factory and adds it to the list
void BankManager::createAccount(const std::string& type, const std::string& owner, float initialBalance) {
    auto account = AccountFactory::createAccount(type, nextAccountId, owner, initialBalance);
    if (account) {
        std::cout << "Created " << type << " account for " << owner
                  << " with ID: " << nextAccountId << " and balance (GBP): " << account->getBalance() << "\n";

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

// Displays details for all registered accounts
void BankManager::showAccounts() const {
    std::cout << "\n--- Account Summary ---\n";
    for (const auto& acc : accounts) {
        std::cout << "ID: " << acc->getId()
                  << " | Owner: " << acc->getOwnerName()
                  << " | Balance (GBP): " << acc->getBalance() << "\n";
    }
    std::cout << "------------------------\n";
}

// Deposits an amount into the matching account
bool BankManager::depositToAccount(int accountId, float amount) {
    for (const auto& acc : accounts) {
        if (acc->getId() == accountId) {
            acc->deposit(amount);

            if (logger) {
                logger->notify("Deposited (GBP): " + std::to_string(amount) + " to account ID " + std::to_string(accountId));
            }
            return true;
        }
    }
    return false;
}

// Withdraws an amount from the matching account
bool BankManager::withdrawFromAccount(int accountId, float amount) {
    for (const auto& acc : accounts) {
        if (acc->getId() == accountId) {
            bool success = acc->withdraw(amount);

            if (success && logger) {
                logger->notify("Withdrew (GBP): " + std::to_string(amount) + " from account ID " + std::to_string(accountId));
            }
            return success;
        }
    }
    return false;
}

// Applies interest to all accounts in the system
void BankManager::applyInterestToAllAccounts() {
    std::cout << "\nApplying interest to all accounts...\n";
    for (const auto& acc : accounts) {
        acc->calculateInterest();

        if (logger) {
            logger->notify("Applied interest to account ID " + std::to_string(acc->getId()));
        }
    }
}

// Registers an observer for logging events
void BankManager::registerObserver(Observer* obs) {
    logger = obs;
}