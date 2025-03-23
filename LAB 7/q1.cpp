#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(string accNum, string accHolderName, double bal = 0)
        : accountNumber(accNum), accountHolderName(accHolderName), balance(bal) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculation not defined for this account." << endl;
    }

    void getAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string accNum, string accHolderName, double bal, double intRate, double minBal)
        : Account(accNum, accHolderName, bal), interestRate(intRate), minimumBalance(minBal) {}

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest calculated and added. New balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount >= minimumBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Withdrawal denied. Minimum balance requirement not met." << endl;
        }
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum, string accHolderName, double bal, double overdraft)
        : Account(accNum, accHolderName, bal), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (amount > 0 && (balance - amount) >= -overdraftLimit) {
            balance -= amount;
            cout << "Withdrew " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Withdrawal denied. Overdraft limit exceeded." << endl;
        }
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    int daysToMaturity;

public:
    FixedDepositAccount(string accNum, string accHolderName, double bal, double fixedIntRate, int days)
        : Account(accNum, accHolderName, bal), fixedInterestRate(fixedIntRate), daysToMaturity(days) {}

    void calculateInterest() override {
        double interest = balance * fixedInterestRate / 100;
        balance += interest;
        cout << "Fixed interest calculated and added. New balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (daysToMaturity <= 0) {
            Account::withdraw(amount);
        } else {
            cout << "Withdrawal denied. Account is still under fixed deposit period." << endl;
        }
    }


};

int main() {
    Account* account;

    account = new SavingsAccount("12345", "John Doe", 1000, 2.5, 500);
    account->deposit(500);
    account->withdraw(200);
    account->calculateInterest();
    account->getAccountInfo();
    delete account;

    account = new CheckingAccount("54321", "Alice Smith", 2000, 1000);
    account->deposit(300);
    account->withdraw(2500);
    account->withdraw(1000);
    account->getAccountInfo();
    delete account;

    account = new FixedDepositAccount("67890", "Jane Doe", 5000, 5, 365);
    account->deposit(1000);
    account->withdraw(2000);
    account->calculateInterest();
    account->getAccountInfo();
    delete account;

    return 0;
}