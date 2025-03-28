#include <iostream>
#include <vector>
using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative = false;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

    void normalize() {
        for (size_t i = 0; i < digits.size(); ++i) {
            if (digits[i] >= 10) {
                if (i == digits.size() - 1) {
                    digits.push_back(0);
                }
                digits[i+1] += digits[i] / 10;
                digits[i] %= 10;
            } else if (digits[i] < 0) {
                if (i == digits.size() - 1) {
                    isNegative = !isNegative;
                    digits[i] = -digits[i];
                } else {
                    int borrow = (-digits[i] + 9) / 10;
                    digits[i+1] -= borrow;
                    digits[i] += borrow * 10;
                }
            }
        }
        removeLeadingZeros();
    }

    static BigInteger addAbsolute(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        size_t maxSize = a.digits.size() > b.digits.size() ? a.digits.size() : b.digits.size();
        result.digits.resize(maxSize, 0);

        for (size_t i = 0; i < maxSize; ++i) {
            if (i < a.digits.size()) result.digits[i] += a.digits[i];
            if (i < b.digits.size()) result.digits[i] += b.digits[i];
        }
        result.normalize();
        return result;
    }

    static BigInteger subtractAbsolute(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        result.digits = a.digits;
        size_t newSize = a.digits.size() > b.digits.size() ? a.digits.size() : b.digits.size();
        result.digits.resize(newSize, 0);

        for (size_t i = 0; i < b.digits.size(); ++i) {
            result.digits[i] -= b.digits[i];
        }
        result.normalize();
        return result;
    }

    static bool lessThanAbsolute(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size()) {
            return a.digits.size() < b.digits.size();
        }
        for (int i = a.digits.size() - 1; i >= 0; --i) {
            if (a.digits[i] != b.digits[i]) {
                return a.digits[i] < b.digits[i];
            }
        }
        return false;
    }

public:
    BigInteger() : digits{0}, isNegative(false) {}

    BigInteger(long long num) {
        if (num < 0) {
            isNegative = true;
            num = -num;
        }
        if (num == 0) {
            digits.push_back(0);
        }
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    BigInteger operator-() const {
        BigInteger result = *this;
        if (result.digits.size() != 1 || result.digits[0] != 0) {
            result.isNegative = !result.isNegative;
        }
        return result;
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result = addAbsolute(*this, other);
            result.isNegative = isNegative;
            return result;
        } else {
            if (lessThanAbsolute(*this, other)) {
                BigInteger result = subtractAbsolute(other, *this);
                result.isNegative = other.isNegative;
                return result;
            } else {
                BigInteger result = subtractAbsolute(*this, other);
                result.isNegative = isNegative;
                return result;
            }
        }
    }

    BigInteger operator-(const BigInteger& other) const {
        return *this + (-other);
    }

    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.digits.resize(digits.size() + other.digits.size(), 0);

        for (size_t i = 0; i < digits.size(); ++i) {
            for (size_t j = 0; j < other.digits.size(); ++j) {
                result.digits[i+j] += digits[i] * other.digits[j];
            }
        }
        result.isNegative = isNegative != other.isNegative;
        result.normalize();
        return result;
    }

    bool operator==(const BigInteger& other) const {
        if (digits.size() != other.digits.size() || isNegative != other.isNegative) {
            return false;
        }
        for (size_t i = 0; i < digits.size(); ++i) {
            if (digits[i] != other.digits[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        if (isNegative) {
            return lessThanAbsolute(other, *this);
        }
        return lessThanAbsolute(*this, other);
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(other < *this);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const BigInteger& num) {
        if (num.isNegative) {
            os << '-';
        }
        for (int i = num.digits.size() - 1; i >= 0; --i) {
            os << num.digits[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& num) {
        num = BigInteger();
        num.digits.clear();
        num.isNegative = false;
        
        char ch;
        while (is.get(ch)) {
            if (ch == '-' && num.digits.empty()) {
                num.isNegative = true;
            } else if (ch >= '0' && ch <= '9') {
                num.digits.insert(num.digits.begin(), ch - '0');
            } else {
                is.putback(ch);
                break;
            }
        }
        
        if (num.digits.empty()) {
            num.digits.push_back(0);
        } else {
         
            size_t i = 0, j = num.digits.size() - 1;
            while (i < j) {
                int temp = num.digits[i];
                num.digits[i] = num.digits[j];
                num.digits[j] = temp;
                i++;
                j--;
            }
        }
        num.removeLeadingZeros();
        return is;
    }
};

int main() {
    BigInteger a(1234567890);
    BigInteger b(-987654321);
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    
    BigInteger c;
    cout << "Enter a big integer: ";
    cin >> c;
    cout << "You entered: " << c << endl;
    
    return 0;
}