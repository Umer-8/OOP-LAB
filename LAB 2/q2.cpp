#include <iostream>
using namespace std;

void* addToEachElement(void* arr, int size, int valueToAdd) {
    for (int i = 0; i < size; i++) {
        ((int*)arr)[i] += valueToAdd;
    }
    return arr;
}

int main() {
    int numElements, incrementValue;

    cout << "Enter the number of elements: ";
    cin >> numElements;

    int* arr = new int[numElements];

    cout << "Enter the value to add to each element: ";
    cin >> incrementValue;

    for (int i = 0; i < numElements; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int* updatedArray = (int*)addToEachElement(arr, numElements, incrementValue);

    cout << "The updated array is:\n";
    for (int i = 0; i < numElements; i++) {
        cout << updatedArray[i] << "\n";
    }

    delete[] arr;

    return 0;
}
