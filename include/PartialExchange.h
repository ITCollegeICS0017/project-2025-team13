#ifndef PARTIAL_EXCHANGE_H
#define PARTIAL_EXCHANGE_H
#include "IExchangeOperation.h"
#include "constants.h"

class PartialExchange : public IExchangeOperation {
public:
    explicit PartialExchange(double partialTarget);
    double processExchange(double amount, Currency from, Currency to, double rate) override;
private:
    double target;
};
#endif