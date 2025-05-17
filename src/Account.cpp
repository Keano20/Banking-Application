#include "Account.h"

// Constructor
Account::Account(int id, const std::string& owner, float initialBalance)
    : accountId(id), ownerName(owner), balance(initialBalance) {}

// Method for depositing money
void Account::deposit (float amount) {
    if (amount > 0) balance += amount;
}

// Method for withdrawing money
bool Account::withdraw(float amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

// Returns the account balance
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