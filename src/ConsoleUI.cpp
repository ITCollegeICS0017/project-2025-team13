#include "ConsoleUI.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>

static std::string to_upper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return static_cast<char>(std::toupper(c)); });
    return s;
}

ConsoleUI::ConsoleUI(ExchangeManager& mgr) : manager(mgr) {}

void ConsoleUI::run() {
    for (;;) {
        int choice = displayMenu();
        if (choice == 4) {
            std::cout << "Bye!\n";
            break;
        }
        else if (choice == 3) {
            std::cout << manager.generateDailyReport() << "\n";
        }
        else {
            try {
                double amount = readAmount("Enter amount: ");
                Currency from = readCurrency("Enter source currency (USD/EUR/GBP): ");
                Currency to = readCurrency("Enter target currency (USD/EUR/GBP): ");

                if (choice == 1) {
                    ExactExchange ex;
                    manager.processTransaction(amount, from, to, ex);
                }
                else if (choice == 2) {
                    double target = readAmount("Enter partial target amount (in source currency): ");
                    PartialExchange px(target);
                    manager.processTransaction(amount, from, to, px);
                }

                std::cout << manager.getLastReceiptString() << "\n";
            }
            catch (const std::exception& ex) {
                showError(ex.what());
            }
        }
    }
}

int ConsoleUI::displayMenu() {
    for (;;) {
        std::cout << "==============================\n"
            << "1) Exact exchange\n"
            << "2) Partial exchange\n"
            << "3) View report\n"
            << "4) Exit\n"
            << "Choose: ";

        int c;
        if (std::cin >> c) {
            if (c >= 1 && c <= 4) {
                return c;
            }
            showError("Please enter 1, 2, 3, or 4.");
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            showError("Please enter a number.");
        }
    }
}

double ConsoleUI::readAmount(const std::string& prompt) {
    for (;;) {
        std::cout << prompt;

        double a;
        if (std::cin >> a) {
            if (a > 0.0) {
                return a;
            }
            showError("Amount must be > 0.");
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            showError("Not a valid number. Try again.");
        }
    }
}

Currency ConsoleUI::readCurrency(const std::string& prompt) {
    for (;;) {
        std::cout << prompt;

        std::string s;
        if (std::cin >> s) {
            s = to_upper(s);
            if (s == "USD" || s == "EUR" || s == "GBP") {
                return currency_from_string(s);
            }
            showError("Use USD, EUR, or GBP.");
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            showError("Invalid input. Try again.");
        }
    }
}

void ConsoleUI::showError(const std::string& msg) {
    std::cerr << "[ERROR] " << msg << "\n";
}