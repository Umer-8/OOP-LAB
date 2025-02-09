#include <iostream>
using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    void displaydate() {
        cout << "Date is: " << day << "/" << month << "/" << year << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        return 1;
    }

    Date d;
    d.day = stoi(argv[1]);
    d.month = stoi(argv[2]);
    d.year = stoi(argv[3]);

    d.displaydate();
    return 0;
}
