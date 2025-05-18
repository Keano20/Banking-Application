#include "TransactionLogger.h"
#include <iostream>

void TransactionLogger::notify(const std::string& message) {
    logs.push_back(message);
}

void TransactionLogger::showLogs() const {
    std::cout << "\n=== Transaction Log ===\n";
    for (const auto& log : logs) {
        std::cout << log << "\n";
    }
    std::cout << "========================\n";
}