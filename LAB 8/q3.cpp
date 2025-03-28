#include <iostream>
#include <string>
using namespace std;

class Bonus {
private:
    double amount;
public:
    Bonus(double amt = 0.0) : amount(amt) {}
    
    friend ostream& operator<<(ostream& os, const Bonus& b) {
        os << "$" << b.amount;
        return os;
    }
};

class Person {
protected:
    int employeeID;
public:
    Person(int id = 0) : employeeID(id) {}
    void getData(int id) {
        employeeID = id;
    }
    void displayData() const {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person {
private:
    string name;
    double monthlyIncome;
public:
    void getData(int id, const string& empName , double income ) {
        Person::getData(id);
        name = empName;
        monthlyIncome = income;
    }
    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
    }
    Bonus calculateBonus() const {
        return Bonus(monthlyIncome * 12 * 0.05);
    }
};

class Accounts : public Person {
private:
    string name;
    double monthlyIncome;
public:
    void getData(int id, const string& empName , double income ) {
        Person::getData(id);
        name = empName;
        monthlyIncome = income;
    }
    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
    }
    Bonus calculateBonus() const {
        return Bonus(monthlyIncome * 12 * 0.05);
    }
};

int main() {
    int numEmployees = 2;
    
    Admin admins[numEmployees];
    Accounts accounts[numEmployees];

    admins[0].getData(101, "John Doe", 5000.0);
    admins[1].getData(102, "Alice Johnson", 5500.0);
    accounts[0].getData(201, "Jane Smith", 4500.0);
    accounts[1].getData(202, "Bob Williams", 4800.0);

    cout << "Admin Department:\n";
    for (int i = 0; i < numEmployees; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        admins[i].displayData();
        cout << "Annual Bonus: " << admins[i].calculateBonus() << endl;
    }

    cout << "\nAccounts Department:\n";
    for (int i = 0; i < numEmployees; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        accounts[i].displayData();
        cout << "Annual Bonus: " << accounts[i].calculateBonus() << endl;
    }

    return 0;
}