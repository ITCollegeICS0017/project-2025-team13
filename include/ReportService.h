#ifndef REPORT_SERVICE_H
#define REPORT_SERVICE_H

#include "Report.h"
#include <map>
#include <string>

class ReportService {
public:
    Report buildDailyReport(const std::map<Currency,double>& openingBalances,
                            const std::map<Currency,double>& endingBalances,
                            double profit, double bonus, const std::string& date) const;
};

#endif
