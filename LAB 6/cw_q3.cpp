#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IOrderTaker {
public:
    virtual void takeOrder() const = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder() const = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill() const = 0;
    virtual ~IBiller() {}
};

class Employee {
protected:
    int id;
    string name;

public:
    Employee(string name, int id) : name(name), id(id) {}
    virtual ~Employee() {}

    void displayInfo() const {
        cout << "Employee: " << name << " (ID: " << id << ")" << endl;
    }

    virtual void performDuties() const {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(string name, int id) : Employee(name, id) {}

    void takeOrder() const override {
        cout << "Waiter " << name << " (ID: " << id << ") is taking the order." << endl;
    }

    void performDuties() const override {
        takeOrder();
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(string name, int id) : Employee(name, id) {}

    void prepareOrder() const override {
        cout << "Chef " << name << " (ID: " << id << ") is preparing the order." << endl;
    }

    void performDuties() const override {
        prepareOrder();
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(string name, int id) : Employee(name, id) {}

    void generateBill() const override {
        cout << "Cashier " << name << " (ID: " << id << ") is generating the bill." << endl;
    }

    void performDuties() const override {
        generateBill();
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(string name, int id) : Employee(name, id) {}

    void takeOrder() const override {
        cout << "Manager " << name << " (ID: " << id << ") is taking the order." << endl;
    }

    void generateBill() const override {
        cout << "Manager " << name << " (ID: " << id << ") is generating the bill." << endl;
    }

    void performDuties() const override {
        takeOrder();
        generateBill();
    }
};

class Menu {
protected:
    int cost;

public:
    Menu(int cost) : cost(cost) {}
    virtual int calculatecosts() const = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
public:
    FoodMenu(int cost) : Menu(cost) {}

    int calculatecosts() const override {
        return cost * 1.2;
    }
};

class BeverageMenu : public Menu {
public:
    BeverageMenu(int cost) : Menu(cost) {}

    int calculatecosts() const override {
        return cost * 1.1;
    }
};

int main() {
    Waiter waiter("John", 1);
    Chef chef("Kevin", 2);
    Cashier cashier("Paul", 3);
    Manager manager("Bob", 4);

    vector<Employee*> employees = {&waiter, &chef, &cashier, &manager};

    for (auto employee : employees) {
        employee->displayInfo();
        employee->performDuties();
        cout << "---------------------" << endl;
    }

    FoodMenu foodMenu(100);
    BeverageMenu beverageMenu(50);

    cout << "Food Menu Cost: " << foodMenu.calculatecosts() << endl;
    cout << "Beverage Menu Cost: " << beverageMenu.calculatecosts() << endl;

    return 0;
}