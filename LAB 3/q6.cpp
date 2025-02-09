#include <iostream>
#include<string>
using namespace std;

class Matrix {
public:
    int rows;
    int columns;
    int rows2;
    int columns2;

    int elements[2][2];
    int elements2[2][2];

    int getrows() { return rows; }
    int getcolumns() { return columns; }
    int getrows2() { return rows2; }
    int getcolumns2() { return columns2; }

    void setelements(int values[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                elements[i][j] = values[i][j];
            }
        }
    }

    void setelements2(int values[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                elements2[i][j] = values[i][j];
            }
        }
    }

    void addmatrix(int result[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = elements[i][j] + elements2[i][j];
            }
        }
    }

    void multiplymatrix(int result[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result[i][j] += elements[i][k] * elements2[k][j];
                }
            }
        }
    }

    Matrix() {
        rows = 2;
        columns = 2;
        rows2 = 2;
        columns2 = 2;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 9) {
        return 1;
    }

    Matrix mat;
    int values1[2][2] = {
        {stoi(argv[1]), stoi(argv[2])},
        {stoi(argv[3]), stoi(argv[4])}
    };

    int values2[2][2] = {
        {stoi(argv[5]), stoi(argv[6])},
        {stoi(argv[7]), stoi(argv[8])}
    };

    mat.setelements(values1);
    mat.setelements2(values2);

    int add_result[2][2];
    mat.addmatrix(add_result);

    cout << "Addition Result:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << add_result[i][j] << " ";
        }
        cout << endl;
    }

    int mul_result[2][2];
    mat.multiplymatrix(mul_result);

    cout << "Multiplication Result:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << mul_result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
