// this release is based on my crc cards, but i did not implement all the classes here, as they are not needed for a simple scenario demonstation
#include <iostream>
#include <string>
#include <iomanip>  // for rounding
using namespace std;

// enum for values
enum class Currency { USD, EUR, GBP };

// used to print currency names
string toString(Currency c) {
    switch (c) {
        case Currency::USD: return "USD";
        case Currency::EUR: return "EUR";
        case Currency::GBP: return "GBP";
        default: return "UNKNOWN";
    }
}

// simple data holder
struct Transaction {
    Currency from;
    Currency to;
    double amountIn;
    double rate;
    double amountOut;

    Transaction(Currency f, Currency t, double amt, double r)
        : from(f), to(t), amountIn(amt), rate(r) {
        amountOut = amt * r;
    }
};

class RateTable {
public:
    double getRate(Currency from, Currency to) {
        // fixed demo values
        if (from == Currency::USD && to == Currency::EUR) return 0.92;
        if (from == Currency::EUR && to == Currency::USD) return 1.09;
        if (from == Currency::USD && to == Currency::GBP) return 0.80;
        return 1.0;
    }
};

class Receipt {
public:
    void print(const Transaction& t) {
        cout << "---- Currency Exchange Receipt ----\n";
        cout << fixed << setprecision(2); // used for rounding
        cout << "From: " << t.amountIn << " " << toString(t.from) << endl;
        cout << "To:   " << t.amountOut << " " << toString(t.to) << endl;
        cout << "Rate: 1 " << toString(t.from) << " = " << t.rate
             << " " << toString(t.to) << endl;
        cout << "----------------------------------\n";
    }
};

class Cashier {
public:
    Transaction exchange(Currency from, Currency to, double amount, RateTable& rates) {
        double rate = rates.getRate(from, to);
        cout << "Cashier starting transaction...\n";
        return Transaction(from, to, amount, rate);
    }
};

int main() {
    RateTable rateTable;
    Cashier cashier;
    Receipt receipt;

    // example user story - exchanging 100 usd to eur
    Transaction t = cashier.exchange(Currency::USD, Currency::EUR, 100.0, rateTable);

    // printing receipt
    receipt.print(t);

    return 0;
}