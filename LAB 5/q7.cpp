#include <iostream>
using namespace std;

class Student {
private:
    const int roll_no;

    int getRollNo() {
        int roll;
        cout << "Enter Roll No: ";
        cin >> roll;
        return roll;
    }

public:
    Student() : roll_no(getRollNo()) {}

    void display() const {
        cout << "Roll No: " << roll_no << endl;
    }
};

int main() {
    Student student;
    student.display();
    return 0;
}