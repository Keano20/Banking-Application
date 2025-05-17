#include "AccountFactory.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include <algorithm>

std::unique_ptr<Account> AccountFactory::createAccount(const std::string& type, int id, const std::string& owner, float initialBalance) {
  std::string lowercaseType = type;
  std::transform(lowercaseType.begin(), lowercaseType.end(), lowercaseType.begin(), ::tolower);

  if (lowercaseType == "savings") {
    return std::make_unique<SavingsAccount>(id, owner, initialBalance);
  }
  if (lowercaseType == "current") {
    return std::make_unique<CurrentAccount>(id, owner, initialBalance);
  }else {
    return nullptr;
  }
}