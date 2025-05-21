#include <iostream>
#include <limits>
#include "BankManager.h"
#include "TransactionLogger.h"


// Displays the list of available menu options
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

// Pauses execution and waits for the user to press Enter
void waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main() {
    // Get the singleton instance of BankManager
    BankManager& manager = BankManager::getInstance();

    // Create and register the transaction logger (Observer)
    TransactionLogger logger;
    manager.registerObserver(&logger);

    bool running = true;

    while (running) {
        showMenu();
        int choice;
        std::cin >> choice;

        // Validate menu input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            waitForEnter();
            continue;
        }

        switch (choice) {
            case 1: {
                // Create a new account
                std::string type, name;
                float initialBalance;

                std::cout << "Enter account type (savings/current): ";
                std::cin >> type;

                std::cout << "Enter account holder name: ";
                std::cin >> name;

                std::cout << "Enter initial balance (GBP): ";
                std::cin >> initialBalance;

                // Validate balance input
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
                // Deposit funds into an account
                int id;
                float amount;

                std::cout << "Enter account ID to deposit to: ";
                std::cin >> id;

                std::cout << "Enter amount to deposit (GBP): ";
                std::cin >> amount;

                // Validate deposit input
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
                // Withdraw fund from an account
                int id;
                float amount;

                std::cout << "Enter account ID to withdraw from: ";
                std::cin >> id;

                std::cout << "Enter amount to withdraw (GBP): ";
                std::cin >> amount;

                // Validate withdrawal input
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
                // Apply interest to all accounts
                manager.applyInterestToAllAccounts();
                waitForEnter();
                break;
            case 5:
                // Display all account details
                manager.showAccounts();
                waitForEnter();
                break;
            case 6:
                // Display all logged transactions
                logger.showLogs();
                waitForEnter();
                break;
            case 7:
                // Exit the application
                std::cout << "Exiting...\n";
                running = false;
                break;
            default:
                // Handle invalid menu choice
                std::cout << "Invalid option. Please try again.\n";
                waitForEnter();
                break;
        }
    }

    return 0;
}