#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account {
public:
    CurrentAccount(int id, const std::string& owner, float initialBalance);
    void calculateInterest() override;
};

#endif