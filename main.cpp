#include <iostream>
#include "BankManager.h"

void showMenu() {
    std::cout << "\n======= Bank Menu =======\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Apply Interest\n";
    std::cout << "5. View All Accounts\n";
    std::cout << "6. Exit\n";
    std::cout << "=========================\n";
    std::cout << "Select an option: ";
}
void waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

int main() {
    BankManager& manager = BankManager::getInstance();
    bool running = true;

    while (running) {
        showMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string type, name;
                float initialBalance;
                std::cout << "Enter account type (savings/current): ";
                std::cin >> type;
                std::cout << "Enter account holder name: ";
                std::cin >> name;
                std::cout << "Enter initial balance: £";
                std::cin >> initialBalance;
                manager.createAccount(type, name, initialBalance);
                waitForEnter();
                manager.showAccounts();
                break;
            }
            case 2: {
                int id;
                float amount;
                std::cout << "Enter account ID to deposit to: ";
                std::cin >> id;
                std::cout << "Enter amount to deposit: £";
                std::cin >> amount;
                if (!manager.depositToAccount(id, amount)) {
                    std::cout << "Deposit failed.\n";
                }
                break;
            }
            case 3: {
                int id;
                float amount;
                std::cout << "Enter account ID to withdraw from: ";
                std::cin >> id;
                std::cout << "Enter amount to withdraw: £";
                std::cin >> amount;
                if (!manager.withdrawFromAccount(id, amount)) {
                    std::cout << "Withdrawal failed.\n";
                }
                break;
            }
            case 4:
                manager.applyInterestToAllAccounts();
                break;
            case 5:
                manager.showAccounts();
                waitForEnter();
                break;
            case 6:
                std::cout << "Exiting...\n";
                running = false;
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}