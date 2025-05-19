#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

// Subclass of account representing a savings account
class SavingsAccount : public Account {
public:
    // Constructs a savings account with the given ID, owner name, and initial balance
    SavingsAccount(int id, const std::string& owner, float initialBalance);

    // Calculates and applies interest to the savings account balance
    void calculateInterest() override;
};

#endif