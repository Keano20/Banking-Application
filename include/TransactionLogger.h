#ifndef TRANSACTIONLOGGER_H
#define TRANSACTIONLOGGER_H

#include "interface/Observer.h"
#include <vector>
#include <string>

class TransactionLogger : public Observer {
    private:
      std::vector<std::string> logs;

    public:
      void notify(const std::string& message) override;
      void showLogs() const;
};

#endif //TRANSACTIONLOGGER_H
