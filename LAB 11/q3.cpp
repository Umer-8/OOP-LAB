#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class SafeArray {
    T* data;
    int size;
public:
    SafeArray(int n) : size(n), data(new T[n]) {}
    ~SafeArray() { delete[] data; }

    T& operator[](int i) {
        if (i < 0 || i >= size) throw out_of_range("Index out of bounds");
        return data[i];
    }
    
    int getSize() const { return size; }
};

int main() {
    SafeArray<int> arr(5);
    
    for (int i = 0; i < arr.getSize(); i++) {
        arr[i] = i * 10;
    }
    
    cout << "Array contents:\n";
  
    
    try {
        for (int i = 0; i < arr.getSize()+1; i++) {
            cout << arr[i] << "\n";
        }
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << "\n";
    }
    
    return 0;
}