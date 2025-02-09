#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string firstname;
    string lastname;
    double salary;

    void testsalary() {
        if (salary < 0) {
            salary = 0.0;
        }
    }

    double display_yearly_salary() {
        salary = salary * 12;
        return salary;
    }

    double display_raised_salary() {
        salary = salary * 1.1;
        return salary;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 7) {
        return 1;
    }

    Employee e1, e2;

    e1.firstname = argv[1];
    e1.lastname = argv[2];
    e1.salary = stod(argv[3]);
    e1.testsalary();

    e2.firstname = argv[4];
    e2.lastname = argv[5];
    e2.salary = stod(argv[6]);
    e2.testsalary();

    cout << "Yearly salary of " << e1.firstname << " " << e1.lastname << ": " << e1.display_yearly_salary() << endl;
    cout << "Yearly salary of " << e2.firstname << " " << e2.lastname << ": " << e2.display_yearly_salary() << endl;

    cout << "Salary after raise of " << e1.firstname << " " << e1.lastname << ": " << e1.display_raised_salary() << endl;
    cout << "Salary after raise of " << e2.firstname << " " << e2.lastname << ": " << e2.display_raised_salary() << endl;

    return 0;
}
