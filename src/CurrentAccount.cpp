#include "CurrentAccount.h"

// Constructor that forwards values to the base Account class
CurrentAccount::CurrentAccount(int id, const std::string& owner, float initialBalance)
    : Account(id, owner, initialBalance) {}

// Applies 1% interest to the current account balance
void CurrentAccount::calculateInterest() {
    float interestRate = 0.01f; // 1%
    balance += balance * interestRate;
}