#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int empId;
    float salary;

public:
    virtual void getdata() {
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee ID: ";
        cin >> empId;
        cout << "Enter base salary: $";
        cin >> salary;
    }

    virtual void displaydata() const {
        cout << "\nName: " << name
             << "\nID: " << empId
             << "\nBase Salary: $" << salary
             << "\nBonus: $" << calculateBonus()
             << "\nTotal Salary: $" << calculateTotalSalary() << endl;
    }

    virtual float calculateBonus() const = 0;

    float calculateTotalSalary() const {
        return salary + calculateBonus();
    }

};

class Admin : virtual public Person {
protected:
    float adminBonusRate;

public:
    void getdata() override {
        Person::getdata();
        cout << "Enter admin bonus rate (%): ";
        cin >> adminBonusRate;
    }

    float calculateBonus() const override {
        return salary * (adminBonusRate / 100);
    }
};

class Account : virtual public Person {
protected:
    float accountBonusRate;

public:
    void getdata() override {
        Person::getdata();
        cout << "Enter account bonus rate (%): ";
        cin >> accountBonusRate;
    }

    float calculateBonus() const override {
        return salary * (accountBonusRate / 100);
    }
};

class Master : public Admin, public Account {
public:
    void getdata() override {
        Person::getdata();
        cout << "Enter admin bonus rate (%): ";
        cin >> Admin::adminBonusRate;
        cout << "Enter account bonus rate (%): ";
        cin >> Account::accountBonusRate;
    }

    float calculateBonus() const override {
        return (salary * (Admin::adminBonusRate / 100)) 
               + (salary * (Account::accountBonusRate / 100));
    }
};

int main() {
    Person* employees[3];
    Admin adminEmp;
    Account accountEmp;
    Master masterEmp;

    employees[0] = &adminEmp;
    employees[1] = &accountEmp;
    employees[2] = &masterEmp;

    
    employees[0]->getdata();
    employees[1]->getdata();
    employees[2]->getdata();

    employees[0]->displaydata();
    employees[1]->displaydata();
    employees[2]->displaydata();

    return 0;
}