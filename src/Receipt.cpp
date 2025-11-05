#include "Receipt.h"
#include <sstream>
#include <iomanip>

std::string Receipt::toString() const {
    std::ostringstream oss;
    oss << "=== RECEIPT ===\n"
        << "Date: " << date << "\n"
        << "From: " << to_string(currencyFrom) << "\n"
        << "To:   " << to_string(currencyTo) << "\n"
        << "Rate: " << std::fixed << std::setprecision(6) << rate << "\n"
        << "Amount given: " << std::setprecision(2) << std::fixed << amount << " " << to_string(currencyFrom) << "\n";
    if (returnedAmount > 0.0) {
        oss << "Exchanged: " << std::setprecision(2) << exchangedAmount << " " << to_string(currencyFrom) << "\n"
            << "Returned:  " << std::setprecision(2) << returnedAmount << " " << to_string(currencyFrom) << "\n";
    }
    oss << "Converted (after fee): " << std::setprecision(2) << converted << " " << to_string(currencyTo) << "\n";
    return oss.str();
}