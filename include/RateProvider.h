#ifndef RATE_PROVIDER_H
#define RATE_PROVIDER_H

#include "types.h"
#include <map>
#include <string>

class RateProvider {
public:
    double getRate(Currency from, Currency to) const;
    void updateRate(Currency from, Currency to, double value);

private:
    std::map<std::string, double> rates;
    static std::string keyFor(Currency from, Currency to);
};

#endif
