#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() const {
        return amount * exchangeRate;
    }

    virtual void displayCurrency() const {
        cout << currencySymbol << amount << " (" << currencyCode << ")\n";
    }

    virtual double convertTo(const Currency& targetCurrency) const {
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency.exchangeRate;
    }

    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    double convertToBase() const override {
        return amount; 
    }

    void displayCurrency() const override {
        cout << "$" << amount << " (USD)\n";
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

    double convertToBase() const override {
        return amount * 1.1;
    }

    void displayCurrency() const override {
        cout << "€" << amount << " (EUR)\n";
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.013) {}

    double convertToBase() const override {
        return amount * 0.013;
    }

    void displayCurrency() const override {
        cout << "₹" << amount << " (INR)\n";
    }
};

int main() {
    Dollar usd(100);
    Euro eur(100);
    Rupee inr(100);

    cout << "Initial Currency Values:\n";
    usd.displayCurrency();
    eur.displayCurrency();
    inr.displayCurrency();

    cout << "\nConversions:\n";
    cout << "100 USD to EUR: " << usd.convertTo(eur) << " EUR\n";
    cout << "100 EUR to INR: " << eur.convertTo(inr) << " INR\n";
    cout << "100 INR to USD: " << inr.convertTo(usd) << " USD\n";

    return 0;
}
