#include "ReportService.h"

Report ReportService::buildDailyReport(const std::map<Currency,double>& openingBalances,
                                       const std::map<Currency,double>& endingBalances,
                                       double profit, double bonus, const std::string& date) const {
    Report r;
    r.date = date;
    r.openingBalances = openingBalances;
    r.endingBalances = endingBalances;
    r.profit = profit;
    r.bonus = bonus;
    return r;
}
