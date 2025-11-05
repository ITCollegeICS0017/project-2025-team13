#include "types.h"

std::string to_string(Currency c) {
    switch (c) {
        case Currency::USD: return "USD";
        case Currency::EUR: return "EUR";
        case Currency::GBP: return "GBP";
        default: return "UNKNOWN";
    }
}

Currency currency_from_string(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    if (s == "USD") return Currency::USD;
    if (s == "EUR") return Currency::EUR;
    if (s == "GBP") return Currency::GBP;
    throw std::invalid_argument("Unsupported currency: " + s);
}
