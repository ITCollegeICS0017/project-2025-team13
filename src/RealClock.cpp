#include "RealClock.h"
#include <ctime>
#include <sstream>
#include <iomanip>

std::string RealClock::nowDate() const {
    std::time_t t = std::time(nullptr);
    std::tm tm{};
    localtime_s(&tm, &t);
    std::ostringstream oss;
    oss << std::put_time(&tm, constants::REPORT_DATE_FMT);
    return oss.str();
}