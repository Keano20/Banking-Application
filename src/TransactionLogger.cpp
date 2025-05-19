#include "TransactionLogger.h"
#include <iostream>

// Stores the received message in the log history
void TransactionLogger::notify(const std::string& message) {
    logs.push_back(message);
}

// Displays all stored log messages
void TransactionLogger::showLogs() const {
    std::cout << "\n=== Transaction Log ===\n";
    for (const auto& log : logs) {
        std::cout << log << "\n";
    }
    std::cout << "========================\n";
}
