#include <iostream>
#include <memory>
#include "AccountFactory.h"

int main() {
    std::cout << "Program started\n";
    // Create a test savings account
    std::unique_ptr<Account> savings = AccountFactory::createAccount("savings", 1, "Alice", 1000.0f);

    if (savings) {
        std::cout << "Created Savings Account for " << savings->getOwnerName()
                  << " with balance £" << savings->getBalance() << "\n";

        savings->calculateInterest();
        std::cout << "After interest: £" << savings->getBalance() << "\n";
    }

    // Create a test current account
    std::unique_ptr<Account> current = AccountFactory::createAccount("current", 2, "Bob", 500.0f);

    if (current) {
        std::cout << "Created Current Account for " << current->getOwnerName()
                  << " with balance £" << current->getBalance() << "\n";

        current->deposit(250.0f);
        std::cout << "After deposit: £" << current->getBalance() << "\n";

        if (current->withdraw(100.0f)) {
            std::cout << "After withdrawal: £" << current->getBalance() << "\n";
        } else {
            std::cout << "Withdrawal failed (insufficient funds)\n";
        }
    }

    return 0;
}