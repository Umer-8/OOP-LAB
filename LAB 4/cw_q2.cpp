#include <iostream>
using namespace std;

class Polynomial {
private:
    int degree;
    double* coefficients;

    void allocateMemory(int deg) {
        degree = deg;
        coefficients = new double[degree + 1]();
    }

    void deallocateMemory() {
        if (coefficients) {
            delete[] coefficients;
            coefficients = nullptr;
        }
    }

public:
    Polynomial() {
        allocateMemory(0);
        cout << "Default constructor called! Degree: " << degree << endl;
    }

    Polynomial(int deg, const double coeffs[]) {
        if (deg < 0) {
            cerr << "Error: Degree cannot be negative. Creating a default polynomial." << endl;
            degree = 0;
            coefficients = new double[1](); // Default to constant zero polynomial
            return;
        }
        allocateMemory(deg);
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = coeffs[i];
        }
        cout << "Parameterized constructor called! Degree: " << degree << endl;
    }

    Polynomial(const Polynomial& other) {
        allocateMemory(other.degree);
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
        cout << "Copy constructor called! Degree: " << degree << endl;
    }

    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients) {
        other.coefficients = nullptr;
        other.degree = 0;
        cout << "Move constructor called! Degree: " << degree << endl;
    }

    ~Polynomial() {
        deallocateMemory();
        cout << "Destructor called! Degree: " << degree << endl;
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            deallocateMemory();
            allocateMemory(other.degree);
            for (int i = 0; i <= degree; ++i) {
                coefficients[i] = other.coefficients[i];
            }
        }
        cout << "Copy assignment operator called! Degree: " << degree << endl;
        return *this;
    }

    Polynomial& operator=(Polynomial&& other) noexcept {
        if (this != &other) {
            deallocateMemory();
            degree = other.degree;
            coefficients = other.coefficients;
            other.coefficients = nullptr;
            other.degree = 0;
        }
        cout << "Move assignment operator called! Degree: " << degree << endl;
        return *this;
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0.0;
        double power = 1.0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * power;
            power *= x;
        }
        return result;
    }

    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        double* newCoeffs = new double[maxDegree + 1]();

        for (int i = 0; i <= degree; ++i) {
            newCoeffs[i] += coefficients[i];
        }
        for (int i = 0; i <= other.degree; ++i) {
            newCoeffs[i] += other.coefficients[i];
        }

        Polynomial result(maxDegree, newCoeffs);
        delete[] newCoeffs;
        return result;
    }

    Polynomial multiply(const Polynomial& other) const {
        int resultDegree = degree + other.degree;
        double* newCoeffs = new double[resultDegree + 1]();

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                newCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        Polynomial result(resultDegree, newCoeffs);
        delete[] newCoeffs;
        return result;
    }

    void print() const {
        if (!coefficients) {
            cout << "Moved-from object (no data)." << endl;
            return;
        }
        for (int i = 0; i <= degree; ++i) {
            cout << coefficients[i];
            if (i > 0) {
                cout << "x^" << i;
            }
            if (i < degree) {
                cout << " + ";
            }
        }
        cout << endl;
    }
};

int main() {
    Polynomial p1;
    cout << "p1: ";
    p1.print();

    double coeffs1[] = {1.0, 2.0, 3.0};
    Polynomial p2(2, coeffs1);
    cout << "p2: ";
    p2.print();

    Polynomial p3 = p2;
    cout << "p3: ";
    p3.print();

    Polynomial p4;
    p4 = p3;
    cout << "p4: ";
    p4.print();

    Polynomial p5 = move(p4);
    cout << "p5: ";
    p5.print();
    cout << "p4 after move: ";
    p4.print();

    Polynomial p6;
    p6 = move(p5);
    cout << "p6: ";
    p6.print();
    cout << "p5 after move: ";
    p5.print();

    double x = 2.0;
    cout << "p6 evaluated at x = " << x << ": " << p6.evaluate(x) << endl;

    double coeffs2[] = {4.0, 5.0};
    Polynomial p7(1, coeffs2);
    Polynomial sum = p6.add(p7);
    cout << "Sum of p6 and p7: ";
    sum.print();

    Polynomial product = p6.multiply(p7);
    cout << "Product of p6 and p7: ";
    product.print();

    return 0;
}
