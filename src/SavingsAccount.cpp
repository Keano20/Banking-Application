#include "SavingsAccount.h"

// Constructor that forwards values to the base Account class
SavingsAccount::SavingsAccount(int id, const std::string& owner, float initialBalance)
    : Account(id, owner, initialBalance) {}

// Applies 3% interest to the savings account balance
void SavingsAccount::calculateInterest() {
    float interestRate = 0.03f; // 3%
    balance += balance * interestRate;
}