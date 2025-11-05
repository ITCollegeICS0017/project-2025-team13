#ifndef REPORT_H
#define REPORT_H

#include "types.h"
#include <map>
#include <string>

struct Report {
    std::string date;
    std::map<Currency,double> openingBalances;
    std::map<Currency,double> endingBalances;
    double profit{0.0};
    double bonus{0.0};

    std::string toString() const;
};

#endif
