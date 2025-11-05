#include "RateProvider.h"
#include <stdexcept>

std::string RateProvider::keyFor(Currency from, Currency to) {
    return to_string(from) + "->" + to_string(to);
}

double RateProvider::getRate(Currency from, Currency to) const {
    auto key = keyFor(from, to);
    auto it = rates.find(key);
    if (it == rates.end())
        throw std::runtime_error("Rate not found for " + key);
    return it->second;
}

void RateProvider::updateRate(Currency from, Currency to, double value) {
    rates[keyFor(from, to)] = value;
}
