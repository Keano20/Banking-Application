#include "Account.h"

// Constructor to initialise common account data
Account::Account(int id, const std::string& owner, float initialBalance)
    : accountId(id), ownerName(owner), balance(initialBalance) {}

// Adds the given amount to the account balance
void Account::deposit (float amount) {
    if (amount > 0) balance += amount;
}

// Deducts the given amount from the balance if sufficient funds exist
bool Account::withdraw(float amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

// Returns the current account balance
float Account::getBalance() const {
    return balance;
}

// Returns the account ID
int Account::getId() const {
    return accountId;
}

// Returns the account owners name
std::string Account::getOwnerName() const {
    return ownerName;
}