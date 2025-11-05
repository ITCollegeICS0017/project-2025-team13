#ifndef RECEIPT_SERVICE_H
#define RECEIPT_SERVICE_H

#include "Receipt.h"

class ReceiptService {
public:
    Receipt buildReceipt(double amount, Currency from, Currency to, double rate,
                         double converted, const std::string& date) const;
};

#endif
