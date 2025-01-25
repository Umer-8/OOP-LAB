#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
    float weight_kg, weight_pounds;
    
    cout << "Enter weight in kilograms: ";
    cin >> weight_kg;

    weight_pounds = weight_kg * 2.2;

    cout << fixed << setprecision(2); 
    cout << "Weight in kilograms is: " << weight_kg << endl;
    cout << "Weight in pounds is: " << weight_pounds << endl;

    return 0;
}
