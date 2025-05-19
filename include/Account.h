#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

// Abstract base class for all account types
class Account {
  protected:
    int accountId;          //Unique identifier for the account
    std::string ownerName;  // Name of the account holder
    float balance;          // Current account balance

  public:
    // Constructor to initialise common account fields
    Account(int id, const std::string& owner, float initialBalance);

    // Ensures the correct destruction of derived account types
    virtual ~Account() = default;

    // Pure virtual method to be implemented by subclasses for applying interest
    virtual void calculateInterest() = 0;

    // Adds funds to the account
    void deposit(float amount);

    // Removes fund from the account but only if a sufficient balance is available
    bool withdraw(float amount);

    // Get methods (Accessors)
    float getBalance() const;
    int getId() const;
    std::string getOwnerName() const;
};



#endif //ACCOUNT_H
