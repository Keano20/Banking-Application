#ifndef TRANSACTIONLOGGER_H
#define TRANSACTIONLOGGER_H

#include "interface/Observer.h"
#include <vector>
#include <string>

// Implements the Observer interface to log transaction messages
class TransactionLogger : public Observer {
    private:
      std::vector<std::string> logs; // Stores logged messages

    public:
      // Called when an event occurs; stores the message
      void notify(const std::string& message) override;

      // Displays all stored log messages
      void showLogs() const;
};

#endif //TRANSACTIONLOGGER_H
