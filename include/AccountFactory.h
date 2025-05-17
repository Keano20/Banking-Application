#ifndef ACCOUNTFACTORY_H
#define ACCOUNTFACTORY_H

#include <memory>
#include <string>
#include "Account.h"

// Implements Factory Pattern
class AccountFactory {
  public:
    static std::unique_ptr<Account> createAccount(const std::string& type, int id, const std::string& owner, float initialBalance);
};



#endif //ACCOUNTFACTORY_H
