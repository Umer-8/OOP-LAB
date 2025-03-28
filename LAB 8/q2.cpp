#include <iostream>
using namespace std;

class Shape {
private:
    int area;

public:
    Shape(int a ) : area(a) {}

    Shape operator+(const Shape& other) {
        return Shape(area + other.area);
    }

    void display() const {
        cout << "Area is: " << area << endl;
    }
};

int main() {
    Shape s1(10), s2(20), s3(0);
    s3 = s1 + s2;
    s3.display();
    return 0;
}