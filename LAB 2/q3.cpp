#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size1 = 5;
    vector<int> vec;
    vec.reserve(size1);

    int value;
    cout << "Enter integers (negative number to stop):"<<endl;
    while (true)
     {
        cin >> value;
        if (value < 0)
        {
         break;
        }

        if (vec.size() == size1) 
        {
            size1 *= 2;
            vec.reserve(size1);
            cout << "Vector capacity increased to " << size1 <<endl;
        }

        vec.push_back(value);
    }

    cout << "Final vector size adjusted to " << vec.size()<<endl;

    cout << "Stored elements: ";
 for (int i = 0; i < vec.size(); i++) 
 {
    cout << vec[i] <<endl;
}
 return 0;
}
