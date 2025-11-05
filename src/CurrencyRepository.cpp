#include "CurrencyRepository.h"

std::map<Currency, double> CurrencyRepository::setOpeningBalances(const std::map<Currency, double>& m) {
    opening = m;
    balances = m;
    return opening;
}

double CurrencyRepository::getReserve(Currency c) const {
    auto it = balances.find(c);
    return (it == balances.end()) ? 0.0 : it->second;
}

bool CurrencyRepository::updateReserve(Currency c, double delta) {
    balances[c] = getReserve(c) + delta;
    return true;
}

std::map<Currency, double> CurrencyRepository::getCurrentBalances() const {
    return balances;
}

std::map<Currency, double> CurrencyRepository::getOpeningBalances() const {
    return opening;
}
