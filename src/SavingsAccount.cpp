#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(int id, const std::string& owner, float initialBalance)
    : Account(id, owner, initialBalance) {}

void SavingsAccount::calculateInterest() {
    float interestRate = 0.03f; // 3%
    balance += balance * interestRate;
}