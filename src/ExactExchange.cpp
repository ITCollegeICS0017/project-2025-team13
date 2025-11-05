#include "ExactExchange.h"
#include <cmath>

static double round_money(double v) {
    double factor = std::pow(10.0, constants::ROUNDING_SCALE);
    return std::round(v * factor) / factor;
}

double ExactExchange::processExchange(double amount, Currency, Currency, double rate) {
    const double gross = amount * rate;
    const double fee = gross * constants::EXCHANGE_FEE;
    const double net = round_money(gross - fee);
    return net;
}