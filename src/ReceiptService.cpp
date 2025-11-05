#include "ReceiptService.h"

Receipt ReceiptService::buildReceipt(double amount, Currency from, Currency to, double rate,
                                     double converted, const std::string& date) const {
    Receipt r;
    r.amount = amount;
    r.currencyFrom = from;
    r.currencyTo = to;
    r.rate = rate;
    r.converted = converted;
    r.date = date;
    return r;
}
