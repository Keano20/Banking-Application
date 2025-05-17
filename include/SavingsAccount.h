#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount(int id, const std::string& owner, float initialBalance);
    void calculateInterest() override;
};

#endif