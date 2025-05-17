#include <iostream>
#include <memory>
#include "BankManager.h"

int main() {
    BankManager& manager = BankManager::getInstance();

    std::cout << "Creating accounts...\n";

    manager.createAccount("savings", "Keano", 100.0f);
    manager.createAccount("current", "Jan", 500000.0f);
    manager.createAccount("savings", "Joe", 12000.0f);
    manager.createAccount("current", "Ahmed", 800.0f);
    manager.createAccount("savings", "Ethan", 550.0f);

    std::cout << "\nDepositing £200 to account ID 1...\n";
    if (!manager.depositToAccount(1, 200.0f)) {
        std::cout << "Deposit failed.\n";
    }

    std::cout << "Withdrawing £125000 from account ID 2...\n";
    if (!manager.withdrawFromAccount(2, 125000.0f)) {
        std::cout << "Withdrawal failed.\n";
    }

    std::cout << "Depositing £150 to account ID 3...\n";
    if (!manager.depositToAccount(3, 150.0f)) {
        std::cout << "Deposit failed.\n";
    }

    std::cout << "Withdrawing £75 from account ID 4...\n";
    if (!manager.withdrawFromAccount(4, 75.0f)) {
        std::cout << "Withdrawal failed.\n";
    }

    std::cout << "Depositing £100 to account ID 5...\n";
    if (!manager.depositToAccount(5, 100.0f)) {
        std::cout << "Deposit failed.\n";
    }

    manager.applyInterestToAllAccounts();

    std::cout << "\nFinal Account Summary:\n";
    manager.showAccounts();

    return 0;
}