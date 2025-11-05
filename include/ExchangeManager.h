#ifndef EXCHANGE_MANAGER_H
#define EXCHANGE_MANAGER_H

#include "types.h"
#include "RateProvider.h"
#include "CurrencyRepository.h"
#include "BonusService.h"
#include "ReportService.h"
#include "ReceiptService.h"
#include "IExchangeOperation.h"
#include "IClock.h"
#include <string>

class ExchangeManager {
public:
    ExchangeManager(RateProvider& rp, CurrencyRepository& repo, BonusService& bs,
                    ReportService& rs, ReceiptService& rcpt, IClock& clock);

    double processTransaction(double amount, Currency from, Currency to, IExchangeOperation& op);
    std::string getLastReceiptString() const;
    std::string generateDailyReport() const;
    double getProfit() const;
    void resetProfit();

private:
    RateProvider& rateProvider;
    CurrencyRepository& repository;
    BonusService& bonusSvc;
    ReportService& reportSvc;
    ReceiptService& receiptSvc;
    IClock& clk;

    mutable double profit;
    Receipt lastReceipt;
};

#endif
