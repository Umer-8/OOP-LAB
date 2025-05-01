

#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

class DimensionMismatchException : public runtime_error {
public:
    DimensionMismatchException(const string& msg) : runtime_error(msg) {}
};

class OutOfBoundsException : public runtime_error {
public:
    OutOfBoundsException(const string& msg) : runtime_error(msg) {}
};

template <typename T>
class Matrix {
private:
    vector<vector<T>> data;
    size_t rows;
    size_t cols;

    void validateDimensions(const Matrix& other, const string& op) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException(
                "Matrix " + op + " requires matching dimensions. " +
                to_string(rows) + "x" + to_string(cols) + " vs " +
                to_string(other.rows) + "x" + to_string(other.cols));
        }
    }

    void validateMultiplicationDimensions(const Matrix& other) const {
        if (cols != other.rows) {
            throw DimensionMismatchException(
                "Matrix multiplication requires cols of first matrix to match rows of second. " +
                to_string(cols) + " != " + to_string(other.rows));
        }
    }

public:
    Matrix(size_t rows, size_t cols, const T& initVal = T()) 
        : rows(rows), cols(cols), data(rows, vector<T>(cols, initVal)) {}

    T& at(size_t row, size_t col) {
        if (row >= rows || col >= cols) {
            throw OutOfBoundsException(
                "Index [" + to_string(row) + "," + to_string(col) + 
                "] out of bounds for matrix size " + 
                to_string(rows) + "x" + to_string(cols));
        }
        return data[row][col];
    }

    const T& at(size_t row, size_t col) const {
        if (row >= rows || col >= cols) {
            throw OutOfBoundsException(
                "Index [" + to_string(row) + "," + to_string(col) + 
                "] out of bounds for matrix size " + 
                to_string(rows) + "x" + to_string(cols));
        }
        return data[row][col];
    }

    Matrix operator+(const Matrix& other) const {
        validateDimensions(other, "addition");
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        validateMultiplicationDimensions(other);
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    void print(const string& name = "") const {
        if (!name.empty()) {
            cout << name << " (" << rows << "x" << cols << "):\n";
        }
        for (const auto& row : data) {
            for (const auto& elem : row) {
                cout << elem << "\t";
            }
            cout << "\n";
        }
        cout << endl;
    }
};

int main() {
    try {
        Matrix<int> m1(2, 3, 1);
        Matrix<int> m2(2, 3, 2);
        Matrix<int> m3(3, 2, 3);

        m1.at(1, 2) = 5;
        m2.at(0, 0) = 10;

        m1.print("Matrix 1");
        m2.print("Matrix 2");
        m3.print("Matrix 3");

        auto sum = m1 + m2;
        sum.print("Sum of m1 and m2");

        auto product = m1 * m3;
        product.print("Product of m1 and m3");

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}