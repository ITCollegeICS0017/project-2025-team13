#ifndef IEXCHANGE_OPERATION_H
#define IEXCHANGE_OPERATION_H
#include "types.h"

struct IExchangeOperation {
    virtual ~IExchangeOperation() = default;
    virtual double processExchange(double amount, Currency from, Currency to, double rate) = 0;
};
#endif