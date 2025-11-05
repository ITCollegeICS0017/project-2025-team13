#ifndef CURRENCY_REPOSITORY_H
#define CURRENCY_REPOSITORY_H

#include "types.h"
#include <map>

class CurrencyRepository {
public:
    std::map<Currency, double> setOpeningBalances(const std::map<Currency, double>& m);
    double getReserve(Currency c) const;
    bool updateReserve(Currency c, double delta);
    std::map<Currency, double> getCurrentBalances() const;
    std::map<Currency, double> getOpeningBalances() const;

private:
    std::map<Currency, double> opening;
    std::map<Currency, double> balances;
};

#endif
