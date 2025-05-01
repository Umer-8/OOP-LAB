#include <iostream>
using namespace std;

template <typename T>
class Base {
protected:
    T val1;
    T val2;
public:
    Base(T a, T b) : val1(a), val2(b) {}
    virtual void multiply() = 0;
    virtual ~Base() {}
};

template <typename T>
class Derived : public Base<T> {
private:
    T val3;
    T val4;
public:
    Derived(T a, T b, T c, T d) : Base<T>(a, b), val3(c), val4(d) {}
    
    void multiply() override {
        T baseProduct = this->val1 * this->val2;
        T derivedProduct = val3 * val4;
        
        cout << "Base product (" << this->val1 << " * " << this->val2 << "): " << baseProduct << endl;
        cout << "Derived product (" << val3 << " * " << val4 << "): " << derivedProduct << endl;
        cout << "Total product: " << baseProduct * derivedProduct << endl;
    }
};

int main() {
    Derived<int> intCalc(2, 3, 4, 5);
    cout << "Integer calculations:" << endl;
    intCalc.multiply();
    cout << endl;
    
    Derived<double> doubleCalc(1.5, 2.5, 3.5, 4.5);
    cout << "Double calculations:" << endl;
    doubleCalc.multiply();
    
    return 0;
}