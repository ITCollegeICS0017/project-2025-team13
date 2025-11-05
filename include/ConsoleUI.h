#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "ExchangeManager.h"
#include "ExactExchange.h"
#include "PartialExchange.h"
#include <string>

class ConsoleUI {
public:
    explicit ConsoleUI(ExchangeManager& mgr);
    void run();

private:
    ExchangeManager& manager;

    int      displayMenu();
    double   readAmount(const std::string& prompt = "Enter amount: ");
    Currency readCurrency(const std::string& prompt);
    void     showError(const std::string& msg);
};

#endif