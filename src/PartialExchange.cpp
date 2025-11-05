#include "PartialExchange.h"
#include <cmath>

static double round_partial(double v) {
    double factor = std::pow(10.0, constants::ROUNDING_SCALE);
    return std::round(v * factor) / factor;
}

PartialExchange::PartialExchange(double partialTarget) : target(partialTarget) {}

double PartialExchange::processExchange(double amount, Currency, Currency, double rate) {
    const double toConvert = (amount < target) ? amount : target;
    const double gross = toConvert * rate;
    const double fee = gross * constants::EXCHANGE_FEE;
    const double net = round_partial(gross - fee);
    return net;
}