#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
  protected:
    int accountId;
    std::string ownerName;
    float balance;

  public:
    Account(int id, const std::string& owner, float initialBalance);
    virtual ~Account() = default;

    virtual void calculateInterest() = 0;
    void deposit(float amount);
    bool withdraw(float amount);
    float getBalance() const;
    int getId() const;
    std::string getOwnerName() const;
};



#endif //ACCOUNT_H
