#include <iostream>
#include <limits>
#include "BankManager.h"
#include "TransactionLogger.h"

void showMenu() {
    std::cout << "\n======= Bank Menu =======\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Apply Interest\n";
    std::cout << "5. View All Accounts\n";
    std::cout << "6. View Transaction Log\n";
    std::cout << "7. Exit\n";
    std::cout << "=========================\n";
    std::cout << "Select an option: ";
}

void waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main() {
    BankManager& manager = BankManager::getInstance();
    TransactionLogger logger;
    manager.registerObserver(&logger);

    bool running = true;

    while (running) {
        showMenu();
        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            waitForEnter();
            continue;
        }

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

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number.\n";
                    waitForEnter();
                    break;
                }

                manager.createAccount(type, name, initialBalance);
                manager.showAccounts();
                waitForEnter();
                break;
            }
            case 2: {
                int id;
                float amount;

                std::cout << "Enter account ID to deposit to: ";
                std::cin >> id;

                std::cout << "Enter amount to deposit: £";
                std::cin >> amount;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number.\n";
                    waitForEnter();
                    break;
                }

                if (!manager.depositToAccount(id, amount)) {
                    std::cout << "Deposit failed.\n";
                }

                waitForEnter();
                break;
            }
            case 3: {
                int id;
                float amount;

                std::cout << "Enter account ID to withdraw from: ";
                std::cin >> id;

                std::cout << "Enter amount to withdraw: £";
                std::cin >> amount;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number.\n";
                    waitForEnter();
                    break;
                }

                if (!manager.withdrawFromAccount(id, amount)) {
                    std::cout << "Withdrawal failed.\n";
                }

                waitForEnter();
                break;
            }
            case 4:
                manager.applyInterestToAllAccounts();
                waitForEnter();
                break;
            case 5:
                manager.showAccounts();
                waitForEnter();
                break;
            case 6:
                logger.showLogs();
                waitForEnter();
                break;
            case 7:
                std::cout << "Exiting...\n";
                running = false;
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
                waitForEnter();
                break;
        }
    }

    return 0;
}