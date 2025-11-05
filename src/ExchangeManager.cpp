#include "ExchangeManager.h"
#include "constants.h"
#include <cmath>

ExchangeManager::ExchangeManager(RateProvider& rp, CurrencyRepository& repo, BonusService& bs,
                                 ReportService& rs, ReceiptService& rcpt, IClock& clock)
    : rateProvider(rp), repository(repo), bonusSvc(bs), reportSvc(rs), receiptSvc(rcpt), clk(clock), profit(0.0) {}

double ExchangeManager::processTransaction(double amount, Currency from, Currency to, IExchangeOperation& op) {
    double rate = rateProvider.getRate(from, to);

    double converted = op.processExchange(amount, from, to, rate);

    const double feeRate = constants::EXCHANGE_FEE;
    double exchangedAmount = 0.0;
    if (rate > 0.0 && (1.0 - feeRate) > 0.0) {
        exchangedAmount = converted / (rate * (1.0 - feeRate));
    }
    if (exchangedAmount < 0.0) exchangedAmount = 0.0;
    if (exchangedAmount > amount) exchangedAmount = amount;

    double returnedAmount = amount - exchangedAmount;

    repository.updateReserve(from, +exchangedAmount);
    repository.updateReserve(to, -converted);

    double gross = exchangedAmount * rate;
    double fee = gross - converted;
    profit += fee;

    lastReceipt = receiptSvc.buildReceipt(amount, from, to, rate, converted, clk.nowDate());
    lastReceipt.exchangedAmount = exchangedAmount;
    lastReceipt.returnedAmount = returnedAmount;

    return converted;
}

std::string ExchangeManager::getLastReceiptString() const {
    return lastReceipt.toString();
}

std::string ExchangeManager::generateDailyReport() const {
    double bonus = bonusSvc.calculateBonus(profit);
    auto report = reportSvc.buildDailyReport(repository.getOpeningBalances(),
                                             repository.getCurrentBalances(),
                                             profit, bonus, clk.nowDate());
    return report.toString();
}

double ExchangeManager::getProfit() const {
    return profit;
}

void ExchangeManager::resetProfit() {
    profit = 0.0;
}
