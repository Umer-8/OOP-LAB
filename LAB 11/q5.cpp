#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class StackUnderflowException : public runtime_error {
public:
    StackUnderflowException() : runtime_error("Stack is empty") {}
};

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    void push(const T& item) {
        elements.push_back(item);
    }

    void pop() {
        if (empty()) throw StackUnderflowException();
        elements.pop_back();
    }

    const T& top() const {
        if (empty()) throw StackUnderflowException();
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    try {
        Stack<int> intStack;
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);

        cout << "Top element: " << intStack.top() << endl;
        intStack.pop();
        cout << "Top after pop: " << intStack.top() << endl;

        intStack.pop();
        intStack.pop();
        intStack.pop();
    }
    catch (const StackUnderflowException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        Stack<string> stringStack;
        stringStack.push("Hello");
        stringStack.push("World");

        cout << "\nTop string: " << stringStack.top() << endl;
        stringStack.pop();
        cout << "Top after pop: " << stringStack.top() << endl;

        cout << "Trying to get top of empty stack: ";
        stringStack.pop();
        cout << stringStack.top() << endl;
    }
    catch (const StackUnderflowException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}