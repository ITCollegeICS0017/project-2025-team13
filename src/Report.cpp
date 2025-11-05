#include "Report.h"
#include <sstream>
#include <iomanip>

std::string Report::toString() const {
    auto bal_to_str = [](const std::map<Currency,double>& m){
        std::ostringstream oss;
        for (auto& [cur, val] : m) {
            oss << to_string(cur) << ": " << std::fixed << std::setprecision(2) << val << "  ";
        }
        return oss.str();
    };

    std::ostringstream oss;
    oss << "=== DAILY REPORT ===\n"
        << "Date: " << date << "\n"
        << "Opening: " << bal_to_str(openingBalances) << "\n"
        << "Ending : " << bal_to_str(endingBalances) << "\n"
        << "Profit : " << std::fixed << std::setprecision(2) << profit << "\n"
        << "Bonus  : " << std::fixed << std::setprecision(2) << bonus << "\n";
    return oss.str();
}
