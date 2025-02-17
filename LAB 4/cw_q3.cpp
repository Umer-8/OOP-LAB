#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    size_t size;

public:
    DynamicArray() : data(nullptr), size(0) {
        cout << "Default constructor called! Size: " << size << endl;
    }

    DynamicArray(size_t n) : size(n) {
        data = new int[size]();
        cout << "Parameterized constructor called! Size: " << size << endl;
    }

    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        cout << "Copy constructor called! Size: " << size << endl;
    }

    DynamicArray(DynamicArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        cout << "Move constructor called! Size: " << size << endl;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        cout << "Copy assignment operator called! Size: " << size << endl;
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        cout << "Move assignment operator called! Size: " << size << endl;
        return *this;
    }

    ~DynamicArray() {
        delete[] data;
        cout << "Destructor called! Size: " << size << endl;
    }

    size_t getSize() const {
        return size;
    }

    int& at(size_t index) {
        if (index >= size) {
            cerr << "Error: Index out of range!" << endl;
            exit(1);
        }
        return data[index];
    }

    const int& at(size_t index) const {
        if (index >= size) {
            cerr << "Error: Index out of range!" << endl;
            exit(1);
        }
        return data[index];
    }

    void resize(size_t newSize) {
        if (newSize == size) {
            return;
        }

        int* newData = new int[newSize]();
        size_t elementsToCopy = (newSize < size) ? newSize : size;
        for (size_t i = 0; i < elementsToCopy; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        size = newSize;

        cout << "Resized array to size: " << size << endl;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr1;
    cout << "arr1 size: " << arr1.getSize() << endl;

    DynamicArray arr2(5);
    cout << "arr2 size: " << arr2.getSize() << endl;
    arr2.print();

    DynamicArray arr3 = arr2;
    cout << "arr3 size: " << arr3.getSize() << endl;
    arr3.print();

    DynamicArray arr4;
    arr4 = arr3;
    cout << "arr4 size: " << arr4.getSize() << endl;
    arr4.print();

    DynamicArray arr5 = std::move(arr4);
    cout << "arr5 size: " << arr5.getSize() << endl;
    arr5.print();
    cout << "arr4 size after move: " << arr4.getSize() << endl;

    DynamicArray arr6;
    arr6 = std::move(arr5);
    cout << "arr6 size: " << arr6.getSize() << endl;
    arr6.print();
    cout << "arr5 size after move: " << arr5.getSize() << endl;

    arr6.resize(10);
    arr6.print();

    arr6.at(0) = 100;
    cout << "arr6[0]: " << arr6.at(0) << endl;

    return 0;
}