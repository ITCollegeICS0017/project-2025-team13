#include "ConsoleUI.h"
#include "RealClock.h"

int main() {
    RateProvider rates;
    rates.updateRate(Currency::USD, Currency::EUR, 0.9);
    rates.updateRate(Currency::EUR, Currency::USD, 1.1);
    rates.updateRate(Currency::USD, Currency::GBP, 0.78);
    rates.updateRate(Currency::GBP, Currency::USD, 1.28);
    rates.updateRate(Currency::EUR, Currency::GBP, 0.86);
    rates.updateRate(Currency::GBP, Currency::EUR, 1.16);

    CurrencyRepository repo;
    repo.setOpeningBalances({
        {Currency::USD, 10000.0},
        {Currency::EUR,  8000.0},
        {Currency::GBP,  7000.0}
    });

    BonusService bonus;
    ReportService reportService;
    ReceiptService receiptService;
    RealClock clock;

    ExchangeManager manager(rates, repo, bonus, reportService, receiptService, clock);
    ConsoleUI ui(manager);
    ui.run();

    return 0;
}
