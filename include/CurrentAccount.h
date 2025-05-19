#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"

// Subclass of Account representing a current account
class CurrentAccount : public Account {
public:
    // Constructs a current account with the given ID, owner name, and initial balance
    CurrentAccount(int id, const std::string& owner, float initialBalance);

    // Calculates and applies interest to the current account balance
    void calculateInterest() override;
};

#endif