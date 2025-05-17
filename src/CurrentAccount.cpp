#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(int id, const std::string& owner, float initialBalance)
    : Account(id, owner, initialBalance) {}

void CurrentAccount::calculateInterest() {
    float interestRate = 0.01f; // 1%
    balance += balance * interestRate;
}