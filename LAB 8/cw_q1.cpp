
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        if (denominator == 0) 
      cout<<"Denominator cannot be zero";
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        reduce();
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, 
                       denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                       denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) throw invalid_argument("Cannot divide by zero");
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator;
        if (f.denominator != 1) os << '/' << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        int num, denom = 1;
        char slash;
        is >> num;
        if (is.peek() == '/') {
            is >> slash >> denom;
        }
        f = Fraction(num, denom);
        return is;
    }
};

int main() {
    Fraction a(3, 4);
    Fraction b(2, 5);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    cout << boolalpha;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a >= b: " << (a >= b) << endl;

    cout << "Enter a fraction (numerator or numerator/denominator): ";
    Fraction c;
    cin >> c;
    cout << "You entered: " << c << endl;

    return 0;
}
