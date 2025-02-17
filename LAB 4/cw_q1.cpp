#include <iostream>
using namespace std;

class matrix {
private:
    int rows;
    int columns;
    int** value;

public:
    matrix(int rows, int columns) : rows(rows), columns(columns) {
        value = new int*[rows];
        for (int i = 0; i < rows; i++) {
            value[i] = new int[columns]();
        }
    }

    matrix(const matrix& other) : rows(other.rows), columns(other.columns) {
        value = new int*[rows];
        for (int i = 0; i < rows; i++) {
            value[i] = new int[columns];
            for (int j = 0; j < columns; j++) {
                value[i][j] = other.value[i][j];
            }
        }
    }

    matrix(matrix&& other) noexcept : rows(other.rows), columns(other.columns), value(other.value) {
        other.value = nullptr;
        other.rows = 0;
        other.columns = 0;
    }

    ~matrix() {
        if (value) {
            for (int i = 0; i < rows; i++) {
                delete[] value[i];
            }
            delete[] value;
        }
    }

    int& at(int r, int c) {
        return value[r][c];
    }

    const int& at(int r, int c) const {
        return value[r][c];
    }

    void fill(int fillValue) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                value[i][j] = fillValue;
            }
        }
    }

    matrix transpose() const {
        matrix transposed(columns, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                transposed.value[j][i] = value[i][j];
            }
        }
        return transposed;
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << value[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int x, y;
    cout << "Enter the number of rows: ";
    cin >> x;
    cout << "Enter the number of columns: ";
    cin >> y;

    matrix obj1(x, y);

    obj1.fill(4);
    cout << "Original matrix:" << endl;
    obj1.print();

    matrix obj2 = obj1;
    cout << "Copied matrix:" << endl;
    obj2.print();

    matrix obj3 = move(obj2);
    cout << "Moved matrix:" << endl;
    obj3.print();

    matrix transposed = obj1.transpose();
    cout << "Transposed matrix:" << endl;
    transposed.print();

    return 0;
}