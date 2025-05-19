#ifndef ACCOUNTFACTORY_H
#define ACCOUNTFACTORY_H

#include <memory>
#include <string>
#include "Account.h"

// Implements the Factory Pattern to create specific account types
class AccountFactory {
  public:
    // Returns a new Account object based on the given type
    static std::unique_ptr<Account> createAccount(const std::string& type, int id, const std::string& owner, float initialBalance);
};



#endif //ACCOUNTFACTORY_H
