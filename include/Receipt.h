#ifndef RECEIPT_H
#define RECEIPT_H

#include "types.h"
#include <string>

struct Receipt {
    Currency currencyFrom{};
    Currency currencyTo{};
    double rate{ 0.0 };
    double amount{ 0.0 };
    double exchangedAmount{ 0.0 };
    double returnedAmount{ 0.0 };
    double converted{ 0.0 };
    std::string date;

    std::string toString() const;
};

#endif