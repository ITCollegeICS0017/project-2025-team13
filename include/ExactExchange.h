#ifndef EXACT_EXCHANGE_H
#define EXACT_EXCHANGE_H
#include "IExchangeOperation.h"
#include "constants.h"

class ExactExchange : public IExchangeOperation {
public:
    double processExchange(double amount, Currency from, Currency to, double rate) override;
};
#endif