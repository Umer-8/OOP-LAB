#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double bal) : accountNumber(accNum), balance(bal) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " into account " << accountNumber << ". New balance: " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNumber << ". New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in account " << accountNumber << endl;
        }
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }

    virtual ~BankAccount() = default;
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accNum, double bal) : BankAccount(accNum, bal) {}

    void applyInterest() {
        double interest = balance * 0.02;
        balance += interest;
        cout << "Interest applied to account " << accountNumber << ". New balance: " << balance << endl;
    }

    void display() const override {
        cout << "Savings Account - ";
        BankAccount::display();
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum, double bal, double odLimit) : BankAccount(accNum, bal), overdraftLimit(odLimit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNumber << ". New balance: " << balance << endl;
            if (balance < 0) {
                cout << "ALERT: Overdraft limit reached for account " << accountNumber << endl;
            }
        } else {
            cout << "Overdraft limit exceeded for account " << accountNumber << endl;
        }
    }

    void setOverdraftLimit(double newLimit) {
        overdraftLimit = newLimit;
    }

    void display() const override {
        cout << "Checking Account - ";
        BankAccount::display();
    }
};

class BusinessAccount : public BankAccount {
public:
    BusinessAccount(string accNum, double bal) : BankAccount(accNum, bal) {}

    void deposit(double amount) override {
        double tax = amount * 0.05;
        BankAccount::deposit(amount - tax);
        cout << "Corporate tax of " << tax << " withheld from deposit." << endl;
    }

    void display() const override {
        cout << "Business Account - ";
        BankAccount::display();
    }
};

class UserRole {
public:
    virtual void performDuties() const = 0;
    virtual ~UserRole() = default;
};

class Customer : public UserRole {
public:
    void performDuties() const override {
        cout << "Customer is performing duties: depositing and withdrawing from accounts." << endl;
    }
};

class Teller : public UserRole {
public:
    void performDuties() const override {
        cout << "Teller is performing duties: depositing, withdrawing, and freezing accounts." << endl;
    }

    void freezeAccount(const BankAccount& account) const {
        cout << "Account " << account.getAccountNumber() << " has been frozen by the teller." << endl;
    }
};

class Manager : public UserRole {
public:
    void performDuties() const override {
        cout << "Manager is performing duties: adjusting limits, overriding transactions, and managing accounts." << endl;
    }

    void adjustLimit(CheckingAccount& account, double newLimit) const {
        account.setOverdraftLimit(newLimit);
        cout << "Overdraft limit for account " << account.getAccountNumber() << " adjusted to " << newLimit << " by the manager." << endl;
    }
};

int main() {
    SavingsAccount savings("SA123", 1000);
    CheckingAccount checking("CA456", 500, 200);
    BusinessAccount business("BA789", 2000);

    Customer customer;
    Teller teller;
    Manager manager;

    vector<BankAccount*> accounts = {&savings, &checking, &business};
    for (auto account : accounts) {
        account->deposit(200);
        account->withdraw(100);
        account->display();
    }

    vector<UserRole*> roles = {&customer, &teller, &manager};
    for (UserRole* role : roles) {
        role->performDuties();
    }

    teller.freezeAccount(savings);
    manager.adjustLimit(checking, 500);

    return 0;
}